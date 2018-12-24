#include <stdlib.h>
#include <stdio.h>
#include "substituor.h"
#include "tools.h"

int main(int argc, char* argv[]) {

	if (argc == 4){

		short l1 = length(argv[1]);
		char* list = (char*) malloc(sizeof(char)*(l1+1));
		for (short i = 0; i < l1; i = i+1)
			list[i] = argv[1][i];
		list[l1] = '\0';

		short l2 = length(argv[2]);
		char* string = (char*) malloc(sizeof(char)*(l2+1));
		for (short i = 0; i < l2; i = i+1)
			string[i] = argv[2][i];
		string[l2] = '\0';

		int times;
		times = convertor(argv[3]);

		substituor_2(list, &string, times); //soit on met &string soit on met string mais
											//auquel cas il aurait fallu déclarer un strinx
		printf("%s\n", string);				//dans substituor_2 avec les valeurs de string
											//et travailler sur stringx et faire un return sringx
		free(list);
		free(string);
	}

	return 0;
}