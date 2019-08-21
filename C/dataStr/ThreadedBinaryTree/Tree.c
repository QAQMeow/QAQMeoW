#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"
#include<string.h>
#define MAX 15
TREE InitTree()
{
	TREE T;
	T= (TREE)malloc(sizeof(Threadnode));
	T = NULL;
	T = CreatTree(T);
	return T;
}

//Creat Tree
TREE CreatTree(TREE Tree)
{ 
	
	TREE T;
	T= (TREE)malloc(sizeof(Threadnode));
	char data[MAX];
	printf("请输入数据(#为空,输入叶节点后须输入两个#)：\n");
	scanf("%s",data);
	
	if(strcmp(data,"#")==0)
		T = NULL;
	else
	{

		if(Tree == NULL)
		{
			T->pre= NULL;
		}
		else
		{
			T->pre = Tree;	
		}
		
		T->data = atoi(data);
		T->left  = CreatTree(T);
		T->right = CreatTree(T);	
	}

	return T;
}


TREE ThreadTree(TREE T)
{
	Threadnode* Pre = (Threadnode*)malloc(sizeof(Threadnode));
	Threadnode* Tree = (Threadnode*)malloc(sizeof(Threadnode));
	Pre = NULL;
	Tree = T;
	if(T==NULL)
	{
		return Pre;
	
	}
	else
	{
		ThreadTree(T->left);
		if(T->left == NULL)
		{
			T->ltag = 1;
			T->left = Pre;
		}
		else T->ltag = 0;
		if(Pre!=NULL&&Pre->right == NULL)
		{
			Pre->rtag =1;
			Pre->right = T;
		}
		Pre = T;
		printf("%d ",T->data);
		ThreadTree(T->right);		
	}
	free(Pre);
	while (Tree->left!=NULL)
	{
		Tree = Tree->left;
	}

	return Tree;

}

void PrintTree(TREE T)
{
	if(T==NULL)
	{
		return;
	
	}
	else
	{
		PrintTree(T->left);
		printf("%d ",T->data);
		PrintTree(T->right);		
	}
	
}

void PrintTT(TREE T)
{
	while(T->right!= NULL)
	{	printf("%d",T->data);
		T = T->right;
	}
}