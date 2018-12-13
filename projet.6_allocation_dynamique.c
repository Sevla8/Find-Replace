#include <stdio.h>
#include <stdlib.h>

unsigned long length(char*);
int convertor(char*);
char* simplifier(char*);
char* rule_assignor(char*, int);
char find_assignor(char*);
char* replace_assignor(char*);
int number_of_rules(char*);
char* substituor_0(char*, char);
char* substituor_1(char*, char, char*);
void substituor_2(char*, char**, int);

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

char* rule_assignor(char* list0, int spot){
	short l = (short) length(list0);
	char* rule = (char*) malloc(sizeof(char)*(l+1));
	short i = 0;
	short sp = 1;
	while (sp != spot){
		while (list0[i] != ',')
			i = i + 1;
		sp = sp + 1;
		i = i + 1;
	}
	rule[0] = list0[i];
	rule[1] = '>';
	i = i + 2;
	short k = 2;
	while (list0[i] != ','  && i < l){
		rule[k] = list0[i];
		i = i + 1;
		k = k + 1;
	}
	rule[k] = '\0';
	rule = (char*) realloc(rule, sizeof(char)*(k+1));
	return rule;
}

char find_assignor(char* rule){
	return rule[0];
}

char* replace_assignor(char* rule){
	short l = (short) length(rule);
	char* replace = (char*) malloc(sizeof(char)*(l-1));
	short i = 2;
	while (i < l){
		replace[i-2] = rule[i];
		i = i + 1;
	}
	replace[i-2] = '\0';
	return replace;
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

char* substituor_0(char* string, char find){
	unsigned long l1 = length(string);
	char* result = (char*) malloc(sizeof(char)*(l1*2+1));
	unsigned long i = 0;
	unsigned long j = 0;
	while (i < l1){
		while (string[i] != find && i < l1){
			result[j] = string[i];
			i = i+1;
			j = j+1;
		}
		if (string[i] == find && i < l1){
			result[j] = string[i];
			result[j+1] = '$';
			i = i+1;
			j = j+2;
		}
	}
	result[j] = '\0';
	result = (char*) realloc(result, sizeof(char)*(j+1));
	return result;
}

char* substituor_1(char* string, char find, char* replace){
	unsigned long l1 = length(string);
	unsigned long l2 = length(replace);
	char* result = (char*) malloc(sizeof(char)*(l1*l2+1));
	unsigned long i = 0;
	unsigned long j = 0;
	while (i < l1){
		while (string[i] != find && i < l1){
			result[j] = string[i];
			i = i + 1;
			j = j + 1;
		}
		if (string[i] == find && string[i+1] == '$' && i < l1){
			short k = 0;
			while (k < l2){
				result[j] = replace[k];
				j = j + 1;
				k = k + 1;
			}
			i = i+2;
		}
		else if (i < l1) {
			result[j] = string[i];
			j = j+1;
			i = i+1;
		}
	}
	result[j] = '\0';
	result = (char*) realloc(result, sizeof(char)*(j+1));
	return result;
}

void substituor_2(char* list, char** string, int times){

	char* list0 = simplifier(list);

	int x = number_of_rules(list0);

	for (int j = 1; j <= times; j = j+1){

		for (int spot = 1; spot <= x; spot = spot+1){

			char* rule = rule_assignor(list0, spot);

			char find = find_assignor(rule);

			char* string$ = substituor_0(*string, find);

			unsigned long l = length(string$);
			*string = (char*) realloc(*string, sizeof(char)*(l+1));
			for (unsigned long i = 0; i < l; i = i+1)
				(*string)[i] = string$[i];
			(*string)[l] = '\0';

			free(rule); free(string$);
		}
		for (int spot = 1; spot <= x; spot = spot+1){

			char* rule = rule_assignor(list0, spot);

			char find = find_assignor(rule);

			char* replace = replace_assignor(rule);

			char* result = substituor_1(*string, find, replace);

			unsigned long l = length(result);
			*string = (char*) realloc(*string, sizeof(char)*(l+1));
			for (unsigned long i = 0; i < l; i = i+1)
				(*string)[i] = result[i];
			(*string)[l] = '\0';

			free(rule); free(replace); free(result);
		}

	}

	free(list0);
}

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