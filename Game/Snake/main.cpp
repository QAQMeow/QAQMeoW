#include "HEAD.h"
using namespace Van;


int main()
{
	
	startup();
	int i = 0;
	while(1)
	{ 
		show();
		updatewithoutInput();
		updatewithInput();
		
	}
	
	
	return 0;
}