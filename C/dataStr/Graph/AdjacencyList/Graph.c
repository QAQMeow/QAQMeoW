#include<stdio.h>
#include"Graph.h"
#include<stdlib.h>


Gr InitGraph(int x)
{
	Gr G = (GRAPH*)malloc(sizeof(GRAPH));

	G->vexnum = 0;
	G->arcnum = 0;
	G->type = x;
	for (int i = 0; i < G->vexnum; ++i)
	{
		G->H[i].first = NULL;
	}
	return G;

}

//测试图 
/*
1—— 2
| / 
3—— 4

1<——>2——>3
^		  ^
|		  |
|—————————|
		  4

*/


Gr InitTest(int x)
{
	;
}



//判断图是否有边<x,y>,或（x,y）
int Adjanvent(Gr G,int x,int y)
{
	Node* x1 = NULL;
	for (int i = 0; i < G->vexnum; ++i)
	{
		if(x==G->H[i].Head)
		{
			//x1 =  (Node*)malloc(sizeof(Node));
			x1 = G->H[i].first;	
			break;
		}	
	}
if(x1!=NULL)
{	while(x1 != NULL|| x1->data != y)
	{

		x1 = x1->next;
	}
}
	if(x1 == NULL)
		return 0;
	else
		return 1;
}

//列出图中与节点x邻接的边
void Neighbors(Gr G,int x){}

//在图中插入顶点x
void InsertVertex(Gr G,int x)
{
	G->H[G->vexnum].Head = x;
	G->H[G->vexnum].first = NULL;
	G->vexnum+=1;
}

//从图中删除顶点x
void DeleteVertex(Gr G,int x){}

//若边(x,y)或<x,y>不存在，则添加该边
void AddEdge(Gr G,int x,int y)
{

}

//求图中顶点x的第一个邻接点
void FirstNeighbor(Gr G,int x){}

//求除y外顶点x的下一个邻接点
void NextNeighbor(Gr G,int x,int y){}

//获取边(x,y)或<x,y>的权值
int Get_edge_weight(Gr G,int x,int y){} 

//设置边(x,y)或<x,y>的权值为w
void Set_edge_wight(Gr G,int x,int y,int w){}


//输出节点

void PrintG(Gr G){}