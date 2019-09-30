#include<stdio.h>
#include"Graph.h"

//测试图 输入值为1 时返回有向图 输入值为0时返回无向图
GRAPH InitTest(int x)
{
	GRAPH G;
	G.vexnum = 4;
	if(x == 1)
		G.type = 1;
	else
		G.type = 0;
	for(int i = 0;i<G.vexnum;i++)
	{
		G.data[i] = i+1;
	}
	// 无向图
	int a[4][4] = 
	{	{0,1,1,0},  
		{0,0,1,1},
    	{0,0,0,1},
    	{0,0,0,0}  	};
    ///有向图:
    int b[4][4] = 
	{	{0,1,0,1},  
		{1,0,0,1},
    	{1,1,0,0},
    	{0,0,1,0}  	};

    for (int i = 0; i < G.vexnum; ++i)
    {
    	for (int j = 0; j < G.vexnum; ++j)
    	{
    		if(x == 1)
    			G.Array[i][j] = b[i][j];
    		else if(x==0)
    			G.Array[i][j] = a[i][j];
    	}
    }
    return G;
}

//初始图
GRAPH InitGraph()
{

	GRAPH G;
	printf("请输入图类型（1为有向图0为无向图）\n");
	scanf("%d",&G.type);
	printf("请输入节点个数：\n");
	scanf("%d",&G.vexnum);
	printf("请输入各节点值\n");
	for(int i = 0; i<G.vexnum;i++)          // 输入节点值
	{

		scanf("%d",&G.data[i]);
	}
	
		for(int i = 0; i<G.vexnum;i++)       
	{
		printf("节点 %d 是否有边(Y/N)(该节点为头，无向图只输入首次出现的边)\n",G.data[i]);
	
		char X;
		getchar();
		scanf("%c",&X);
		int k = 1;
		while(X == 'Y'|| X=='y')
		{
			printf("节点：%d ",G.data[i]);
			printf("的一条边为：\n");
			int x;
			scanf("%d",&x);
			for(int j =0;j<G.vexnum;j++)
			{
				if(G.data[j] == x)
				{
					G.Array[i][j] = 1;
				}
			}
			k++;
			if(k>=G.vexnum)
				break;
			printf("节点 %d 是否有边(Y/N)\n",G.data[i]);
			char a;
			getchar();
			scanf("%c",&a);
			X=a;

		}
	}

	for (int i = 0; i < G.vexnum; ++i)
	{
		for (int j = 0; j < G.vexnum; ++j)
		{
			printf("%d ",G.Array[i][j]);
		}
		printf("\n");
	}

}



//判断图是否有边<x,y>,或（x,y）
void Adjanvent(GRAPH G,int x,int y)
{

}

//列出图中与节点x邻接的边
void Neighbors(GRAPH G,int x){}

//在图中插入顶点x
void InsertVertex(GRAPH G,int x){}

//从图中删除顶点x
void DeleteVertex(GRAPH G,int x){}

//若边(x,y)或<x,y>不存在，则添加该边
void AddEdge(GRAPH G,int x,int y){}

//求图中顶点x的第一个邻接点
void FirstNeighbor(GRAPH G,int x){}

//求除y外顶点x的下一个邻接点
void NextNeighbor(GRAPH G,int x,int y){}

//获取边(x,y)或<x,y>的权值
void Get_edge_weight(GRAPH G,int x,int y){} 

//设置边(x,y)或<x,y>的权值为w
void Set_edge_wight(GRAPH G,int x,int y,int w){}