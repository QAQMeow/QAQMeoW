#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>
#include<ncurses.h>
// 4*4 16宫格

int A[4][4] = { 0 };

int empty;

int old_y, old_x;

void draw();//绘制游戏界面
void play();//游戏运行
void init();//初始化
void draw_one(int y, int x);//绘制单个数字
void cnt_value(int* new_y, int* new_x);
int game_over();//结束
int cnt_one(int y, int x);


int main()
{
	init();
	play();
	endwin();// 关闭窗口

	return 0;

}


void init()
{
	initscr();
	cbreak();
	noecho();
	cur_set(0);

	empty = 15;
	srand(time(0));
	x = rand() % 4;
	y = rand() % 4;
	A[y][x] = 2;
	draw();
}





