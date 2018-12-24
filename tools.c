#include "tools.h"

unsigned long length(char* string){
	unsigned long l = 0;
	for(unsigned long i = 0; string[i] != '\0'; i = i+1)
		l = l + 1;
	return l;
}

int convertor(char* string){
	short l = (short) length(string);
	int x = 0;
	for (short i = 0; i < l; i = i+1){
		x = x * 10 + ((int)string[i]-48);
	}
	return x;
}

char* simplifier(char* list){
	short l = (short) length(list);
	char* list0 = (char*) malloc(sizeof(char)*l);
	short i = 1;
	short j = 0;
	while (list[i] != ']'){
		while (list[i] == ' ')
			i = i + 1;
		list0[j] = list[i];
		i = i + 1;
		j = j + 1;
		while (list[i] == ' ')
			i = i + 1;
		list0[j] = '>';
		i = i + 2;
		j = j + 1;
		while (list[i] == ' ')
			i = i + 1;
		while (list[i] != ' ' && list[i] != ',' && list[i] != ']'){
			list0[j] = list[i];
			i = i + 1;
			j = j + 1;
		}
		while (list[i] == ' ')
			i = i + 1;
		if (list[i] == ','){
			list0[j] = ',';
			i = i + 1;
			j = j + 1;
		}
	}
	list0[j] = '\0';
	list0 = (char*) realloc(list0, sizeof(char)*(j+1));
	return list0;
}



int number_of_rules(char* list0){
	short l = (short) length(list0);
	int times = 0;
	short i = 0;
	while (i < l){
		while (list0[i] != ',' && i < l)
			i = i + 1;
		times = times + 1;
		if (list0[i] == ',')
			i = i + 1;
	}
	return times;
}