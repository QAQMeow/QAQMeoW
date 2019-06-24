#include<stdio.h>
typedef int Point;
typedef struct Node{
	int data;
	Point next;

}Node;  //节点
	
typedef struct List{

	Node node[15];
	int last;                       //链表节点个数
	Point head;			//头节点位置
	Point HeadOfLeftNode;   	//剩余节点头节点
}List;                   

typedef List* Lists;  //链表入口指针

//Initialize list 初始化链表
List IniList();

//Detects if the list is empty 检测列表是否为空
int IsListEmpty(List List);

//Delete the List 删除列表
void DelList(Lists List);

//print 输出
void PrintList(List List);

//Add an item 添加1项(该项来自剩余节点)
void AddItem(Lists List,int n);

//Delete an item which position is n 删除 n 位置上的项
void DelItem(Lists List,int n);

