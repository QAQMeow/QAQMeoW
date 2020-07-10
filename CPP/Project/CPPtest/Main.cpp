#include<iostream>
#include<cstring>
#include<vector>
#include"test.h"
using namespace std;


int main()
{	
	Stock s1 = Stock("S1",2,3.0);
	Stock s2 = Stock("S2",4,0.5);
	s1.show();
	s2.show();
	Stock Topval =  s1.topval(s2);
	Topval.show();
	return 0;

}
