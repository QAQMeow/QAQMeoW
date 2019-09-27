#include<stdio.h>
#include"E_Queens.h"
#include<stdlib.h>
int main()
{
	Cb c = InitTree();
	
	for(int i =0;i<3;i++)
	AddSon(c);
	//PrintResult(c);
	CreatTree(c);
	PrintTree(c);
	//printf("■ □  ");
	return 0;
}