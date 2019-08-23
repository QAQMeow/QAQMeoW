#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

//双亲表示
typedef struct PTNode{
	char data;
	int parent;
}PTNode;

typedef struct{
	PTNode nodes[MAX_SIZE];
	int r,n;
}PTree;

//孩子表示
typedef struct CTNode{
	int child;
	struct CTNode* next;	
}CTNode;

typedef CTNode* ChildPtr;

typedef struct{
	char data;
	ChildPtr first;
}CTbox;

typedef struct{
	CTbox ndoes[MAX_SIZE];
	int n,r;
}CTree;


//建立双亲表示树
PTree BuildPTree();
//建立孩子表示树
CTree BuildCTree();

//输出双亲表示树
void PrintPTree(PTree Tree);

//输出孩子表示树
void PrintCTree(CTree Tree);