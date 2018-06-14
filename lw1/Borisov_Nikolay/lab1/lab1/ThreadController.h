#pragma once
class ThreadController
{
public:
	ThreadController();
	void Add(LPTHREAD_START_ROUTINE threadProc, LPVOID param);
	void WaitAll();
	~ThreadController();
private:
	std::vector<HANDLE> threads;
};

