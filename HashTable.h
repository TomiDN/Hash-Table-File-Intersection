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
#ifndef __HASHTABLE_HEADER_INCLUDED_
#define __HASHTABLE_HEADER_INCLUDED_

#include <iostream>
#include "TList.h"

template<class T>
class HashT{
private:
	unsigned size;
	int count;
	TList<T>* slot;
public:
	HashT() : size(0), count(0) {}
	HashT(HashT&);
	~HashT() { delete[]slot; }
	unsigned GetSize()const{ return size; }
	HashT& operator=(HashT&);
	void Set(unsigned, int);
	bool Hash(T);
private:
	void Copy(HashT&);
};

template<class T>
HashT<T>::HashT(HashT<T>& obj)
{
	Copy(obj);
}

template<class T>
HashT<T>& HashT<T>::operator=(HashT<T>& obj)
{
	if (this != &obj)
	{
		delete[]slot;
		Copy(obj);
	}
	return *this;
}

template<class T>
void HashT<T>::Set(unsigned num, int cnt)
{
	size = num;
	count = cnt;
	slot = new TList<T>[size];
}

template<class T>
bool HashT<T>::Hash(T el)
{
	long long int hashed = el%size;
	return slot[hashed].Search(el, count);
}

template<class T>
void HashT<T>::Copy(HashT<T>& obj)
{
	size = obj.size;
	slot = new TList<T>[size];
	for (long long int i = 0; i < size; i++)
	{
		this->slot[i] = obj.slot[i];
	}
}

#endif 