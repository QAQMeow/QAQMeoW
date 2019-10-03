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
	int x1 = -1;
	int y1 = -1;
	for (int i = 0; i < G.vexnum; ++i)		//
	{
		if(x == G.data[i])
			x1 = i;
		if(y == G.data[i])
			y1 = i;
	}
	if (x1==-1||y1 == -1)
	{
		printf("不存在\n");
		return;
	}
	else
		{	if(G.Array[x1][y1] != 0)
			{	
				if(G.type == 1)
					printf("存在 <%d , %d> \n",x,y);
				else
					printf("存在 (%d , %d)\n",x,y);
				return;
			}
			else if(G.Array[x1][y1] == 0)
			{	if(G.type == 0)
				{
					if(G.Array[y1][x1] != 0)
						printf("存在 (%d , %d)\n",x,y);
					else
					printf("不存在\n");
					return;
				}
				else
					printf("不存在\n");
				return;
			}
		}
}

//列出图中与节点x邻接的边
void Neighbors(GRAPH G,int x)
{
	int x1;
	for (int i = 0; i < G.vexnum; ++i)		//
	{
		if(x == G.data[i])
			x1 = i;
	}
	printf("%d 的领边有：\n",	x);
	
	for (int j = 0; j < G.vexnum; ++j)
		{
			if(G.Array[j][x1] != 0)
				printf("%d ",G.data[j]);

		}

	for (int i = 0; i < G.vexnum; ++i)
	{
			if(G.Array[x1][i] != 0)
				printf("%d ",G.data[i]);
	
	}
	printf("\n");
}

//在图中插入顶点x, y 为与新节点x相连的旧节点
void InsertVertex(GR G,int x,int y) 
{//只加一条边了，之后再写增加多条边 0_0
	
	
	int z = G->vexnum;
	G->data[z] = x;
		G->vexnum+=1;
	if(G->type)
	{

		for (int i = 0; i < G->vexnum; ++i)		//
		{
			if(y == G->data[i])
				{
					G->Array[i][z] = 1;
					return;
				}
		}
		

	}
	else
	{
		
		for (int i = 0; i < G->vexnum; ++i)		//
		{
			if(y == G->data[i])
			{
				G->Array[i][z] = 1;
				return;
			}

		}

	
	}



}

//从图中删除顶点x
void DeleteVertex(GR G,int x)
{
	int x1;
	for (int i = 0; i < G->vexnum; ++i)		//
	{
		if(x == G->data[i])
		{
			G->data[i] = 0;
			x1 = i;
		}
	}

for (int i = x1; i < G->vexnum; ++i)
{
	int t;
	t = G->data[i];
	G->data[i] = G->data[i+1];
	G->data[i+1] = t;
}
	for (int j = 0; j < G->vexnum; ++j)
		{
			if(G->Array[j][x1] != 0)
				G->Array[j][x1] = 0;

		}

	for (int i = 0; i < G->vexnum; ++i)
	{
			if(G->Array[x1][i] != 0)
				G->Array[x1][i] = 0;
	
	}
	G->vexnum--;
}

//若边(x,y)或<x,y>不存在，则添加该边
void AddEdge(GR G,int X,int Y)
{
	int x1 =-1;
	int y1 =-1;
	int func(GR G,int x,int y)
	{
		
		for (int i = 0; i < G->vexnum; ++i)		//
		{
			if(x == G->data[i])
				x1 = i;
			if (y == G->data[i])
				y1 = i;
		}

		if(x1!=-1&&y1!=-1)
			return 1;
		else
			return 0;

		
	}

	int T = func(G,X,Y);
	
	if(T==0)
	{
		if(x1==-1&&y1!=-1)
			InsertVertex(G ,X,Y);
		else if((x1!=-1&&y1==-1))
			InsertVertex(G ,Y,X);
		else if((x1==-1&&y1==-1))
		{
			G->data[G->vexnum] = X;
			G->data[G->vexnum+1] = Y;
			G->vexnum+=2;
			G->Array[G->vexnum-2][G->vexnum-1] = 1;
		}
	}
}

//求图中顶点x的第一个邻接点
void FirstNeighbor(GRAPH G,int x)
{}

//求除y外顶点x的下一个邻接点
void NextNeighbor(GRAPH G,int x,int y){}

//获取边(x,y)或<x,y>的权值
int Get_edge_weight(GRAPH G,int x,int y)
{
	int x1 = -1;
	int y1 = -1;
	for (int i = 0; i < G.vexnum; ++i)	
	{
		if(x == G.data[i])
			x1 = i;
		if(y == G.data[i])
			y1 = i;
	}
	return G.Array[x1][y1];

} 

//设置边(x,y)或<x,y>的权值为w
void Set_edge_wight(GR G,int x,int y,int w)
{
	int x1 = -1;
	int y1 = -1;
	for (int i = 0; i < G->vexnum; ++i)	
	{
		if(x == G->data[i])
			x1 = i;
		if(y == G->data[i])
			y1 = i;
	}
	G->Array[x1][y1] = w;
}

void PrintG(GRAPH G)
{
	if(G.type)
	{
		printf("有向图G节点有：\n");
		for (int i = 0; i < G.vexnum; ++i)
		{
			printf("%d ", G.data[i]);
		}
		printf("\n");
	}
	else
	{
		printf("无向图G节点有：\n");
		for (int i = 0; i < G.vexnum; ++i)
		{
			printf("%d ", G.data[i]);
		}
		printf("\n");
	}
}