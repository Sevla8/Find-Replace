#ifndef SYMBOL
#define SYMBOL

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

#endif