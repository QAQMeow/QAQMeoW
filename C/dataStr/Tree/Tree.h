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
	int r,n; //根位置和节点个数
}PTree;

//孩子表示

typedef struct{
	
	char data;
	int next;
	int child;
}CTbox;

typedef struct{
	CTbox nodes[MAX_SIZE];
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

//孩子表示树输出孩子
void PrintChild(CTree CT,CTbox box);