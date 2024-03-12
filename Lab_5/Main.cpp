#include "lab_5.h"	//Подключили собственный заголовочный файл


int main() {
	system("chcp 1251");
	system("cls");
	setlocale(0, "");


	int choice = 0;
	int size = 0;
	bool flag = true;
	vector <int> arr_original;	//Да-да наконец-то используем vector :)
	vector <int> arr_sorted;
	Conditions conditions;
	Actions actions;


	//массив указателей на функции
	void (*sort_functions[])(vector<int>&, vector<int>&, Conditions&, Actions&) = {
		bubble_sort,
		shaker_sort,
		dwarves_sort,
		inserts_sort,
		selection_sort,
		shell_sort,
		recursive_sort_combo,
		hoara_sort_combo,
		merging_sort
	};


	input_size_of_arr(size);
	fill_arr(arr_original, arr_sorted, size);
	output_original(arr_original, arr_sorted, conditions);


	int num_sort_functions = sizeof(sort_functions) / sizeof(sort_functions[0]);

	for (int i = 0; i < num_sort_functions; i++) {

		cout << "\n\tСортировка " << i + 1 << ": " << '\n';
		sort_functions[i](arr_original, arr_sorted, conditions, actions);
	}

	
	void (*sort_function)(vector<int>&arr_original, vector<int>&arr_sorted, Conditions& conditions, Actions& actions) = get_sort_function();

	// Вызываем функцию сортировки
	if (sort_function != nullptr) {
		sort_function(arr_original, arr_sorted, conditions, actions);
	}

	sort_function_typedef sort_function_typedef = get_sort_function_typedef();
	
	// Вызываем функцию сортировки (typedef)
	if (sort_function_typedef != nullptr) {
		sort_function_typedef(arr_original, arr_sorted, conditions, actions);
	}

	sort_function_using sort_function_using = get_sort_function_using();

	// Вызываем функцию сортировки (using)
	if (sort_function_using != nullptr) {
		sort_function_using(arr_original, arr_sorted, conditions, actions);
	}

	return 0;
}