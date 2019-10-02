#include<stdio.h>
#include"Graph.h"


int main()
{
	GRAPH G = InitTest(0);
	//printf("%d ",G.type);
	PrintG(G);
	printf("2 与 0 是否存在边 \n");
	Adjanvent(G,G.data[1],0);
	Neighbors(G, G.data[3]);
	printf("给节点 1 增加节点 5\n");
	InsertVertex(&G,5,1); 
	PrintG(G);
	printf("1 与 %d 是否存在边\n",G.data[G.vexnum-1]);
	Adjanvent(G,1,G.data[G.vexnum-1]);
	printf("删去节点 2\n");
	DeleteVertex(&G,2);
	PrintG(G);
	printf("2 与 5 是否存在边 \n");
	Adjanvent(G,2,5);
	printf("增加边1 - 7\n");
	AddEdge(&G,1,7);
	PrintG(G);
	Adjanvent(G,1,7);

	return 0;
}