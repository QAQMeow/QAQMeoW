#include<stdio.h>
//邻接矩阵
#define N 100
typedef int DataType;

typedef struct 
{	
	DataType data[N]; // 顶点
	int Array[N][N]; // 边表
	int arcnum;	// 图当前弧数
	int vexnum; // 图当前顶点数,边表行和列的长度
	int type;
}GRAPH;

//初始图
GRAPH InitGraph();
//测试图 
GRAPH InitTest(int x);



//判断图是否有边<x,y>,或（x,y）
void Adjanvent(GRAPH G,int x,int y);

//列出图中与节点x邻接的边
void Neighbors(GRAPH G,int x);

//在图中插入顶点x
void InsertVertex(GRAPH G,int x);

//从图中删除顶点x
void DeleteVertex(GRAPH G,int x);

//若边(x,y)或<x,y>不存在，则添加该边
void AddEdge(GRAPH G,int x,int y);

//求图中顶点x的第一个邻接点
void FirstNeighbor(GRAPH G,int x);

//求除y外顶点x的下一个邻接点
void NextNeighbor(GRAPH G,int x,int y);

//获取边(x,y)或<x,y>的权值
void Get_edge_weight(GRAPH G,int x,int y); 

//设置边(x,y)或<x,y>的权值为w
void Set_edge_wight(GRAPH G,int x,int y,int w);