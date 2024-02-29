#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "enum.h"


using std::cin;
using std::cout;
using std::vector;
using std::min;
using std::sort;
using std::swap;


void bubble_sort(vector<int>& arr, int size);
void shaker_sort(vector<int>& arr, int size);
void dwarves_sort(vector<int>& arr, int size);
void inserts_sort(vector<int>& arr, int size);
void selection_sort(vector<int>& arr, int size);
void shell_sort(vector<int>& arr, int size);
void recursive_sort(vector<int>& arr, int size);
void hoara_sort(vector<int>& arr, int size);
void merging_sort(vector<int>& arr, int size);