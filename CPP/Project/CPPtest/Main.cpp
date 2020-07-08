#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

namespace Fzh
{
	double fzh = 1.1;
}
double fzh = 1.2;
int main()
{	
	using namespace Fzh;
	Fzh::fzh = 11.2;
	cout << ::fzh;
	cout << '\n' << Fzh::fzh;
	return 0;

}
