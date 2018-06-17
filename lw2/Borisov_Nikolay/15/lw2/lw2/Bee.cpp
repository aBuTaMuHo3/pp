#include "stdafx.h"
#include "Bee.h"
#include "Semaphore.h"
#include "BeeHive.h";

Bee::Bee(size_t id, BeeHive & hive, Semaphore & beeSemaphore)
	:m_beeId(id),
	m_hive(hive),
	m_workingBees(beeSemaphore)
{
}

Bee::~Bee()
{
}


DWORD Bee::Loop(LPVOID data)
{
	Bee bee = *(Bee*)data;
	bee.CollectHoney();
	return 0;
}

void Bee::CollectHoney()
{
	std::mt19937 generator{ std::random_device()() };
	std::uniform_int_distribution<int> random(500, 1000);

	while (1)
	{
		unsigned flightTime = random(generator);
		Sleep(random(generator));
		m_workingBees.Wait();
		std::printf("<-ѕчела %zu полетела по пчелиным делам.\n", m_beeId);
		m_hive.mutex.Wait();
		m_hive.BeeFliesOut();
		m_hive.mutex.Release(1);
		Sleep(random(generator));
		m_hive.mutex.Wait();
		m_hive.AddHoney();
		m_hive.BeeFliesIn();
		std::printf("->ѕчела %zu собрала мед и вернулась в улей.\n", m_beeId);
		m_hive.mutex.Release(1);
		m_workingBees.Release(1);
	}
}
