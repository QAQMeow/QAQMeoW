#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>
#include<ncurses.h>
// 4*4 16����

int A[4][4] = { 0 };

int empty;

int old_y, old_x;

void draw();//������Ϸ����
void play();//��Ϸ����
void init();//��ʼ��
void draw_one(int y, int x);//���Ƶ�������
void cnt_value(int* new_y, int* new_x);
int game_over();//����
int cnt_one(int y, int x);


int main()
{
	init();
	play();
	endwin();// �رմ���

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





