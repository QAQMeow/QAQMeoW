#include<stdio.h>
#include<stdlib.h>
typedef struct Stack
{
	struct Node* Top;
	struct Node* Buttom;	
}Stack;

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

//Initialize stack
Stack IniStack();

//Add an Item 
void InStack(Stack* stack);

//Output an Item
void OutStack(Stack* stack);

//IsStackEmpty
int IsEmpty(Stack* stack);

//Print stack
void PrintStack(Stack* stack);

//Delete Stack
void DelStack(Stack* stack);
