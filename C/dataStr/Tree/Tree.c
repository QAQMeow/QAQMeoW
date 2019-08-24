#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"
#define MAX_SIZE 100
/*
树结构：
          R
       /  |  \
	  A   B   C
	 / \    / | \ 
    D   E  G  H  K
*/

//建立双亲表示树
PTree BuildPTree()
{
	PTree PT;
	PT.n = 0;	//	节点个数
	PT.r = 0; 	//	树根位置在0
	char c;

	while(PT.n == 0)
	{
		printf("请输入树根元素(#为空):\n");
		scanf("%c",&c);
		if(c!='#')
		{
			PT.nodes[PT.r].data = c;
			PT.nodes[PT.r].parent = -1;
			PT.n++;
		}
		else return PT;
	
	}	
		int p = 0;		//双亲节点
		
		
			for(int i = 1;i < MAX_SIZE;i++)
			{
				int j = 0;
				printf("请输入%c子节点元素(#为空,@添加下一层)：\n",PT.nodes[p].data);
				getchar();
				scanf("%c",&c);
				if(c != '#')
				{	

					if(c!='@'){
						PT.nodes[i].data = c;
						PT.nodes[i].parent = p;	
						PT.n++;
						j++;
					}
				}
				else
				break;

				if(c == '@')
				{
					i--;
					p++;
				}
				
			}


	return PT;

}
//建立孩子表示树
CTree BuildCTree()
{
	CTree CT;
	CT.n = 0;
	CT.r = 0;
	char c;
	for(int i = CT.n;i<MAX_SIZE;i++)
	{
		CT.nodes[i].data = 0;
		CT.nodes[i].child = -1;
		CT.nodes[i].next = -1;
	}
			printf("请输入根节点：\n");
			scanf("%c",&c);
			getchar();
	if(c == '#')
	{
		return CT;
	}
	else
	{
		CT.nodes[0].data = c;

		CT.n++;
	}

	int i = 1;
	int p = 0;
	while(CT.nodes[p].data != 0)
	{

		char T;
		printf("%c 是否有子节点(Y/N)：\n",CT.nodes[p].data);
		scanf("%c",&T);
		getchar();
		
		if(T !='N')
		{
			if(CT.nodes[p].child == -1)
			{
				CT.nodes[p].child = i;
			}

			printf("请输入子节点：\n");
			scanf("%c",&c);
			getchar();
			CT.nodes[i].data = c;
			CT.n++;
			CT.nodes[i-1].next = i; 
			
			i++;
			

		}else
		{
			p++;
			CT.nodes[p].next = -1;
		}

	}
	return CT;

}
//输出双亲表示树
void PrintPTree(PTree Tree)
{
	if(Tree.n == 0)
		printf("树为空\n");
	else
		printf("data  parent\n");
		for(int i = 0;i<Tree.n+2;i++)
		printf(" %c       %d \n",Tree.nodes[i].data,Tree.nodes[i].parent);
}

//输出孩子表示树
void PrintCTree(CTree Tree)
{

	for(int i = 0;i < Tree.n;i++)
	printf("|%d| ",Tree.nodes[i].next);
}

//孩子表示树输出孩子
void PrintChild(CTree CT,CTbox box)
{
	int T = box.child;
	
	while(T != -1)
		{
			printf("%c ",CT.nodes[T].data);
			T = CT.nodes[T].next;
		}
}