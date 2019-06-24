#include<stdio.h>
#include<stdlib.h>
#include"List.h"

//Initialize List 初始化List
List IniList(int x,int t)
{		
	printf("请输入各项值：\n");
	
	List list;
	list.last = 0;
	list.L = &list;

	switch(t)
	{	
		case 1:
			list.datatype = 1;	
			for(int i = 0;i<x;i++)
			{	
				scanf("%d",&list.Data[i].i);
				list.last +=1;		
			}break;
		case 2:
			list.datatype = 2;		
			for(int i = 0;i<x;i++)
			{	
				scanf("%f",&list.Data[i].f);
				list.last +=1;		
			}break;
		case 3:
			list.datatype = 3;
			for(int i = 0;i<x;i++)
			{	
				scanf("%lf",&list.Data[i].d);
				list.last +=1;		
			}break;
		case 4:
			list.datatype = 4;		
			for(int i = 0;i<x;i++)
			{	getchar();
				scanf("%c",&list.Data[i].c);
				list.last +=1;		
			}break;
		default: printf("ERROR ");break;
	}
	return list;
}

//Delete the List 删除列表
void DelList(List* list)
{
	list->last = 0;
}

//Detects if the list is empty 检测列表是否为空
int IsListEmpty(List* list)
{
	if(list->last != 0)
	return  1;
	else 
	return 0;
}
//print 输出
void PrintList(List* list)
{
	if(IsListEmpty(list))
	{
		switch(list->datatype)
		{	
			case 1:for(int i = 0;i<list->last;i++)
			{	
				printf("%d ",list->Data[i].i);
				
			}break;
			case 2:for(int i = 0;i<list->last;i++)
			{	
				printf("%.2f ",list->Data[i].f);
				
			}break;
			case 3:for(int i = 0;i<list->last;i++)
			{	
				printf("%.5lf ",list->Data[i].d);
			
			}break;
			case 4:for(int i = 0;i<list->last;i++)
			{	
				printf("%c ",list->Data[i].c);			
			}break;
			default :printf("ERROR ");break;
		}
	}else printf("list is empty\n");
}

//Add a item in position n 在 n 位置添加一项
void AddItem(List *list,int n)
{
	if(IsListEmpty(list))
	{	
		if(0<n&&n<=list->last)
		{
			
			list->last += 1;
			n =n-1;
			if(0<list->last&&list->last<=10)
			{
				switch(list->datatype)
				{
					
					case 1: 
						
						for(int i = list->last-1;i>n;i--)
						{
							list->Data[i].i = list->Data[i-1].i;				
						}
						printf("请输入插入值：\n");
						scanf("%d",&list->Data[n].i);
						break;
					case 2:
						for(int i = list->last-1;i>n;i--)
						{
							list->Data[i].f = list->Data[i-1].f;				
						}
						printf("请输入插入值：\n");
						scanf("%f",&list->Data[n].f);
						break;
					case 3:
						for(int i = list->last-1;i>n;i--)
						{
							list->Data[i].d = list->Data[i-1].d;				
						}
						printf("请输入插入值：\n");
						scanf("%lf",&list->Data[n].d);
						break;
					case 4:
						for(int i = list->last-1;i>n;i--)
						{
							list->Data[i].c = list->Data[i-1].c;				
						}
						printf("请输入插入值：\n");
						getchar();
						scanf("%c",&list->Data[n].c);
						break;
					default:break;
				}
			}
			else if(list->last>10)
			{
				list->last -=1;
				printf("超过List容量");
			}
		}
		else 
		printf("ERROR ");
	}else printf("List is empty\n");
}

//Delete a item which position is n 删除 n 位置上的项
void DelItem(List* list,int n)
{	
	
	if(0<n&&n<=10)
	{
		if(IsListEmpty(list))
		{
			list->last -=1;
			n =n-1;
			switch(list->datatype)
			{	
				case 1:for(int i =n;i<list->last;i++)
					{
						list->Data[i].i = list->Data[i+1].i;
					}
					break;
				case 2:
					for(int i =n;i<list->last;i++)
					{
						list->Data[i].f = list->Data[i+1].f;
					}
					break;
				case 3:
					for(int i =n;i<list->last;i++)
					{
						list->Data[i].d = list->Data[i+1].d;
					}
					break;
				case 4:
					for(int i =n;i<list->last;i++)
					{
						list->Data[i].c = list->Data[i+1].c;
					}
					break;	
				default: printf("ERROR 1");break;	
			}
			
		}
		else if(n == list->last)
		list->last -=1;
		else
		printf("ERROR2");
	}
	else 
	printf("list is empty\n");
} 



