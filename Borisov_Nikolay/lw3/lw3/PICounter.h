#pragma once
class PICounter
{
public:
	PICounter(size_t iterationCount);
	~PICounter() = default;
	double CalculatePi();
private:
	size_t m_iterationCount;
	double m_pi = 0;
	size_t m_pointsInCircle;
	void Calculator();
	bool IsPointInCircle(double x, double y);
};

