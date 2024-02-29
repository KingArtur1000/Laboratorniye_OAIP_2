#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "functions_for_array.h" 


using std::cin;
using std::cout;
using std::vector;
using std::sort;
using std::min;
using std::max;


void input_searched_value(int& target);
void incremental_search(vector <int> arr, int target);
void jump_search(vector <int> arr, int target);
void index_sequential_search(vector <int> arr, int target);
void binary_search(vector <int> arr, int target);
void binary_search_recursive(vector <int> arr, int target, const int &left, const int &right, int& operations, bool& flag_2);