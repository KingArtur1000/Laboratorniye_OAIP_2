#pragma once

#include <iostream>
#include <vector>
#include <chrono>

#include "structs.h"


using std::cout;	/*Компромисс :)*/
using std::vector;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::microseconds;


void exit(bool& flag);
void error();
void reset(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions);
steady_clock::time_point start_timer();
steady_clock::time_point end_timer();
long duration_time(steady_clock::time_point start, steady_clock::time_point end);