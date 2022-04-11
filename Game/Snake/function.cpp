#include"HEAD.h"
using namespace Van;
int Van::Blocks[HEIGHT][WIDTH] = { 0 };
char Van::moveDirection = 'd';
static int isFailure = 0;
void Van::startup()
{
	
	Blocks[HEIGHT / 2][WIDTH / 2] = 1; // 画面中间画蛇头，数字为1
	for (int i = 1; i <= 4; i++) //  向左依次4个蛇身，数值依次为2,3,4,5
		Blocks[HEIGHT / 2][WIDTH / 2 - i] = i + 1;

	initgraph(WIDTH * BLOCK_SIZE, HEIGHT * BLOCK_SIZE);
	setlinecolor(RGB(200, 200, 200));
	BeginBatchDraw();
}

void Van::show()
{
	cleardevice();
	
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (Blocks[i][j] > 0)
				setfillcolor(HSVtoRGB(Blocks[i][j] * 10, 0.9, 1));
			else
				setfillcolor(RGB(150, 150, 150));

			fillrectangle(j * BLOCK_SIZE, i * BLOCK_SIZE, (j + 1) * BLOCK_SIZE, (i + 1) * BLOCK_SIZE);
		}
	}
	if (isFailure) //  如果游戏失败
	{
		setbkmode(TRANSPARENT); // 文字字体透明    
		settextcolor(RGB(255, 0, 0));// 设定文字颜色
		settextstyle(40, 0, _T("宋体")); //  设定文字大小、样式
		outtextxy(120, 150, _T("游戏失败")); //  输出文字内容
	}
	FlushBatchDraw();
}

void Van::moveSnake()
{


	int oldTail_i, oldTail_j, oldHead_i, oldHead_j; // 定义变量，存储旧蛇尾、旧蛇头坐标  
	int max = 0; // 用于记录最大值 
	for (int i = 0; i < HEIGHT; i++) 
		for (int j = 0; j < WIDTH; j++) 
			if (Blocks[i][j] > 0) // 大于0的为小蛇元素 
				Blocks[i][j]++;

	for (int i = 0; i < HEIGHT; i++) //  对行列遍历
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (max < Blocks[i][j]) //  如果当前元素值比max大
			{
				max = Blocks[i][j]; // 更新max的值
				oldTail_i = i; //  记录最大值的坐标，就是旧蛇尾的位置
				oldTail_j = j; //  
			}
			if (Blocks[i][j] == 2) // 找到数值为2 
			{
				oldHead_i = i; //  数值为2恰好是旧蛇头的位置
				oldHead_j = j; //  
			}
		}
	}

	static int newHead_i = oldHead_i; //  设定变量存储新蛇头的位置
	static int newHead_j = oldHead_j;

	if (moveDirection == 'a') // 向左移动
		newHead_j = oldHead_j - 1;
	else if (moveDirection == 'd') // 向右移动
		newHead_j = oldHead_j + 1;
	else if (moveDirection == 'w') // 向上移动
		newHead_i = oldHead_i - 1;
	else if (moveDirection == 's') // 向下移动
		newHead_i = oldHead_i + 1;
	
	if (newHead_i >= HEIGHT || newHead_i < 0 || newHead_j >= WIDTH || newHead_j < 0
		|| Blocks[newHead_i][newHead_j]>0)
	{
		isFailure = 1; //  游戏失败
		return; // 函数返回
	}


	Blocks[newHead_i][newHead_j] = 1;  // 新蛇头位置数值为1
	Blocks[oldTail_i][oldTail_j] = 0; // 旧蛇尾位置变成空白
}

void Van::updatewithoutInput()
{
	if (isFailure) //  如果游戏失败，函数返回
		return;
	static int waitIndex = 1; // 静态局部变量，初始化时为1
	waitIndex++; // 每一帧+1
	if (waitIndex == 10) // 如果等于10才执行，这样小蛇每隔10帧移动一次
	{
		moveSnake(); //  调用小蛇移动函数
		waitIndex = 1; // 再变成1
	}
	Sleep(1);
}
void Van::updatewithInput()
{
	if (kbhit()) // 如果有按键输入
	{
		char input = getch(); // 获得按键输入
		if (input == 'a' || input == 's' || input == 'd' || input == 'w') // 如果是A、S、W
		{
		moveDirection = input; // 设定移动方
		moveSnake(); // 调用移动小蛇函数
		}
	}

}

