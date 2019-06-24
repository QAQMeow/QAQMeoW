#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

int main()
{
	printf("*****初始化一个空队列*****\n");	
	Queue Q = IniQueue();
	printf("\n*****压入5个节点*****\n");
	for(int i = 1;i<=5;i++)
	InQueue(&Q);
	
	PrintQueue(&Q);
	printf("\n*****出栈3个节点*****\n");
	for(int i = 1;i<=3;i++)
	OutQueue(&Q);
	PrintQueue(&Q);	
	printf("删除栈\n");
	DelQueue(&Q);
	PrintQueue(&Q);
	return 0;
}

