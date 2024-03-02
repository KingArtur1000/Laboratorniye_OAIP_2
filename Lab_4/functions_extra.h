#pragma once

#include <iostream>
#include <vector>

#include "structs.h"


using std::cout;	/*Компромисс :)*/
using std::vector;

void exit(bool& flag);
void error();
void reset(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions);