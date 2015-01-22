//
//  io_core.cpp
//  xrt2
//
//  Created by Adrien on 21/01/2015.
//  Copyright (c) 2015 -. All rights reserved.
//

#include "io_core.h"
#include "../myList.cpp"

/*template<class T>
void myList<T>::Append(T newItem)
{
	myListItem<T> newLast(newItem);
	
	if (NbItems==0)
	{
		first = &newLast;
	}
	else
	{
		last->Next = &newLast;
	}
	
	last = &newLast;
	NbItems++;
}*/

void loadFromCsv(string fileName, myList<string>* output)
{
	// fileName existence already tested above
	ifstream fileStream;
	fileStream.open(fileName);
	
	long currentLineCount=0;
	string currentLine;
	
	// Skip the file header
	if (fileStream.good())getline(fileStream, currentLine);
	
	string left;
	string right;
	
	// Read the lines
	while (fileStream.good())
	{
		getline(fileStream, currentLine);
		if (currentLine.empty()) continue;
		output->Append(currentLine);
		currentLineCount++;
	}
	
	// Properly close the file
	fileStream.close();
}