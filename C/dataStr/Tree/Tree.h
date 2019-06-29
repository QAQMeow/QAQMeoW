#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

typedef struct node* TREE;

//Creat Tree

TREE CreatTree();

//Print Tree

void PrintTree(TREE T);
