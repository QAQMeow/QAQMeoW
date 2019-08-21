#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"
#include<string.h>

int main()
{

	printf("前序建立二叉树:\n");
	TREE T= InitTree();
	printf("中序遍历输出二叉树：\n");
	PrintTree(T);
	printf("\n二叉树中序线索化后输出：\n");
	TREE NewT = ThreadTree(T);
	PrintTT(NewT);
	printf("\n");
	return 0;
}