#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"

int main()
{
	//PTree PT = BuildPTree();
	CTree CT = BuildCTree();
	//PrintPTree(PT);
	PrintCTree(CT);
	PrintChild(CT,CT.nodes[0]);	
	return 0;
}