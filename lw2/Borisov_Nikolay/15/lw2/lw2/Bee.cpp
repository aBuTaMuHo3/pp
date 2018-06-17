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
}