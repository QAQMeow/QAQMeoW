#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"
#include<string.h>
#include <stdbool.h>
#define MAX 15
#define STRINGLENGTH 100
// Initialize Tree
TREE InitTree()
{
	TREE T;
	T= (TREE)malloc(sizeof(node));
	T = NULL;
	T = CreatTree(T);
	return T;
}

//Creat Tree
int level =1;
TREE CreatTree(TREE Tree)
{ 
	
	TREE T;
	T= (TREE)malloc(sizeof(node));
	char data[MAX];
	printf("请输入数据(#为空,输入叶节点后须输入两个#)：\n");
	scanf("%s",data);
	
	if(strcmp(data,"#")==0)
		T = NULL;
	else
	{
		if(Tree == NULL)
		{
			T->level = 1;
			T->pre= NULL;
		}
		else
		{
			T->pre = Tree;	
			T->level = Tree->level+1;	
		}
		T->data = atoi(data);
		T->left  = CreatTree(T);
		T->right = CreatTree(T);	
	}

	return T;
}

//Print Tree

void PrintTree(TREE T)
{
	if(T==NULL)
	{
		return;
	
	}
	else
	{
		PrintTree(T->left);
		printf("  %d    %d \n",T->data,T->level);
		PrintTree(T->right);		
	}
	
}

//Search Tree

void SearchTree(TREE T,int n)
{
	if(T==NULL)
	{
		return;	
	}	
	else
	{
		SearchTree(T->left,n);
		SearchTree(T->right,n);
		if(T->data == n)
			printf("  %d    %d \n",T->data,T->level);
		else
			return;
	}
}

void Num(TREE T,int* c)
{

	if(T==NULL)
	{
		return;
	
	}
	else
	{
		Num(T->left,c);
		*c+=1;
		Num(T->right,c);		
	}

}
//节点个数
int NumNode(TREE T)
{
	int n =0;
	Num(T,&n);
	return n;

}

// 层序遍历

void PrintTree_c1(TREE T)
{
	int n = NumNode(T);
	int* p = (int*)malloc(n*sizeof(int));
	int* t = p;
	int* l = p;
	//*****************************************
	//计算树的深度
 	int levelMax = 0;
	if(T!=NULL){
		levelMax = T->level;
		void CacuLevel(TREE T)
		{
			if(levelMax<=T->level)	
			levelMax = T->level;
			if(T->left!=NULL)
			CacuLevel(T->left);
			if(T->right!=NULL)
			CacuLevel(T->right);	
		}
		CacuLevel(T);
	}
	//*****************************************

	for(int l = 1;l<=levelMax;l++)
	{
		void readdata(TREE T)
		{
			if(l==T->level)	
			{*t  = T->data;
			t++;}
			if(T->left!=NULL)
			readdata(T->left);
			if(T->right!=NULL)
			readdata(T->right);	
		}
		readdata(T);	
	}	

	for(int i = 0;i<n;i++)
		printf("%d ",p[i]);

}

//层序遍历
// 初始化一个队列，先将根节点入队，然后出队，访问该结点，若有左子树，则将左子树入队，若有右子树，将右子树入队，然后出队，对出队节点访问
	typedef struct Queue
		{
			struct Node* Entrance;
			struct Node* Exit;	
		}Queue;

	
	typedef struct Node
	{
		node* DATA;
		struct Node* pre;
		struct Node* next;
	}Node;

	Queue IniQueue()
	{
		Queue Q;
		Q.Entrance =NULL;
		Q.Exit = NULL;
		return Q;
	}
	//Add 
	void InQueue(Queue* Q,node* T)
	{
		Node* node = (Node*)malloc(sizeof(Node));
		node->pre = NULL;
		node->DATA = T;
		if(Q->Entrance == NULL)
		{	node->next = Q->Entrance;
			Q->Entrance = node;
			Q->Exit = node;	
			
		}
		else
		{	Q->Entrance->pre = node;
			node->next = Q->Entrance;
			Q->Entrance = node;
					
		}

	}

	//out
	node* OutQueue(Queue* Q)
	{
		node* N = (node*)malloc(sizeof(node));
		
		if(Q->Exit== NULL)
		{
			printf("Queue is Empty,Use method :InQueue(Queue* queue) to add an Item\n");
			return NULL;
		}
		else if(Q->Exit->pre == NULL)
		{
			
			N =  Q->Exit->DATA;
			//printf("%d ",Q->Exit->DATA->data);
			
			Q->Entrance = Q->Exit->pre;
			Q->Exit = Q->Exit->pre;
		}	
		else 
		{	
			N = Q->Exit->DATA;
			//printf("%d ",Q->Exit->DATA->data);
			Q->Exit->pre->next = Q->Exit->next;
			Q->Exit = Q->Exit->pre;

		}
		return N;
	}

	//IsQueueEmpty
	int IsQEmpty(Queue* Q)
	{
		return Q->Entrance == NULL;

	}


