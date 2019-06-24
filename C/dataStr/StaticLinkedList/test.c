#include<stdio.h>
#include"LinkedList.h"

int main()
{
	printf("******初始化链表并添加五项*****\n");
	List L = IniList();
	for(int i =0;i<3;i++)
	{	int x;
		printf("\n请输入数据:\n");
		scanf("%d",&x);
		AddItem(&L,x);
	}	
	printf("\n******输出链表*****\n");
	PrintList(L);
	printf("\n******删除链表*****\n");
	DelList(&L);
	printf("\n******输出链表*****\n");
	PrintList(L);
	return 0;	

}
