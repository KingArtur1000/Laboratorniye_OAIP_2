#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "enum.h"
#include "functions_for_array.h"


using std::cin;
using std::cout;
using std::vector;
using std::min;
using std::sort;
using std::swap;


int find_min_index(vector<int> arr, int i, int j);
void bubble_sort(vector<int> arr, int size, bool is_sorted);
void shaker_sort(vector<int> arr, int size, bool is_sorted);
void dwarves_sort(vector<int> arr, int size, bool is_sorted);
void inserts_sort(vector<int> arr, int size, bool is_sorted);
void selection_sort(vector<int> arr, int size, bool is_sorted);
void shell_sort(vector<int> arr, int size, bool is_sorted);
void recursive_sort(vector<int> arr, int size, bool is_sorted, int index);
void hoara_sort(vector<int> arr, int size, bool is_sorted);
void merging_sort(vector<int> arr, int size, bool is_sorted);