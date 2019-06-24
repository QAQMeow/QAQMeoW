#include<stdio.h>
#include<stdlib.h>

typedef struct List{
	union {
	int i;
	float f;
	double d;
	char c;
	}Data[10];

	int datatype;
	int last;                  //last 为存入数据最后的位置
	struct List* L;
}List;                                 //建立一个可容纳10个数据的List


//Initialize List 初始化List
List IniList(int x,int t);

//print 输出
void PrintList(List* list);

//Add a item in position n 在 n 位置添加一项
void AddItem(List* list,int n);

//Delete a item which position is n 删除 n 位置上的项
void DelItem(List* list,int n);

//Delete the List 删除列表
void DelList(List* list);

//Detects if the list is empty 检测列表是否为空
int IsListEmpty(List* list);



