#pragma once	 /*директива для предотвращения многократного включения заголовочных файлов*/


const int LEN = 256;


struct Mum {
	int age = 0;
	char sex = 'Ж';
	char name[LEN];
};


struct Dad {
	int age = 0;
	char sex = 'М';
	char name[LEN];
};


union Parents {
	Mum mum = {0, 'Ж', ""};
	Dad dad;
};