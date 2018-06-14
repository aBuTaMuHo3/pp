#include "stdafx.h"
#include "PICounter.h"

using namespace std;
static const size_t MIN_ARGS_COUNT = 2;
static const size_t MAX_ARGS_COUNT = 3;
static const size_t MIN_ITERATION_COUNT = 1;
static const size_t MIN_THREAD_COUNT = 1;
static const string HELP_FLAG = "--h";
static const string HELP_MESSAGE = "To use this program, type \" lab1.exe <iteration_count>\" in your command line\n";
static const string ERROR_MESSAGE = "Invalid arguments \n" "Use lab1.exe --h for help\n";

int main(int argc, char *argv[])
{
	if (argc > MAX_ARGS_COUNT || argc < MIN_ARGS_COUNT)
	{
		cout << ERROR_MESSAGE;
		return 0;
	}
	if (argc == MIN_ARGS_COUNT && argv[1] == HELP_FLAG)
	{
		cout << HELP_MESSAGE;
		return 0;
	}
	if (argc == MIN_ARGS_COUNT && argv[1] != HELP_FLAG)
	{
		cout << ERROR_MESSAGE;
		return 0;
	}
	size_t iterationCount = stoi(argv[1]);
	size_t threadCount = stoi(argv[2]);
	if (threadCount < MIN_THREAD_COUNT || iterationCount < MIN_ITERATION_COUNT)
	{
		cout << ERROR_MESSAGE;
		return 1;
	}
	PICounter monteCarlo(iterationCount, threadCount);
	unsigned int startTime = clock();
	double pi = monteCarlo.CalculatePi();
	unsigned int endTime = clock();
	cout.precision(5);	
	cout << "Pi ~= " << pi << endl;
	cout << "Calculeted in " << (float)(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	return 0;
}