#include<stdio.h>
#include<stdlib.h>
#include"E_Queens.h"
#define Queens 3
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
	if(C!=NULL && C->Son != NULL)
	{	
		Cb node  = C->Son;
		Cb p = node;
		while( p!= NULL)
		{
			for (int i = 0; i < Queens; ++i)
			{
				AddSon(p);
			}
			
			p = p->brother;

		}
		// while(node!=NULL)
		// {
		 	//CreatTree(node);
		//if(node->Row<=2)
		if(node->Row<3)
			CreatTree(node);
		// }
		// node= node->brother;
	}
}
void PrintTree(Cb C)
{
	if(C != NULL)
	{	Cb node = C->Son;
		Cb p = node;

		while(p!=NULL)
		{
			for (int i = 0; i < Queens; ++i)
			{
				for (int j = 0; j < Queens; ++j)
				{
					printf("%d ",p->board[i][j]);
				} 
				printf("\n");
			}
			printf("s\n\n");

			
			p = p->brother;
		}
		//if(node!=NULL)
		PrintTree(node);
		
	}
}	