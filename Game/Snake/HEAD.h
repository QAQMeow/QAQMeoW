#pragma once
#include<graphics.h>
#include<conio.h>
#include<stdio.h>


namespace Van {
	
	const int BLOCK_SIZE = 20;
	const int HEIGHT = 30;
	const int WIDTH = 40;
	extern int Blocks[HEIGHT][WIDTH]; //  ��ά���飬���ڼ�¼���е���Ϸ����
	extern char moveDirection;
	
	void startup(); //��ʼ��
	void updatewithoutInput();
	void updatewithInput();
	void show();
	void moveSnake();
}

#pragma warning(disable:4996)