#include <iostream>
 
using namespace std;
 


class Question_1
{
	//返回输入值之和
public:
 
    int aplusb(int a, int b) 
    {	 
 	   return a+b;
	}
};

class Question_2
{
	//输入一个整数，返回其阶乘后末尾0的个数
public:

	   long long trailingZeros(long long n) {
	   	{
	   		if(n<5)
	   			return 0;

	   		long long i = n;
	   		long long k = 0;

	   		while(i/5!=0)
	   		{
	   			i = i/5;
	   			k = k+i;
	   		}
	   		return k;
	   	}
    }
};

class Question_3
{
	//计算数字 k 在 0 到 n 中的出现的次数，k 可能是 0~9 的一个值。
	    int digitCounts(int k, int n) 
	    {
        	
   		}
};
int main()
{
	Question_1 Q1;
	cout << "第1题：输入1、2,返回输入值和：\n";
	cout << Q1.aplusb(1,2) << "\n";
	
	Question_2 Q2;
	cout << "第2题：输入105,返回其阶乘后末尾0的个数：\n";
	cout << Q2.trailingZeros(105) << "\n";

	return 0;
}
