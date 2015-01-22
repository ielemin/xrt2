//
//  myList.h
//  xrt2
//
//  Created by Adrien on 21/01/2015.
//  Copyright (c) 2015 -. All rights reserved.
//

#ifndef __xrt2__myList__
#define __xrt2__myList__

#include <stdio.h>
#include <iostream>
using namespace std;

template<class T> class myListItem
{
private:
public:
	myListItem<T>* Next;
	T Value;
	myListItem();
	myListItem(T value);
};

// A very basic singly-linked class
template <class T> class myList
{
private:
	myListItem<T>* first;
	myListItem<T>* last;
	myListItem<T>* current;
public:
	int NbItems;
	myList();
	void Append(T newItem); // I do not want to handle possible loops at the moment, so I only append objects of type T, not myList<T>
	bool Forward();
	void Rewind();
	T Read();
	bool Enumerate(T* output);
};

#endif /* defined(__xrt2__myList__) */
