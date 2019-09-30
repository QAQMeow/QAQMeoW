#include<stdio.h>
#include"E_Queens.h"
#include<stdlib.h>
// test
int main()
{
	Cb c = InitTree();
	Cb b = c;

 	 CreatTree(c);
	 printf("%d",PrintTree(c));
	
	return 0;
}