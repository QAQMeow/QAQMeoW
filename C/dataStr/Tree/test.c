#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"

int main()
 {	
	printf("建立以父节点表示的树\n");
	PTree PT = BuildPTree();
	printf("建立以孩子节点表示的树\n");
	CTree CT = BuildCTree();
	printf("\n以父节点表示的树：\n");
	PrintPTree(PT);
	printf("\n以孩子表示的树：\n");
	PrintCTree(CT);
	printf("\n以孩子表示的树第一个节点的所有子节点\n");
	PrintChild(CT,CT.nodes[0]);	
	return 0;
}