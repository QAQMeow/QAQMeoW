#include<stdio.h>
#include<stdlib.h>
#include"List.h"

int main()
{	
	int x,y,z,m;
	printf("该List共10项\n");	
	printf("数据类型1：整型\n数据类型2：浮点型\n数据类型3：Double型\n数据类型4：字符型\n");
	
	printf("请输入数据类型(1-4)：\n");
	scanf("%d" ,&y);
	printf("请输入List项数(<=10)：\n");
	scanf("%d",&x);

	List l = IniList(x,y);
	PrintList(&l);

	printf("请输入要插入的位置\n");	
	scanf("%d",&z);
	AddItem(&l,z);
	PrintList(&l);

	printf("请输入要删除的位置\n");
	scanf("%d",&m);
	DelItem(&l,m);
	PrintList(&l);
	
	printf("\n删除list\n");
	DelList(&l);
	PrintList(&l);
	return 0;
}
