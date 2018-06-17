#include "stdafx.h"
#include "PICounter.h"
#include <random>
static double CIRCLE_RADIUS = 1;
static int MULTIPLIER = 4;


PICounter::PICounter(size_t iterationCount)
	: m_iterationCount(iterationCount),
	m_pointsInCircle(0)
{
	std::srand(time(0));
}

double PICounter::CalculatePi()
{
	Calculator();
	return m_pi;
}

void PICounter::Calculator()
{
	double x;
	double y;
	#pragma omp parallel for 
	for (size_t i = 0; i < m_iterationCount; ++i)
	{
		x = (float)rand() / RAND_MAX * CIRCLE_RADIUS;
		y = (float)rand() / RAND_MAX * CIRCLE_RADIUS;
		if (IsPointInCircle(x, y))
		{
			#pragma omp atomic
			m_pointsInCircle++;
		}
	}
	m_pi = 1.0*m_pointsInCircle / m_iterationCount * MULTIPLIER;
}

bool PICounter::IsPointInCircle(double x, double y)
{
	return x * x + y * y <= CIRCLE_RADIUS;
}



