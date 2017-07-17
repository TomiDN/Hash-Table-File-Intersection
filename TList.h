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
#ifndef __TLIST_HEADER_INCLUDED_
#define __TLIST_HEADER_INCLUDED_

template<class T>
class TList{
private:
	struct Node
	{
		T data;
		Node* next;
		int counter;
		Node(T el, Node* n = nullptr, int cnt = 0) :
			data(el),
			next(n),
			counter(cnt)
		{}
	};
	Node* Head;
	Node* Tail;
	int size;
public:
	TList() : Head(nullptr), Tail(nullptr), size(0) {}
	TList(TList&);
	~TList() { Release(); }
	TList& operator=(TList&);
	bool IsEmpty()const{ return(size == 0); }
	void PushTail(const T);
	void PopHead();
	bool Search(T, int);
private:
	bool SearchRec(T, int, Node*&);
	void Copy(TList&);
	void CopyRec(TList&, Node*&);
	void Release();
};

template<class T>
TList<T>::TList(TList<T>& obj)
{
	Copy(obj);
}

template<class T>
TList<T>& TList<T>::operator=(TList<T>& obj)
{
	if (this != &obj)
	{
		Release();
		Copy(obj);
	}
	return true;
}

template <class T>
void TList<T>::PushTail(const T el)
{
	if (IsEmpty())
	{
		Node* temp = new Node(el);
		Head = temp;
		Tail = Head;
	}
	else
	{
		Node* temp = new Node(el);
		Tail->next = temp;
		Tail = Tail->next;
	}
	size++;
}

template<class T>
void TList<T>::PopHead()
{
	Node* killer = Head;
	Head = Head->next;
	delete killer;
	size--;
}

template<class T>
bool TList<T>::Search(T el, int cnt)
{
	return SearchRec(el, cnt, Head);
}

template<class T>
bool TList<T>::SearchRec(T el, int cnt, Node*& Last)
{
	if (IsEmpty() || Last == nullptr)
	{
		PushTail(el);
		return false;
	}
	if (Last->data == el)
	{
		Last->counter++;
		if (Last->counter == cnt)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return SearchRec(el, cnt, Last->next);
}


template<class T>
void TList<T>::Copy(TList<T>& obj)
{
	size = obj.size;
	CopyRec(obj, obj.Head);
}

template<class T>
void TList<T>::CopyRec(TList<T>& obj, Node*& Last)
{
	if (Last == nullptr)
		return;
	if (IsEmpty())
	{
		Node* temp = new Node(obj.Head->data);
		temp->counter = obj.Head->counter;
		Head = temp;
		Tail = Head;
	}
	else
	{
		Node* temp = new Node(Last->data);
		temp->counter = Last->counter;
		Tail->next = temp;
		Tail = Tail->next;
	}
	CopyRec(obj, Last->next);
}

template<class T>
void TList<T>::Release()
{
	while (!IsEmpty())
	{
		PopHead();
	}
}

#endif