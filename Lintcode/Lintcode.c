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
	public:
	    int digitCounts(int k, int n) 
	    {
	    	int a = 0;
	   		
        	for (int m = 0; m <=n; ++m)
        	{
        		int x = m;
	    		if(x == k)
	    		{	
	    			a++;
	    		}
	    		else if(x>9)
		    	{
			    	int t = 1;
		   			int i = 0;
		   			
		   			//判断位数
		   			while(x/t!=0)
		   			{	
		   				i++;
		   				t =t*10;
		   			}

		   			// for (int j = 1; j < i; ++j)
		   			// {
		   			// 	r = r*10;
		   			// }
		   			
		   			for (int j = 1; j < i; ++j)
		   			{
		   				int r = 10;
		   				int z = x%r;
		   				x = (x-z)/r;
		   				if(x == k)
		   					a++;
		   				if(z == k)
		   					a++;
		   				

		   			}

		    	}
        	}

        	return a;
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

	Question_3 Q3;
	cout << "第3题：计算数字 k 在 0 到 n 中的出现的次数，k 可能是 0~9 的一个值。：\n";
	cout << Q3.digitCounts(2,302) << "\n";
	return 0;
}
