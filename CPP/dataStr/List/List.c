#include<iostream>
#include"List.h"

sqlists InitList()
{
	sqlists List = new SqList;
	List->data = new Datatype(Size);
	List->Maxsize = 10;
	List->length = 0;
	return 	List;
}