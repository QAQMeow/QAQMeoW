#include<stdio.h>
#include<stdlib.h>
#include"E_Queens.h"
#define Queens 8 // 数组行列大小

//根节点
// 根节点数组元素全为0 可以自己赋值0 ，C语言不赋值默认为0
//根节点 Row = -1 Column = 0 方便之后计算
Cb InitTree()
{
	Cb C = (Chessboard*)malloc(sizeof(Chessboard));
	C->Row = -1;
	C->Column = 0;
	C->parent = NULL;
	C->snum = 0;
	C->Son = NULL;
	C->brother = NULL;
	return C;
}

/*
增加子节点，子节点数组元素进行筛选
步骤
1 将父节点 数组 复制给子节点
2 确定子节点的Row Column
Row = 父节点+1(父节点新建子节点)或兄弟节点Row
Column = 0或上一个节点Column+1
3 筛选 根据条件 若子节点中Column == 父节点Column 或者==父节点Column +1或者 == 父节点Column-1 则赋值为 0，否则对相应位置赋值为1
*/
void AddSon(Cb C)
{
	if(C == NULL)
		return;
	if(C->Son == NULL)
	{
		Cb Son = (Chessboard*)malloc(sizeof(Chessboard));
		Son->parent = C;
		Son->brother = NULL;
		Son->Row = C->Row+1;
		Son->Column = 0;
		for (int i = 0; i < Queens; ++i)
		{
			for (int j = 0; j < Queens; ++j)
			{
				Son->board[i][j] = C->board[i][j];
			} 
		}
		int i = C->Row;
		int j = C->Column;

		 if(i>=0)
		 {
		 	if(Son->Column==j || Son->Column== j-1 || Son->Column==j+1)
		 		Son->board[Son->Row][Son->Column]=0;
		 	else
		 		Son->board[Son->Row][Son->Column]=1;
		 }
		  else
			 Son->board[Son->Row][Son->Column]=1;
		C->Son = Son;
		C->snum++;
	}
	else
	{
		C->snum++;
		Cb Son = (Chessboard*)malloc(sizeof(Chessboard));
		Son->brother = C->Son;
		Son->parent = C;
		Son->Row = C->Son->Row;
		Son->Column = C->Son->Column+1;
		for (int i = 0; i < Queens; ++i)
		{
			for (int j = 0; j < Queens; ++j)
			{
				Son->board[i][j] = C->board[i][j];

			} 
		}
		int i = C->Row;
		int j = C->Column;
		if(i>=0)
		 {
		 		if(Son->Column==j || Son->Column== j-1 || Son->Column==j+1)
		 		Son->board[Son->Row][Son->Column]=0;
		 	else
		 		Son->board[Son->Row][Son->Column]=1;
		 }
		  else
		 	Son->board[Son->Row][Son->Column]=1;
			
		
		C->Son = Son;	
	}

}

void PrintResult(Cb C)
{
	Cb node = C->Son;
	while(node!=NULL)
	{
		for (int i = 0; i < Queens; ++i)
		{
			for (int j = 0; j < Queens; ++j)
			{
				printf("%d ",node->board[i][j]);
			} 
			printf("\n");
		}
		printf("\n");
		node = node->brother;
	}
		
}



void CreatTree(Cb C)
{
		
	if(C!=NULL && C->Row < Queens-1)
	{
		if(C->snum == 0)
		{
			for (int i = 0; i < Queens; ++i)
			{
				AddSon(C);
			}

			CreatTree(C->Son);
			CreatTree(C->brother);
		}		
	}
	
}	

/*输出条件
1.数组元素总和 == Queens
2.每列元素和 == 1
3. 两条斜对角线和 ==2
*/
int CountOne(int (*A)[Queens],int n)
{


	int r = 0;
	
	int Fun1(int A[Queens][Queens],int i,int j)
	{
		int la =i;
		int lb =i;
		int ra =j;
		int rb =j;
		int n = 0;
		while(la>=0 && ra>=0)
		{
			n+= A[la][ra];
			la--;
			ra--;
		}	
		while(lb<Queens-1 && rb<Queens-1)
		{
			lb++;
			rb++;
			n+= A[lb][rb];
			
		}
		return n;	
	}
	int Fun2(int A[Queens][Queens],int i,int j)
	{
		int la =i;
		int lb =i;
		int ra =j;
		int rb =j;
		int n = 0;
		while(la>=0 && ra<Queens-1)
		{
			n+= A[la][ra];
			la--;
			ra++;
		}	
		while(lb<Queens-1 && rb>=0)
		{
			n+= A[lb][rb];
			lb++;
			rb--;
			
			
		}
		return n-A[i][j];	
	}
//--------------------------------------------------

	for (int i = 0; i < n; ++i)
	{
		int k = 0;
		int x0 = 0; 
		int x1 = 0; //x0,x1为两条对角线之和 

		for (int j = 0; j < n; ++j)
		{
				
				k+= A[j][i];//列之和
			   
			    	x0 = Fun1(A,i,j);
			    	x1 = Fun2(A,i,j);
			    	if(x0==1&&x1==1)
			    		r+= A[i][j];
			  
			    //r+= A[i][j];
			 
		}
		

		if(k!=1)
			
			return r;
			
			//	printf("%d %d\n",x0,x1);
  		//printf("%d %d\n",x0,x1);
	}
		
		return r;
}

int PrintTree(Cb C)
{
	int n = 0;
	
	if(C != NULL)
	{	Cb node = C->Son;
		Cb b = C->brother;
		
		   if(CountOne(C->board,Queens) == Queens)
		   {
			for (int i = 0; i < Queens; ++i)
			{
				for (int j = 0; j < Queens; ++j)
				{
					//printf("%d ",C->board[i][j]);
					if(C->board[i][j] == 1)
						printf("■ ");
					else
						printf("□ ");
				} 
					printf("\n");
			}
			// printf("\n %d ",CountOne(C->board,Queens));
			// printf(" %d--%d ",C->Row,C->Column);
			//printf("%d ",CountOne(C->board,Queens));
			printf("\n\n");	
			n++;	
		  }
		n+=PrintTree(node);
		n+=PrintTree(b);

	}

	return n;

}




