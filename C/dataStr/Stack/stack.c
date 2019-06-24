#include<stdio.h>
#include<stdlib.h>
#include"stack.h"



//Initialize stack
Stack IniStack()
{
	Stack S;
	S.Top =NULL;
	S.Buttom = NULL;
	return S;
}
//Add 
void InStack(Stack* stack)
{
	Node* node = (Node*)malloc(sizeof(Node));
	printf("请输入数据：");
	scanf("%d",&node->data);

	node->next = stack->Top;
	stack->Top = node;

	if(stack->Buttom == NULL)
	{
		stack->Buttom = node;
	}


}

//Delete
void OutStack(Stack* S)
{
	if(S->Top == NULL)
	printf("Stack is Empty,Use method :InStack(Stack* stack) to add an Item\n");
	
		
	else 
	{	printf("出栈数据：%d\n",S->Top->data);
		S->Top=S->Top->next;
	}
}

//IsStackEmpty
int IsEmpty(Stack* stack)
{
	return stack->Top == NULL;

}

//Print stack
void PrintStack(Stack* stack)
{
	Node* P = stack->Top;
	if(stack->Top == NULL)
	printf("Stack is Empty.\n");
	else
	{
		printf("Buttom[ ");
		while(P!= NULL)
		{
			printf("%d ",P->data);
				P = P->next;
		}
		printf("]Top\n");
	}

	free(P);
}

//Delete Stack
void DelStack(Stack* S)
{
	if(S->Top == NULL&&S->Buttom == NULL)
	printf("Stack is Empty,Use method :InStack(Stack* stack) to add an Item\n");
	else
	{	
		S->Buttom = S->Buttom->next;
		S->Top = S->Buttom;
		
	}

}


