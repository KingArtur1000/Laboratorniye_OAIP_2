#pragma once	 /*директива для предотвращения многократного включения заголовочных файлов*/
#include <string>


struct Mum {
	int age = 0;
	char sex = 'Ж';
	std::string name = "";
};

struct Dad {
	int age = 0;
	char sex = 'М';
	std::string name = "";
};

union Parents {
	Mum mum = {0, 'Ж', ""};
	Dad dad;

	Parents() {}	//Да-да не забываем, что для union нет конструктора по умолчанию!
	~Parents() {}
};