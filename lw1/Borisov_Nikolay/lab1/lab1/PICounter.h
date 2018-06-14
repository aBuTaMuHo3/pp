#pragma once
class PICounter
{
public:
	PICounter(size_t iterationCount, size_t threadCount);
	~PICounter() = default;
	double CalculatePi();
private:
	size_t m_iterationCount;
	size_t m_threadCount;
	double m_pi = 0;
	static size_t m_pointsInCircle;

	void SingleThreadCalculator();
	void MultiThreadCalculator();

	static DWORD WINAPI  CalculatePoint(LPVOID data);
	static bool IsPointInCircle(double x, double y);
};

