#include "stdafx.h"
#include "PICounter.h"
static double CIRCLE_RADIUS = 1;
static int MULTIPLIER = 4;

PICounter::PICounter(size_t iterationCount)
	: m_iterationCount(iterationCount)
{
}

double PICounter::CalculatePi()
{
	SingleThreadCalculatior();
	return m_pi;
}

void PICounter::SingleThreadCalculatior()
{
	int pointsInCircle = 0;
	double x, y;
	for (double i = 0; i < m_iterationCount; ++i) {
		x = (double)rand() / (RAND_MAX * CIRCLE_RADIUS);
		y = (double)rand() / (RAND_MAX * CIRCLE_RADIUS);
		if (IsPointInCircle(x, y))
		{
			pointsInCircle++;
		}
	}
	m_pi = pointsInCircle / m_iterationCount * 4.0;
}

bool PICounter::IsPointInCircle(double x, double y)
{
	return x * x + y * y <= CIRCLE_RADIUS;
}



