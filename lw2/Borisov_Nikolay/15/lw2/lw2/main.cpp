// lw3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "stdafx.h"
#include "Bear.h"
#include "Bee.h"
#include "BeeHive.h"
#include "Event.h"
#include "Semaphore.h"
#include "ThreadController.h"

using namespace std;

int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != 3)
	{
		cout << ">Неверное количество аргументов\n"
			<< "Используйте: lw2.exe <Максимальное количество меда> <Количество пчел>\n";
		return 1;
	}

	size_t hiveCapacity = atoi(argv[1]);
	size_t beeCount = atoi(argv[2]);

	Event wakeBearEvent = Event(FALSE);
	Semaphore workingBees = Semaphore(beeCount - 1, beeCount - 1);
	BeeHive hive(hiveCapacity, wakeBearEvent);
	Bear bear(hive, wakeBearEvent);
	vector<Bee> bees;
	for (size_t i = 0; i < beeCount; ++i)
	{
		bees.push_back(Bee(i + 1, hive, workingBees));
		hive.BeeFliesIn();
	}
	ThreadController controller;
	for (auto & bee : bees)
	{
		controller.Add(Bee::Loop, &bee);
	}
	controller.Add(Bear::Loop, &bear);

	controller.WaitAll();

	return 0;
}

