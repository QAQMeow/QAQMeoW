#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"

int main()
{
	printf("前序建立二叉树:\n");
	TREE T= InitTree();
	printf("\n中序遍历输出:\n");
	printf("data level\n");
	PrintTree(T);
	printf("\n后序遍历查找n:\n");
	int n;
	printf("请输入查找数据:");
	scanf("%d",&n);
	printf("data level\n");
	SearchTree(T,n);
	printf("\n共有%d个节点\n",NumNode(T));
	printf("层序遍历输出:\n");
	PrintTree_c1(T);
	return 0;
}
