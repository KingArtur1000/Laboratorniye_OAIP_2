#pragma once

#include <iostream>
#include <vector>

#include "structs.h"


using std::cin;
using std::cout;
using std::vector;


void input_size_of_arr(int& size);
void fill_arr(vector <int>& arr_original, vector <int>& arr_sort, int size);
void output(vector <int>& arr_original, vector <int>& arr_sorted, Conditions& conditions);
void output_original(vector <int>& arr_original, vector <int>& arr_sorted, Conditions& conditions);