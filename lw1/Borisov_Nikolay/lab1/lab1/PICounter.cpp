#include "stdafx.h"
#include "PICounter.h"
#include "ThreadController.h"
static double CIRCLE_RADIUS = 1;
static int MULTIPLIER = 4;
size_t PICounter::m_pointsInCircle = 0;

PICounter::PICounter(size_t iterationCount,  size_t threadCount)
	: m_iterationCount(iterationCount)
	,m_threadCount(threadCount)
{
	std::srand(time(0));
}

double PICounter::CalculatePi()
{
	if(m_iterationCount == 1)
	{
		SingleThreadCalculator();
	}
	else
	{
		MultiThreadCalculator();
	}
	return m_pi;
}

void PICounter::SingleThreadCalculator()
{
	CalculatePoint(&m_iterationCount);
	m_pi = m_pointsInCircle / m_iterationCount * MULTIPLIER;
}

void PICounter::MultiThreadCalculator()
{
	ThreadController threadController;
	std::vector<size_t> iterationThreadCount;
	size_t iterationPerThread = m_iterationCount / m_threadCount;
	size_t undistributedIterations = m_iterationCount % m_threadCount;

	for (size_t i = 0; i < m_threadCount; i++)
	{
		iterationThreadCount.emplace_back(iterationPerThread);
	}
	for (size_t i = 0; i < undistributedIterations; ++i)
	{
		++iterationThreadCount.at(i);
	}
	for (size_t i = 0; i < m_threadCount; ++i)
	{
		threadController.Add(&CalculatePoint, &iterationThreadCount[i]);
	}
	threadController.WaitAll();
	m_pi = m_pointsInCircle / m_iterationCount ;
}

DWORD PICounter::CalculatePoint(LPVOID data)
{
	double x;
	double y;
	size_t* iterationCount = static_cast<size_t*>(data);
	for (size_t i = 0; i < *iterationCount; ++i)
	{
		x = (float)rand() / RAND_MAX * CIRCLE_RADIUS;
		y = (float)rand() / RAND_MAX * CIRCLE_RADIUS;
		if (IsPointInCircle(x, y))
		{
			InterlockedIncrement(&m_pointsInCircle);
		}
	}
	return 0;
}

bool PICounter::IsPointInCircle(double x, double y)
{
	return x * x + y * y <= CIRCLE_RADIUS;
}



