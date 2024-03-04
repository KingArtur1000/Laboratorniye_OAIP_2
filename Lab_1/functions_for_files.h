#pragma once	 /*директива для предотвращения многократного включения заголовочных файлов*/

#include <iostream>
#include <fstream>
#include <string>

#include "structures.h"
#include "functions_extra.h"


using std::cin;		/*Компромисс :)*/
using std::cout;
using std::fstream;
using std::ios;
using std::string;


void saving(Parents *parents, const int SIZE);
void reading(Parents *parents, const int SIZE);