#pragma once
class PICounter
{
public:
	PICounter(size_t iterationCount);
	~PICounter() = default;
	double CalculatePi();
private:
	size_t m_iterationCount;
	void SingleThreadCalculatior();
	bool IsPointInCircle(double x, double y);
	double m_pi;
};

