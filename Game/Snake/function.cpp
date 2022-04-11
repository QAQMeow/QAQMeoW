#include"HEAD.h"
using namespace Van;
int Van::Blocks[HEIGHT][WIDTH] = { 0 };
char Van::moveDirection = 'd';
static int isFailure = 0;
void Van::startup()
{
	
	Blocks[HEIGHT / 2][WIDTH / 2] = 1; // �����м仭��ͷ������Ϊ1
	for (int i = 1; i <= 4; i++) //  ��������4��������ֵ����Ϊ2,3,4,5
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
	if (isFailure) //  �����Ϸʧ��
	{
		setbkmode(TRANSPARENT); // ��������͸��    
		settextcolor(RGB(255, 0, 0));// �趨������ɫ
		settextstyle(40, 0, _T("����")); //  �趨���ִ�С����ʽ
		outtextxy(120, 150, _T("��Ϸʧ��")); //  �����������
	}
	FlushBatchDraw();
}

void Van::moveSnake()
{


	int oldTail_i, oldTail_j, oldHead_i, oldHead_j; // ����������洢����β������ͷ����  
	int max = 0; // ���ڼ�¼���ֵ 
	for (int i = 0; i < HEIGHT; i++) 
		for (int j = 0; j < WIDTH; j++) 
			if (Blocks[i][j] > 0) // ����0��ΪС��Ԫ�� 
				Blocks[i][j]++;

	for (int i = 0; i < HEIGHT; i++) //  �����б���
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (max < Blocks[i][j]) //  �����ǰԪ��ֵ��max��
			{
				max = Blocks[i][j]; // ����max��ֵ
				oldTail_i = i; //  ��¼���ֵ�����꣬���Ǿ���β��λ��
				oldTail_j = j; //  
			}
			if (Blocks[i][j] == 2) // �ҵ���ֵΪ2 
			{
				oldHead_i = i; //  ��ֵΪ2ǡ���Ǿ���ͷ��λ��
				oldHead_j = j; //  
			}
		}
	}

	static int newHead_i = oldHead_i; //  �趨�����洢����ͷ��λ��
	static int newHead_j = oldHead_j;

	if (moveDirection == 'a') // �����ƶ�
		newHead_j = oldHead_j - 1;
	else if (moveDirection == 'd') // �����ƶ�
		newHead_j = oldHead_j + 1;
	else if (moveDirection == 'w') // �����ƶ�
		newHead_i = oldHead_i - 1;
	else if (moveDirection == 's') // �����ƶ�
		newHead_i = oldHead_i + 1;
	
	if (newHead_i >= HEIGHT || newHead_i < 0 || newHead_j >= WIDTH || newHead_j < 0
		|| Blocks[newHead_i][newHead_j]>0)
	{
		isFailure = 1; //  ��Ϸʧ��
		return; // ��������
	}


	Blocks[newHead_i][newHead_j] = 1;  // ����ͷλ����ֵΪ1
	Blocks[oldTail_i][oldTail_j] = 0; // ����βλ�ñ�ɿհ�
}

void Van::updatewithoutInput()
{
	if (isFailure) //  �����Ϸʧ�ܣ���������
		return;
	static int waitIndex = 1; // ��̬�ֲ���������ʼ��ʱΪ1
	waitIndex++; // ÿһ֡+1
	if (waitIndex == 10) // �������10��ִ�У�����С��ÿ��10֡�ƶ�һ��
	{
		moveSnake(); //  ����С���ƶ�����
		waitIndex = 1; // �ٱ��1
	}
	Sleep(1);
}
void Van::updatewithInput()
{
	if (kbhit()) // ����а�������
	{
		char input = getch(); // ��ð�������
		if (input == 'a' || input == 's' || input == 'd' || input == 'w') // �����A��S��W
		{
		moveDirection = input; // �趨�ƶ���
		moveSnake(); // �����ƶ�С�ߺ���
		}
	}

}

