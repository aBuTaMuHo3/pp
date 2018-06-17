#include "stdafx.h"
#include "BeeHive.h"


BeeHive::BeeHive()
{
}

size_t BeeHive::CountBeesInHive()
{
	return m_beesInHive;
}

void BeeHive::AddHoney()
{
	if (m_currentHoney < m_honeyCapacity)
		++m_currentHoney;
}


BeeHive::~BeeHive()
{
}
