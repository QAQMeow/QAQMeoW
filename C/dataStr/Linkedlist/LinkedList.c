#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

//Initialize list 初始化链表
List IniList()
{
	Node* head=(Node*)malloc(sizeof(Node));
	Node* L=(Node*)malloc(sizeof(Node));
	L = head;
	head->next = NULL; 
	printf("是否增加节点(1:增加，0：不增加)\n");
	int x;
	int i = 1;
	scanf("%d",&x);
	while(x)
	{	
		AddItem(L,i);
		printf("是否增加节点(1:增加，0：不增加)\n");
		scanf("%d",&x);
		i++;
	}
	
	return L;
}

//Detects if the list is empty 检测列表是否为空
int IsListEmpty(List L)
{
	return L->next == NULL;
	
}

//Add an items position n 在 n 位置添加1项
void AddItem(List L,int n)
{		
	
	if(0<n&&n<=CacList(L)+1)
	{	Node* p =(Node*)malloc(sizeof(Node));
		p=L;
		for(int i =1;i<n;i++)
		{
			p = p->next;		
		}

		Node* node = (Node*)malloc(sizeof(Node));
		node->next = p->next;
		printf("请输入节点数据：\n");
		scanf("%d",&node->data);
		p->next = node;
		p =p->next;	
	}else printf("输入添加位置超出链表范围\n");
			
}


//print 输出
void PrintList(List L)
{
	Node* P = (Node*)malloc(sizeof(Node));
	P = L->next;
	while(P!=NULL)
	{
		printf("%d ",P->data);
		P = P->next;
	}
	
}

//Caculate List Items number 计算节点总数
int CacList(List L)
{
	Node* P = (Node*)malloc(sizeof(Node));
	P = L;
	int i = -1;
	while(P!= NULL)
	{
		P = P->next;
		i++;	
	} 
	return i;
}


//Delete an item which position is n 删除 n 位置上的项
void DelItem(List L,int n)
{
	Node* p =(Node*)malloc(sizeof(Node));
	p= L;
	if(IsListEmpty(L))
	printf("链表为空无法删除");
	else
	{
		if(0<n&&n<=CacList(L)+1)
		{	
			for(int i =1;i<n;i++)
			{
				p = p->next;		
			}

			
			p->next = p->next->next;
				
		}else printf("输入删除位置不在链表范围\n");
	}
}

//Delete the List 删除列表
void CleanList(List L)
{
	L->next = NULL;
}












