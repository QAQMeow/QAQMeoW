#include"List.h"
#include<iostream>

int main()
{
	using namespace Meow_van;
	int a = 10;
	linked_List L2;
	L2.Insert(1);
	L2.Insert(2);
	L2.Insert(3);
	L2.Insert(4);
	L2.Insert(5);
	std::cout << L2.End()->a << '\n';
	std::cout << L2.GetItem(1)->a;
	L2.ShowList();
	L2.help();
	L2.Delet(4);
	L2.ShowList();
	return 0;
}