#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"

int main()
{
	PTree PT = BuildPTree();
	//Ctree CT = BuildCTree();
	PrintPTree(PT);
	//PrintCTree(CT);
	return 0;
}