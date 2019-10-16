#include<iostream>
#define Size 10

typedef int Datatype;

typedef struct SqList
{
	Datatype *data;
	int Maxsize, length;
}SqList;

typedef SqList* sqlists;
sqlists InitList();