void PrintTree_c(TREE T)
{
	node* Node  = (node*)malloc(sizeof(node));
	Queue Q = IniQueue();
	Queue* q = &Q;
	Node = T;

	InQueue(&Q,Node);
	while(!IsQEmpty(&Q))
	{
		
		Node = OutQueue(&Q);
		printf("%d ",Node->data);
		if(Node->left != NULL)
		{
			InQueue(&Q,Node->left);
		}
		if(Node->right != NULL)
		{
			InQueue(&Q,Node->right);
		}
		
	}

}



//赫夫曼(Huffman)树(最优二叉树)
void HuffmanTree()
{
	printf("请输入字符串：\n");
	char S[STRINGLENGTH];
	scanf("%s",S);

	int Slen = strlen(S);

//建一个队列储存字符的Huffman码
	typedef struct Box
	{
		int code;
		struct Box* pre;
		struct Box* next;
	}Box;

	typedef struct Box* B;

	typedef struct LINE
	{
		struct Box* exit;
		struct Box* enter;
	
	}LINE;
	typedef struct LINE* LN;


	LINE readL(LINE L,int x)
	{
		if(L.enter == NULL)
		{
			//printf("ERROR1 ");
		//	L = (LINE*)malloc(sizeof(LINE));
			B b =(Box*)malloc(sizeof(Box));
			b->next = NULL;
			b->pre = NULL;
			b->code = x;
			L.exit  = b;
			L.enter = b;
		return L;
		}
			else
		{
			B NT = (Box*)malloc(sizeof(Box));
			NT->code = x;
			NT->next = NULL;
			L.enter->next = NT;
			NT->pre = L.enter;
			L.enter = NT;
		return L;
		}
	}
	void printL(LINE L) 
	{
		if(L.enter != NULL)
		{
			B b = L.enter;
	
			while(b != NULL)
			{
				printf("%d",b->code);
				b = b->pre;
			}
			
		//printf(" ");
		
		}
			else if(L.exit == NULL)

			printf(" ");
		
	}
//-------------------------------------------------------
	typedef struct HTNode{
		
		char C;
		int weight;

		int position;  //相对父节点位置 左为1 右为0
		LINE Code;
		struct HTNode* left;
		struct HTNode* right;

	}HTNode;

	typedef struct HTNode* HT;




	HT Str = (HTNode*)malloc(sizeof(HTNode));
	int n = 0;	// 记录不同的字符总个数
	for(int i = 0;i < Slen;i++)
	{
		int j = 0;
		for(j; j <n;j++)
		{
			if(S[i] == Str[j].C)
			{
				Str[j].weight++;
				break;
			}
		}
		if(j == n)
		{
			Str[j].C = S[i];
			Str[j].weight++;
			n++;
		}
			
	}
	
	
	//根据权重从小到大排序
	for(int i  = 0;i < n - 1;i++)
	{
		for(int j = 0;j < n-1-i;j++)
		{
			if(Str[j].weight >= Str[j+1].weight)
			{
				HTNode T;
	
				T.C = Str[j].C;
				T.weight = Str[j].weight;
				T.left = Str[j].left;
				T.right = Str[j].right;

				Str[j].C = Str[j+1].C;
				Str[j].weight = Str[j+1].weight;
				Str[j].left = Str[j+1].left;
				Str[j].right = Str[j+1].right;

				Str[j+1].C = T.C;
				Str[j+1].weight = T.weight;
				Str[j+1].left = T.left;
				Str[j+1].right = T.right;
			}
		}
	}
	
	printf("字符 权重(个数)\n");
	for(int i = 0;i < n;i++)
	printf(" %c     %d\n",Str[i].C,Str[i].weight);
	

	HT Ss = Str;
	for(int i = 0;i<n;i++)
	{

		Ss->right = NULL;
		Ss->left = NULL;

		Ss++;
	}

printf("\n");
	HT CT(){
		
		void IntoNode(HT HL,int n)
	{
		if(HL != NULL)
		{	

			HL->Code = readL(HL->Code,n);
			IntoNode(HL->left,n);
			IntoNode(HL->right,n);
			
		}
	}

		if(n==1){
			HT Hft = (HTNode*)malloc(sizeof(HTNode));
	
			Str[0].position = 1;
		
		
			Hft->right = NULL;
			Hft->left = Str;
		
			IntoNode(Hft,1);
			return Hft;
		}
		else if(n==2){
			HT Hft = (HTNode*)malloc(n*sizeof(HTNode));
			HT Tc = (HTNode*)malloc(sizeof(HTNode));
			Str[0].position = 1;
			Str[1].position = 0;
			Tc->left = Str;
			IntoNode(Tc->left,1);
			
			Tc->right = Str+1;
			Hft++;
			IntoNode(Tc->right,0); 
		
			Hft = Tc;	

			return Hft;
		
		}
		else if(n> 2){
			HT Hft = (HTNode*)malloc(n*sizeof(HTNode));
			HT Tc = (HTNode*)malloc(sizeof(HTNode));
			Str[0].position = 1;
			Str[1].position = 0;
			Tc->left = Str;
				IntoNode(Tc->left,1);
			Tc->right = Str+1;
				IntoNode(Tc->right,0);
			Tc->weight = Str[0].weight+Str[1].weight;
			Hft++;
			Hft = Tc;

			for(int i = 2;i<n;i++)
			{	
				HT T = (HTNode*)malloc(sizeof(HTNode));
				
				if(Hft->weight <= Str[i].weight)
					{	
						Hft->position = 1;
						Str[i].position = 0; 
						T->left= Hft;
						IntoNode(T->left,1);
						T->right = Str+i;
						IntoNode(T->right,0);
					}
				else	
					{
						Hft->position = 0;
						Str[i].position = 1;
						T->left = Str+i;
						IntoNode(T->left,1);
						T->right = Hft;
						IntoNode(T->right,0);
					}
					T->weight = Str[i].weight+Hft->weight;
				
				Hft++;
				Hft = T;	

			}

			return Hft;
		}
		else return NULL;
	}
	HT HFT = CT();

	// void printHFT(HT HL)
	// {
	// 	if(HL != NULL)
	// 	{	
	// 		//printf("%d -- %c\n",HL->weight,HL->C);
	// 		//if(HL->IsL == 1)
	// 		 printf("%c   ",HL->C);
	// 		printL(HL->Code);
	// 		 printf("\n");
	// 		 printHFT(HL->left);
	// 		 printHFT(HL->right);
			
	// 	}

	// }
 // 	printHFT(HFT);

printf("字符  编码	\n");
	for(int i = 0;i<n;i++)
	{
		printf("%-6c",Str[i].C);
		printL(Str[i].Code);
		printf("\n");
	}
	char S1[STRINGLENGTH];
	printf("请输入仅包含上面显示字符 的字符串：\n");
	scanf("%s",S1);
	printf("字符串：%s\n编码：",S1);
for(int i = 0;i<strlen(S1);i++)
{
	for(int j = 0;j<n;j++)
	{	if(S1[i] == Str[j].C)
			
			printL(Str[j].Code);
	}

}
printf("\n");

}

 