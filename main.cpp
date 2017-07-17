/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Tomislav Nikolov
* @idnumber 45211
* @task 5
* @compiler VC
*
*/
#include <iostream>
#include "Interface.h"

int main()
{
	Interface Dis;
	int N;
	char name[256];
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		std::cin >> name;
		name[strlen(name)] = '\0';
		if (i == 0)
		{
			Dis.SetSize(name, N);
		}
		Dis.OpenFile(name);
	}
	std::cout << "Ready!\n";
	return 0;
}