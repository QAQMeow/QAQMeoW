#include<stdio.h>
#include<stdlib.h>
typedef struct Queue
{
	struct Node* Entrance;
	struct Node* Exit;	
}Queue;

typedef struct Node
{
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

//Initialize stack
Queue IniQueue();

//Add an Item 
void InQueue(Queue* q);

//Output an Item
void OutQueue(Queue* q);

//IsQueueEmpty
int IsEmpty(Queue* q);

//Print stack
void PrintQueue(Queue* q);

//Delete Stack
void DelQueue(Queue* q);
