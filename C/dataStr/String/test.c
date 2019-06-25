#include<stdio.h>
#include"String.h"
#include<stdlib.h>
int main()
{
	STRING s1= IniString();
	STRING s2 = IniString();
	printf("常规模式匹配：\n");
	PM(s1,s2);
	printf("\nKMP算法：\n");
	Kmp(s1,s2);
	return 0;
}
