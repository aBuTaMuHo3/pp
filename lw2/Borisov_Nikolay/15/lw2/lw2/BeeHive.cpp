#include "stdafx.h"
#include "Semaphore.h"
#include "BeeHive.h"
#include "Event.h"

BeeHive::BeeHive(size_t capacity, Event & halfFullEvent)
	:m_honeyCapacity(capacity),
	m_halfFullEvent(halfFullEvent)
{
	mutex = Semaphore(1, 1);
}

size_t BeeHive::CountBeesInHive()
{
	return m_beesInHive;
}

void BeeHive::AddHoney()
{
	if (m_currentHoney < m_honeyCapacity)
	{
		++m_currentHoney;
		if ((1.0*m_honeyCapacity / m_currentHoney) <= 2)
		{
			m_halfFullEvent.Start();
		}
	}

}

void BeeHive::BeeFliesIn()
{
	m_beesInHive++;
}

void BeeHive::BeeFliesOut()
{
	m_beesInHive--;
}

bool BeeHive::EmptyHive()
{
	if (m_beesInHive <= 2)
	{
		m_currentHoney = 0;
		return true;
	}
	else
	{
		return false;
	}
}


BeeHive::~BeeHive()
{
}
