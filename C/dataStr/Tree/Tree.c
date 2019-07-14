#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"
#include<string.h>
#define MAX 15

// Initialize Tree
TREE InitTree()
{
	TREE T;
	T= (TREE)malloc(sizeof(node));
	T = NULL;
	T = CreatTree(T);
	return T;
}

//Creat Tree
int level =1;
TREE CreatTree(TREE Tree)
{ 
	
	TREE T;
	T= (TREE)malloc(sizeof(node));
	char data[MAX];
	printf("请输入数据(#为空,输入叶节点后须输入两个#)：\n");
	scanf("%s",data);
	
	if(strcmp(data,"#")==0)
		T = NULL;
	else
	{
		if(Tree == NULL)
		{
			T->level = 1;
			T->pre= NULL;
		}
		else
		{
			T->pre = Tree;	
			T->level = Tree->level+1;	
		}
		T->data = atoi(data);
		T->left  = CreatTree(T);
		T->right = CreatTree(T);	
	}

	return T;
}

//Print Tree

void PrintTree(TREE T)
{
	if(T==NULL)
	{
		return;
	
	}
	else
	{
		PrintTree(T->left);
		printf("  %d    %d \n",T->data,T->level);
		PrintTree(T->right);		
	}
	
}

//Search Tree

void SearchTree(TREE T,int n)
{
	if(T==NULL)
	{
		return;	
	}	
	else
	{
		SearchTree(T->left,n);
		SearchTree(T->right,n);
		if(T->data == n)
			printf("  %d    %d \n",T->data,T->level);
		else
			return;
	}
}

void Num(TREE T,int* c)
{

	if(T==NULL)
	{
		return;
	
	}
	else
	{
		Num(T->left,c);
		*c+=1;
		Num(T->right,c);		
	}

}
//节点个数
int NumNode(TREE T)
{
	int n =0;
	Num(T,&n);
	return n;

}

// 层序遍历

void PrintTree_c1(TREE T)
{
	int n = NumNode(T);
	int* p = (int*)malloc(n*sizeof(int));
	int* t = p;
	int* l = p;
	//*****************************************
	//计算树的深度
 	int levelMax = 0;
	if(T!=NULL){
		levelMax = T->level;
		void CacuLevel(TREE T)
		{
			if(levelMax<=T->level)	
			levelMax = T->level;
			if(T->left!=NULL)
			CacuLevel(T->left);
			if(T->right!=NULL)
			CacuLevel(T->right);	
		}
		CacuLevel(T);
	}
	//*****************************************

	for(int l = 1;l<=levelMax;l++)
	{
		void readdata(TREE T)
		{
			if(l==T->level)	
			{*t  = T->data;
			t++;}
			if(T->left!=NULL)
			readdata(T->left);
			if(T->right!=NULL)
			readdata(T->right);	
		}
		readdata(T);	
	}	

	for(int i = 0;i<n;i++)
		printf("%d ",p[i]);

}










