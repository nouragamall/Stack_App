/*
 ============================================================================
 Name        : mainBalance.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
char isMatchingPair(char Parenthese , char Top);
int main(void) {
	char Parenthese[100];
	stack_t exp;
	int i;
	setbuf(stdout,NULL);
	printf("Enter the Expression :");
	scanf("%s",Parenthese);
	Stack_Init(&exp);
	for(i=0;Parenthese[i]!='\0';i++){
		if(Parenthese[i]=='('||Parenthese[i]=='{'||Parenthese[i]=='['){
			Stack_Push(&exp, Parenthese[i]);
		}
		else{
			char openParenthese;
			Stack_Top(&exp, &openParenthese);
			if(isMatchingPair(Parenthese[i],openParenthese)){
				Stack_Pop(&exp);
			}
		}
	}
	if(IsEmpty(&exp)){
				printf("Expression Balanced \n");
	}
			else{
				printf("Expression Not Balanced \n");
			}
	return EXIT_SUCCESS;
}

char isMatchingPair(char Parenthese , char Top)
{
	char LocReturn ;
	switch(Parenthese)
	{
		case ')': if(Top == '(')  LocReturn= 1 ; break;
		case '}': if(Top == '{')  LocReturn= 1 ; break;
		case ']': if(Top == '[')  LocReturn= 1 ; break;
		default : LocReturn= 0 ; break;
	}
	return LocReturn;
}
