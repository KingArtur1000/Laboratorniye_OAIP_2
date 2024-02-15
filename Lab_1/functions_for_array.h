#pragma once	 /*директива для предотвращения многократного включения заголовочных файлов*/
#include "structures.h"


using namespace std;


void input(Parents* parents, const int SIZE);
void remove(Parents* parents, const int SIZE);
void output(Parents* parents, const int SIZE);
void output_arr(Parents* parents, const int SIZE);