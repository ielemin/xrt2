//
//  io_core.h
//  xrt2
//
//  Created by Adrien on 21/01/2015.
//  Copyright (c) 2015 -. All rights reserved.
//

#ifndef __xrt2__io_core__
#define __xrt2__io_core__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include "myList.h"
using namespace std;

// Function declarations
void loadFromCsv(string fileName, myList<string>* output);

#endif /* defined(__xrt2__io_core__) */
