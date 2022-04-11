#pragma once
#include<graphics.h>
#include<conio.h>
#include<stdio.h>


namespace Van {
	
	const int BLOCK_SIZE = 20;
	const int HEIGHT = 30;
	const int WIDTH = 40;
	extern int Blocks[HEIGHT][WIDTH]; //  二维数组，用于记录所有的游戏数据
	extern char moveDirection;
	
	void startup(); //初始化
	void updatewithoutInput();
	void updatewithInput();
	void show();
	void moveSnake();
}

#pragma warning(disable:4996)