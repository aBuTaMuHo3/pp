#pragma once
#include "BeeHive.h"
#include "Event.h"
class Bear
{
public:
	Bear(BeeHive & hive, Event & wakeEvent);
	void DoRaid();
	static DWORD WINAPI Loop(LPVOID data);
	~Bear();
private:
	BeeHive & m_hive;
	Event m_wakeBear;
};

