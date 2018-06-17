#pragma once
class Bee
{
public:
	Bee(size_t id, BeeHive & m_hive, Semaphore & beeSemaphore);
	static DWORD WINAPI Loop(LPVOID data);
	~Bee();
private:
	size_t m_beeId;
	BeeHive & m_hive;
	Semaphore m_workingBees;
};

