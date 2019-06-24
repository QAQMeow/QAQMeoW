#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"


		
//Initialize list 初始化链表
List IniList()
{
	List L;
	L.HeadOfLeftNode = 0;   
	L.last = 0;       
	L.head = 0;
	for(int i = 0;i<14;i++)
	{
		L.node[i].next = i+1;
	}	
	
	L.node[14].next = -1;  //尾节点设为-1 
	return L;
}


	
//print 输出
void PrintList(List L)
{
	Point P;
	P = L.head;
	if(IsListEmpty(L))
	{
		printf("链表为空\n");	
	}
	else
	{
		for(int i = 0;i<L.last;i++)
		{
			printf("%d ",L.node[P].data);
			P = L.node[P].next;	
		}
		printf("\n");
	}	
}


//Detects if the list is empty 检测列表是否为空
int IsListEmpty(List List)
{
	return List.last == 0;
}
//Add an items  添加1项(该项所用节点来自来自剩余节点，添加在已存在节点后)
void AddItem(Lists List,int n)
{
	
	
	int XInTheLeft(int X)		//检测输入位置是否在剩余节点中
	{
		Point NP = List->HeadOfLeftNode;		
		while(NP != -1)
		{	if(X==NP)
			return 1;
			NP = List->node[NP].next;
		}
		return 0;

	}

	if(List->HeadOfLeftNode ==-1)
	{
		printf("链表已满\n");		
	}
	else
	{	
	
		Point P = List->HeadOfLeftNode;
		Point T = List->head;
		Point LP = List->HeadOfLeftNode;
		printf("可用节点位置：\n");	
		while(P != -1)
		{
			printf("%d ",P);
			P = List->node[P].next;
		}

		for(int i = 1;i<List->last;i++)
		{
			T = List->node[T].next;	
		}				//获取链表尾节点
		printf("\n请输入提取节点：");
		Point X;
		scanf("%d",&X);

		
		
		if(!XInTheLeft(X))
		{
			printf("输入位置超出范围，录入失败\n");
		}
		else
		{
				
			List->node[X].data =n;
			if(X == List->HeadOfLeftNode)
			{
				List->HeadOfLeftNode = List->node[List->HeadOfLeftNode].next;		
			}//如果取剩余头节点，HeadOFLeftNode往后移动一位
			else
			{
				
				while(List->node[LP].next != X)
				{
					LP = List->node[LP].next;	//找到X节点的前继节点
				}
				
				List->node[LP].next = List->node[X].next;	//修复x前后节点	
			}



			if(List->last == 0)
			{
				List->head = X;
					
			}
			else
			{
						
				List->node[T].next = X;		//将X节点插到List最后
			}
			
			
			List->last +=1;
		}
	}
//
	
//
}



//Delete the List 删除列表
void DelList(Lists List)
{
	List->head = 0;
	List->HeadOfLeftNode = 0;
	List->last =0;
	printf("链表已删除\n");
	
}











