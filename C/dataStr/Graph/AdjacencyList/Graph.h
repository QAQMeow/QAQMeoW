#include<stdio.h>
#define N 100

typedef int DataType; 
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node;

typedef struct HeadList
{
	int Head;
	Node* first;	
}HeadList[N];

typedef struct GRAPH
{
	int vexnum;
	int arcnum;
	int type;
	HeadList H;
}GRAPH;


typedef GRAPH* Gr;

Gr InitGraph(int x);
//测试图 
Gr InitTest(int x);



//判断图是否有边<x,y>,或（x,y）
int Adjanvent(Gr G,int x,int y);

//列出图中与节点x邻接的边
void Neighbors(Gr G,int x);

//在图中插入顶点x
void InsertVertex(Gr G,int x);

//从图中删除顶点x
void DeleteVertex(Gr G,int x);

//若边(x,y)或<x,y>不存在，则添加该边
void AddEdge(Gr G,int x,int y);

//求图中顶点x的第一个邻接点
void FirstNeighbor(Gr G,int x);

//求除y外顶点x的下一个邻接点
void NextNeighbor(Gr G,int x,int y);

//获取边(x,y)或<x,y>的权值
int Get_edge_weight(Gr G,int x,int y); 

//设置边(x,y)或<x,y>的权值为w
void Set_edge_wight(Gr G,int x,int y,int w);


//输出节点

void PrintG(Gr G);