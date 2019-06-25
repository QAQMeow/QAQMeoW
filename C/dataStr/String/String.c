#include<stdio.h>
#include"String.h"
#include<stdlib.h>

//NEXT



//Initialize String 初始化串
STRING IniString()
{
	STRING S =(STRING)malloc(sizeof(String));
	printf("请输入字符串:\n");
	int i =0;
	while(1)
	{
		S->string[i] = getchar();
		if(S->string[i] == '\n')
		break;
		i++;
		if(i==14)
		{
			S->string[i] ='\n';
			printf("超出字符串14个字符限制\n");
			break;
		}
	}
	S->last = i;
	return S;
}

//Print String
void PrintString(STRING string)
{
	int i =0;
	if(string->string[i]=='\n')
	printf("\n字符串为空\n");
	printf("\"");
	while(string->string[i]!='\n')
	{
		printf("%c",string->string[i]);
		i++;
	}
	printf("\"");	


}

//KMP
void Kmp(STRING parent,STRING child)
{
	int p = parent->last;
	int c = child->last;
	int i=0,j=0;
	int next[c+1];
	
	void Next(int next[],STRING child)
	{
		next[0]=0;
		int i =1,j =-1;
		for(i;i<c;i++)
		{	
			if(j==-1||child->string[j]==child->string[i])
			{	j++;
			
				
			}
			else{	
				if(child->string[i]==child->string[0])
				j=1;
				else j=0;
				
			}	
			next[i] = j;	
		}//PMT
		//转换为next
		for(i=c-1;i>0;i--)next[i] = next[i-1];
		next[0]=-1;
		//for(i=0;i<c;i++)printf("%d ",next[i]);
	
		}
 	j=0;i=0;
	
	Next(next,child);
if(p>=c)
	{
		while(i<p)
		{
			
			if(j==-1||parent->string[i]==child->string[j])
			{
				j++;
				i++;	
				if(j==c)
				{	
					break;
				}
			}else
			{
				
				j=next[j];
					
			}
				
		}
		if(i<=p&&j==c)
		{		
			PrintString(child);
			printf(" 在 ");
			PrintString(parent);
			printf(" 中的位置是 %d ",i-j);
			printf("\n");	
		}
		else 
		{
			printf("未在 ");
			PrintString(parent);
			printf(" 找到 ");
			PrintString(child);
			printf("\n");			
		}
	}else {
			printf("子串过长，");
			printf("未在 ");
			PrintString(parent);
			printf(" 找到 ");
			PrintString(child);	
			printf("\n");			
		}		
			
	
}

// pattern matching
void PM(STRING parent,STRING child)
{
	
	int p = parent->last;
	int c = child->last;
	int i=0,j=0;
	if(p>=c)
	{
		while(j<c||i<p)
		{
			
			if(parent->string[i]==child->string[j])
			{
				
				i++;
				j++;	
				if(j==c)
				{	
					break;
				}
			}else
			{
				i=i-j+1;
				j=0;
					
			}
				
		}
		if(i<=p)
		{		
			PrintString(child);
			printf(" 在 ");
			PrintString(parent);
			printf(" 中的位置是 %d ",i-c);
			printf("\n");		
		}
		else 
		{
			printf("未在 ");
			PrintString(parent);
			printf(" 找到 ");
			PrintString(child);			
			printf("\n");			
		}
	}else {
			printf("子串过长，");
			printf("未在 ");
			PrintString(parent);
			printf(" 找到 ");
			PrintString(child);	
			printf("\n");			
		}
}


//delete string
void DelString(STRING string)
{
	for(int i=0;i<MAX;i++)
		string->string[i] = '\n';
}



