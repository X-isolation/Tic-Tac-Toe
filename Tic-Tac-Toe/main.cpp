#define _CRT_SECURE_NO_WARNINGS	
#include "game.h"

void menu()
{
	printf("******************************\n"); 
	printf("******   按1.开始游戏   ******\n"); 
	printf("******   按0.结束游戏   ******\n"); 
	printf("******************************\n");

}
void game() 
{
	char ret = 0;
	char board[ROW][COL];
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	PrintBoard(board, ROW, COL);
	int tmp = rand() % 2;
	while (1)
	{
		if (0 == tmp)
		{
			//玩家走
			Player(board, ROW, COL);
			PrintBoard(board, ROW, COL);
			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
				break;
			//电脑走+判断
			int a = Attack(board, ROW, COL);
			if (0 == a)
			{
				int d = Defense(board, ROW, COL);
				if (0 == d)
				{
					Computer(board, ROW, COL);
					PrintBoard(board, ROW, COL);
				}
				else
				{
					PrintBoard(board, ROW, COL);
				}
			}
			else
			{
				PrintBoard(board, ROW, COL);
			}
			ret = IsWin(board, ROW, COL);
			
			if (ret != 'C')
				break;
		}
		else
		{
			//电脑走
			Computer(board, ROW, COL);
			PrintBoard(board, ROW, COL);
			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
				break;
			//玩家走
			Player(board, ROW, COL);
			PrintBoard(board, ROW, COL);
			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
				break;

		}
	}
	if ('*' == ret)
	{
		printf("你赢了！\n");
	}
	else if ('#' == ret)
	{
		printf("你输了！\n");
	}
	else
		printf("平局\n");
}
int main()
{
	srand((unsigned) time(NULL));
	int input = 0;
	do
	{
		
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("游戏开始\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);
	return 0;
}
