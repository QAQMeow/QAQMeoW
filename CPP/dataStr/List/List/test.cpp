#include"List.h"

int main()
{
	using namespace Meow_van;
	std::cout << "Hello World!\n";
	
	List<int> l;
	std::cout << l.Length();
	l.help();
	return 0;
}