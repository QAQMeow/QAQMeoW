#include<stdio.h>
#include"Graph.h"

int main()
{
	Gr G = InitGraph(0);
	
	printf("%d ",Adjanvent(G,1,3));
	return 0;
}