#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"
#include<string.h>
#define MAX 15


//Creat Tree

TREE CreatTree()
{
	TREE T;
	T= (TREE)malloc(sizeof(node));
	char data[MAX];                      //输入字符串，若不等于“#”，则转换为int型
	printf("请输入数据(#为空)：\n");
	scanf("%s",data);
	getchar();
	if(strcmp(data,"#")==0)
	T = NULL;
	else
	{
		T->data = atoi(data);
		T->left = CreatTree();
		T->right = CreatTree();
	}	


	return T;
}

//Print Tree

void PrintTree(TREE T)
{
	if(T!=NULL)
	{
		printf("%d ",T->data);
		PrintTree(T->left);
		PrintTree(T->right);	
	
	}	
	
	
}









