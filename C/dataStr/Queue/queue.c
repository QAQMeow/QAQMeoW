#include<stdio.h>
#include<stdlib.h>
#include"queue.h"



//Initialize Queue
Queue IniQueue()
{
	Queue Q;
	Q.Entrance =NULL;
	Q.Exit = NULL;
	return Q;
}
//Add 
void InQueue(Queue* Q)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->pre = NULL;
	printf("请输入数据：");
	scanf("%d",&node->data);
	if(Q->Entrance == NULL)
	{	node->next = Q->Entrance;
		Q->Entrance = node;
		Q->Exit = node;	
		
	}
	else
	{	Q->Entrance->pre = node;
		node->next = Q->Entrance;
		Q->Entrance = node;
				
	}	
}

//out
void OutQueue(Queue* Q)
{
	if(Q->Exit== NULL)
	{
		printf("Queue is Empty,Use method :InQueue(Queue* queue) to add an Item\n");
	}
	else if(Q->Exit->pre == NULL)
	{
		printf("出栈数据：%d\n",Q->Exit->data);
		Q->Entrance = Q->Exit->pre;
		Q->Exit = Q->Exit->pre;
		
	}	
	else 
	{	
		printf("出栈数据：%d\n",Q->Exit->data);
		Q->Exit->pre->next = Q->Exit->next;
		Q->Exit = Q->Exit->pre;
		
	}
}

//IsQueueEmpty
int IsEmpty(Queue* Q)
{
	return Q->Entrance == NULL;

}

//Print queue
void PrintQueue(Queue* Q)
{
	Node* P = Q->Entrance;
	if(Q->Entrance == NULL)
	printf("Queue is Empty.\n");
	else
	{
		printf("Entrance[ ");
		while(P!= NULL)
		{
			printf("%d ",P->data);
				P = P->next;
		}
		printf("]Exit\n");
	}

	free(P);
}

//Delete Queue
void DelQueue(Queue* Q)
{
	if(Q->Entrance == NULL&&Q->Exit == NULL)
	printf("Stack is Empty,Use method :InQueue(Queue* queue) to add an Item\n");
	else
	{	while(Q->Exit !=NULL)
		{
			Q->Exit = Q->Exit->pre;
		}
			Q->Entrance = Q->Exit;
		
	}

}


