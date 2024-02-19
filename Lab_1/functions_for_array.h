#pragma once	 /*директива для предотвращения многократного включения заголовочных файлов*/

#include <iostream>
#include <fstream>
#include <string>

#include "structures.h"
#include "functions_extra.h"


using std::cin;		/*Компромисс :)*/
using std::cout;
using std::fstream;
using std::string;
using std::getline;


void input(Parents* parents, const int SIZE);
void remove(Parents* parents, const int SIZE);
void output(Parents* parents, const int SIZE);
void output_arr(Parents* parents, const int SIZE);