#include "functions_extra.h"


void exit(bool& flag, string message) {
	cout << '\t' << message << '\n';
	flag = false;
}


void error() {
	cout << "�������� �����! �������� ������ ����� ������ ������ (��� ������)\n\n";
}