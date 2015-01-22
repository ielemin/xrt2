//
//  myList.cpp
//  xrt2
//
//  Created by Adrien on 21/01/2015.
//  Copyright (c) 2015 -. All rights reserved.
//

#include "myList.h"

// Implementations of myList

template<class T>
myList<T>::myList()
{
	NbItems = 0;
	first = nullptr;
	last = nullptr;
	current = first;
}

template<class T>
void myList<T>::Append(T newItem)
{
	//cout<<"Item #"<<NbItems<<":"<<endl;
	myListItem<T> newLast(newItem);
	
	if (first==nullptr)
	{
		first = &newLast;
		//last = &newLast;
	}
	else
	{
		last->Next = &newLast;
		//last = &newLast;
	}
	
	last = &newLast;
	
	NbItems++;
}
// For some reason, Next is always nullptr

template<class T>
bool myList<T>::Forward()
{
	if (current->Next == nullptr) return false;
	
	current = current->Next;
	
	return true;
}

template<class T>
void myList<T>::Rewind()
{
	current = first;
}

template<class T>
T myList<T>::Read()
{
	return current->Value;
}

template<class T>
bool myList<T>::Enumerate(T* output)
{
	output = &(current->Value);
	
	if (current->Next == nullptr)
	{
		Rewind();
		return false;
	}
	
	current = current->Next;
	return true;
}

// Implementations of myListItem

template<class T>
myListItem<T>::myListItem()
{
	Next = nullptr;
}

template<class T>
myListItem<T>::myListItem(T value):myListItem()
{
	Value = value;
	//cout<<value<<endl;
}
