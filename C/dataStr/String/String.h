#include<stdio.h>
#define MAX 15
typedef struct String{
	
	char string[MAX];
	int last;		

}String;

typedef String* STRING;


//Initialize String 初始化串
STRING IniString();

//Print String
void PrintString(STRING string);

//KMP
void Kmp(STRING parent,STRING child);

// pattern matching
void PM(STRING parent,STRING child);

//delete string
void DelString(STRING string);
