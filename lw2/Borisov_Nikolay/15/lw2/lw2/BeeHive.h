#pragma once
#include "Event.h"
#include "Semaphore.h"
class BeeHive
{
public:
	BeeHive(size_t capacity, Event & halfFullEvent);
	size_t CountBeesInHive();
	void AddHoney();
	void BeeFliesIn();
	void BeeFliesOut();
	bool EmptyHive();
	Semaphore mutex;
	~BeeHive();
private:
	size_t m_honeyCapacity;
	size_t m_currentHoney;
	size_t m_beesInHive;
	Event m_halfFullEvent;
};

