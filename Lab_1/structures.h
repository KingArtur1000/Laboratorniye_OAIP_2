#pragma once	 /*��������� ��� �������������� ������������� ��������� ������������ ������*/
#include <string>


struct Mum {
	int age = 0;
	char sex = '�';
	std::string name = "";
};

struct Dad {
	int age = 0;
	char sex = '�';
	std::string name = "";
};

union Parents {
	Mum mum = {0, '�', ""};
	Dad dad;

	Parents() {}	//��-�� �� ��������, ��� ��� union ��� ������������ �� ���������!
	~Parents() {}
};