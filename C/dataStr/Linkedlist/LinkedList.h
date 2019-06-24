#include<stdio.h>

typedef struct Node{
	int data;
	struct Node* next;

}Node;

typedef Node* List;	//指向链表头指针，从该处进入链表


//Initialize list 初始化链表
List IniList();

//Detects if the list is empty 检测列表是否为空
int IsListEmpty(List List);

//Delete the List 删除列表
void CleanList(List List);

//print 输出
void PrintList(List List);

//Add an items position n 在 n 位置添加1项
void AddItem(List List,int n);

//Delete an item which position is n 删除 n 位置上的项
void DelItem(List L,int n);

//Caculate List Items number 计算节点总数
int CacList(List List);

