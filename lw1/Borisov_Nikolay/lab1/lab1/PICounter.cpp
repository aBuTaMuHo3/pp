#include "stdafx.h"
#include "PICounter.h"


PICounter::PICounter(size_t iterationCount)
	: m_iterationCount(iterationCount)
{
}

double PICounter::CalculatePi()
{
	int c = 0;
	double x, y;
	for (double i = 0; i < m_iterationCount ; ++i) {
		x = (double)rand() / (RAND_MAX);
		y = (double)rand() / (RAND_MAX);
		if (x * x + y * y <= 1.0)
		{
			c++;
		}
	}
	return (double)c / m_iterationCount * 4.0;
}



