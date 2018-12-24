#include "substituor.h"

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