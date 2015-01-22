//
//  string_core.cpp
//  xrt2
//
//  Created by Adrien on 21/01/2015.
//  Copyright (c) 2015 -. All rights reserved.
//

#include "string_core.h"

/*bool split(string input,string delimiter,string* leftPart, string* rightPart)
{
	if (input.empty()||delimiter.empty())
	{
		*leftPart=input;
		*rightPart="";
		return false;
	}
	
	long delimiterPosition =input.find(delimiter);
	if (delimiterPosition<=0||delimiterPosition>=input.length()||delimiterPosition==string::npos)
	{
		*leftPart=input;
		*rightPart="";
		return true;
	}
	
	*leftPart = input.substr(0,delimiterPosition);
	*rightPart =input.substr(delimiterPosition+delimiter.length(),input.length());
	
	return true;
}*/

// This iterative split appends to output until no delimiter is found
bool split(string input,string delimiter,string*const& output)
{
	if (input.empty()||delimiter.empty())
	{
		output->append(input);
		return false;
	}
	
	long delimiterPosition =input.find(delimiter);
	if (delimiterPosition<=0||delimiterPosition>=input.length()||delimiterPosition==string::npos)
	{
		output->append(input);
		return true;
	}
	
	output->append(input.substr(0,delimiterPosition));
	
	return split(input.substr(delimiterPosition+delimiter.length(),input.length()),delimiter,output);
}