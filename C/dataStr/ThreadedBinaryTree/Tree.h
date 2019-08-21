#include<stdio.h>
#include<stdlib.h>

typedef struct Threadnode{
	int data;
	struct Threadnode* left;
	struct Threadnode* right;
	struct Threadnode* pre;
	int ltag;
	int rtag;

}Threadnode;


typedef struct Threadnode* TREE;

TREE InitTree();

TREE CreatTree(TREE Tree);

void PrintTree(TREE T);

//线索二叉树，返回指向第一个节点的指针
TREE ThreadTree(TREE T);
//输出线索二叉树
void PrintTT(TREE T);