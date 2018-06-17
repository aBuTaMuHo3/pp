#include "stdafx.h"
#include "Bee.h"


Bee::Bee()
{
}


Bee::~Bee()
{
}

DWORD Buyer::loop(LPVOID data)
{
	ThreadData* threadData = static_cast<ThreadData*>(data);
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	seed *= threadData->number;
	std::mt19937 random(seed);
	while (true)
	{
		int cashNumber = random() % 3;
		std::printf("покупатель %d набирает продукты\n", threadData->number);
		Sleep(random() % 2000 + 2000);
		std::printf("покупатель %d идет на кассу %d \n", threadData->number, cashNumber);
		threadData->cashiers.at(cashNumber).Lock();
		std::printf("покупатель %d покупает на кассе %d \n", threadData->number, cashNumber);
		Sleep(random() % 1000 + 1000);
		std::printf("покупатель %d уходит с кассы %d \n", threadData->number, cashNumber);
		threadData->cashiers.at(cashNumber).Unlock();
	}
}