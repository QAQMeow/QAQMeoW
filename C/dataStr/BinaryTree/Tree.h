#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	int level;
	struct node* left;
	struct node* right;
	struct node* pre;
}node;

typedef struct node* TREE;
// Initialize Tree
TREE InitTree();

//Creat Tree
TREE CreatTree(TREE Tree);

//Print Tree //中序遍历

void PrintTree(TREE T);


//Search Tree
void SearchTree(TREE T,int n);

// Print Tree 层序遍历
void PrintTree_c(TREE T);

//节点个数
int NumNode(TREE T);
void Num(TREE T,int* c);

// Print Tree 层序遍历
void PrintTree_c1(TREE T);

//赫夫曼(Huffman)树(最优二叉树)
void HuffmanTree();