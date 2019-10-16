#include<iostream>
typedef int DataType;
typedef struct node
{
	DataType data;
	struct node* Top;		//栈顶
	struct node* next;		//
}node;

typedef Stack
{	
	struct node* stack;    // 头指针
	int len;			   // 栈元素个数
}Stack;