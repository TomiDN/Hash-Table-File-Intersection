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
#ifndef __INTERFACE_HEADER_INCLUDED_
#define __INTERFACE_HEADER_INCLUDED_

#include <iostream>
#include <fstream>
#include "HashTable.h"

class Interface{
private:
	HashT<long long int> hashche;
	std::ifstream infile;
	std::ofstream resfile;
public:
	Interface();
	~Interface();
	void SetSize(char*, int);
	void OpenFile(char*);
};

Interface::Interface()
{
	if (infile.is_open())
		infile.close();
	if (resfile.is_open())
		resfile.close();
}

Interface::~Interface()
{
	if (infile.is_open())
		infile.close();
	if (resfile.is_open())
		resfile.close();
}

void Interface::SetSize(char* name, int n)
{
	infile.open(name, std::ios::binary);
	infile.seekg(0, std::ios::end);
	unsigned size = infile.tellg() / 8;
	hashche.Set(size, n);
	infile.close();
}

void Interface::OpenFile(char* name)
{
	infile.open(name, std::ios::binary);
	long long int n = 0;
	while (infile.good())
	{
		infile.read((char*)(&n), sizeof(n));
		if (hashche.Hash(n))
		{
			resfile.open("result.bin", std::ios::binary | std::ios::app);
			resfile.write((char*)(&n), sizeof(n));
			resfile.close();
		}
	}
	infile.close();
}

#endif