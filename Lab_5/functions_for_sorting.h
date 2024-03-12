#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "functions_for_array.h"
#include "functions_extra.h"
#include "structs.h"


using std::cin;
using std::cout;
using std::vector;
using std::min;
using std::sort;
using std::swap;


void bubble_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions);
void shaker_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions);
void dwarves_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions);
void inserts_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions);
void selection_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions);
void shell_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions);
void recursive_sort(vector<int>& arr_original, vector<int>& arr_sorted, int left, int right, Conditions& conditions, Actions& actions);
void recursive_sort_combo(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions);
void hoara_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions, int begin, int end);
void hoara_sort_combo(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions);
void merge(vector<int>& arr, int left, int middle, int right, Actions& actions);
void merging_sort(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions);

void (*get_sort_function())(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions);

typedef void (*sort_function_typedef)(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions);
sort_function_typedef get_sort_function_typedef();


using sort_function_using = void (*)(vector<int>& arr_original, vector<int>& arr_sorted, Conditions& conditions, Actions& actions);
sort_function_using get_sort_function_using();