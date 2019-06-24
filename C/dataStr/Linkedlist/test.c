#include<stdio.h>
#include"LinkedList.h"

int main()
{
	List L = IniList();
	printf("\n****在链表第一位置增加一个节点****\n");
	AddItem(L,1);
	printf("\n****删除链表第三个位置节点****\n");
	DelItem(L,3);printf("\n该链表共有%d个节点\n",CacList(L));
	printf("\n****输出该链表****\n");
	PrintList(L);
	printf("\n****删除该链表****\n");
	CleanList(L);
	printf("\n该链表共有%d个节点\n",CacList(L));
	return 0;

}
