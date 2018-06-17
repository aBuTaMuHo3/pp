
#include "stdafx.h"
#include "ThreadController.h"

ThreadController::ThreadController()
{
}

void ThreadController::Add(LPTHREAD_START_ROUTINE threadProc, LPVOID param)
{
	threads.push_back(CreateThread(NULL, 0, threadProc, param, 0, 0));
}

void ThreadController::WaitAll()
{
	WaitForMultipleObjects(threads.size(), threads.data(), true, INFINITE);
}

ThreadController::~ThreadController()
{
	for (auto &thread : threads)
	{
		CloseHandle(thread);
	}
}