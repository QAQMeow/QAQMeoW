#include"List.h"
#include<iostream>

int main()
{
	using namespace Meow_van;
	int a = 10;
	con_List L1 = con_List(10);
	//std::cout << L1.Length()<<'\n';
	L1.Insert(102);
	L1.Insert(103);
	L1.Insert(104);
	L1.Insert(105);
	L1.Insert(106);
	L1.cShowList();
	
	return 0;
}