#include "assignor.h"

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