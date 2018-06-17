#include "stdafx.h"
#include "Bear.h"
#include "BeeHive.h"
#include "Event.h"

Bear::Bear(BeeHive & hive, Event & wakeEvent)
	:m_hive(hive),
	m_wakeBear(wakeEvent)
{
}

void Bear::DoRaid()
{
	std::mt19937 generator{ std::random_device()() };
	std::uniform_int_distribution<int> random(1500, 2000);
	while (1)
	{
		m_wakeBear.Wait();
		std::printf("======================================\n->Медведь идет за медом \n======================================\n");
		Sleep(random(generator));
		m_hive.mutex.Wait();
		if (m_hive.EmptyHive())
		{
			std::printf("======================================\n<-Правильные пчелы дают правильный мед\n======================================\n");
			m_hive.mutex.Release(1);
			m_wakeBear.End();
		}
		else
		{
			std::printf("======================================\n<---Это какие-то неправильные пчелы\n======================================\n");
			m_hive.mutex.Release(1);
			Sleep(random(generator));
		}
	}
}



DWORD Bear::Loop(LPVOID data)
{
	Bear bear = *(Bear*)data;
	bear.DoRaid();
	return 0;
}

Bear::~Bear()
{
}
