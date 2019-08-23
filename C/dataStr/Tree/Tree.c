#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"

/*
树结构：
          R
       /  |  \
	  A   B   C
	 / \     / | \ 
    D   E   G  H  K
*/

//建立双亲表示树
PTree BuildPTree()
{
	PTree PT;
	PT.n = 0;	//	节点个数
	PT.r = 0; 	//	树根位置在0
	
	printf("请输入树根元素:\n");
	scanf("%c",&PT.nodes[0].data);

	return PT;

}
//建立孩子表示树
CTree BuildCTree()
{

}
//输出双亲表示树
void PrintPTree(PTree Tree)
{
	if(Tree.n == 0)
		printf("树为空\n");
}

//输出孩子表示树
void PrintCTree(CTree Tree)
{

}