#pragma once	 /*��������� ��� �������������� ������������� ��������� ������������ ������*/


const int LEN = 256;


struct Mum {
	int age = 0;
	char sex = '�';
	char name[LEN];
};


struct Dad {
	int age = 0;
	char sex = '�';
	char name[LEN];
};


union Parents {
	Mum mum = {0, '�', ""};
	Dad dad;
};