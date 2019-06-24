#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

int main()
{
	printf("*****初始化一个空栈*****\n");	
	Stack S = IniStack();
	printf("\n*****压入5个节点*****\n");
	for(int i = 1;i<=5;i++)
	InStack(&S);
	
	PrintStack(&S);
	printf("\n*****出栈3个节点*****\n");
	for(int i = 1;i<=3;i++)
	OutStack(&S);
	PrintStack(&S);	
	printf("删除栈\n");
	DelStack(&S);
	PrintStack(&S);
	return 0;
}

