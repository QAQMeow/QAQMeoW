#include<stdio.h>
#define Queens 3
typedef struct Chessboard
{
	int Row;  //行
	int Column;  //列
	int board[Queens][Queens];
	int snum;
	struct Chessboard* parent; // 父节点
	struct Chessboard* Son; //最后一个子节点
	struct Chessboard* brother; //前一个兄弟
}Chessboard;

typedef struct Chessboard* Cb;


Cb InitTree();

void AddSon(Cb C);

void PrintResult(Cb C);

void CreatTree(Cb C);
void PrintTree(Cb C);