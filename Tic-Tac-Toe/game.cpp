#define _CRT_SECURE_NO_WARNINGS	
#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}
void Player(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
		printf("玩家走\n");
		printf("请输入坐标：");
		scanf("%d %d", &x, &y);


		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新选择：");
			}
		}
		else
		{
			printf("坐标非法，重新输入\n");
		}
	}
}
void Computer(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("电脑走：\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i, j;
	//判断行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
		{
			return board[i][1];
		}
	}
	//判断列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
		{
			return board[1][i];
		}
	}
	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')
	{
		return board[1][1];
	}
	if (IsFull(board, row, col))
	{
		return 'Q';
	}
	else
	{
		return 'C';
	}
}
int IsFull(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
int Attack(char board[ROW][COL], int row, int col)
{
	int q = 0;
	int i = 0;
	//判断行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == '#' && board[i][2] == ' ')
		{
			board[i][2] = '#';
			q = 1;
			return q;
		}
		else if (board[i][0] == board[i][2] && board[i][0] == '#' && board[i][1] == ' ')
		{
			board[i][1] = '#';
			q = 1;
			return q;
		}
		else if (board[i][1] == board[i][2] && board[i][1] == '#' && board[i][0] == ' ')
		{
			board[i][0] = '#';
			q = 1;
			return q;
		}
	}
	//判断列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == '#' && board[2][i] == ' ')
		{
			board[2][i] = '#';
			q = 1;
			return q;
		}
		else if (board[0][i] == board[2][i] && board[0][i] == '#' && board[1][i] == ' ')
		{
			board[1][i] = '#';
			q = 1;
			return q;
		}
		else if (board[2][i] == board[1][i] && board[1][i] == '#' && board[0][i] == ' ')
		{
			board[0][i] = '#';
			q = 1;
			return q;
		}
	}
	//判断主对角线
	if (board[0][0] == board[1][1] && board[0][0] == '#' && board[2][2] == ' ')
	{
		board[2][2] = '#';
		q = 1;
		return q;
	}
	else if (board[0][0] == board[2][2] && board[0][0] == '#' && board[1][1] == ' ')
	{
		board[1][1] = '#';
		q = 1;
		return q;
	}
	else if (board[2][2] == board[1][1] && board[1][1] == '#' && board[0][0] == ' ')
	{
		board[0][0] = '#';
		q = 1;
		return q;
	}
	//判断副对角线
	else if (board[0][2] == board[1][1] && board[0][2] == '#' && board[2][0] == ' ')
	{
		board[2][0] = '#';
		q = 1;
		return q;
	}
	else if (board[0][2] == board[2][0] && board[0][2] == '#' && board[1][1] == ' ')
	{
		board[1][1] = '#';
		q = 1;
		return q;
	}
	else if (board[2][0] == board[1][1] && board[2][0] == '#' && board[0][2] == ' ')
	{
		board[0][2] = '#';
		q = 1;
		return q;
	}
	return q;//无需进攻
}
int Defense(char board[ROW][COL], int row, int col)
{
	int q = 0;
	int i = 0;
	//判断行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == '*' && board[i][2] == ' ')
		{
			board[i][2] = '#';
			q = 1;
			return q;
		}
		else if (board[i][0] == board[i][2] && board[i][0] == '*' && board[i][1] == ' ')
		{
			board[i][1] = '#';
			q = 1;
			return q;
		}
		else if (board[i][1] == board[i][2] && board[i][1] == '*' && board[i][0] == ' ')
		{
			board[i][0] = '#';
			q = 1;
			return q;
		}
	}
	//判断列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == '*' && board[2][i] == ' ')
		{
			board[2][i] = '#';
			q = 1;
			return q;
		}
		else if (board[0][i] == board[2][i] && board[0][i] == '*' && board[1][i] == ' ')
		{
			board[1][i] = '#';
			q = 1;
			return q;
		}
		else if (board[2][i] == board[1][i] && board[1][i] == '*' && board[0][i] == ' ')
		{
			board[0][i] = '#';
			q = 1;
			return q;
		}
	}
	//判断主对角线
	if (board[0][0] == board[1][1] && board[0][0] == '*' && board[2][2] == ' ')
	{
		board[2][2] = '#';
		q = 1;
		return q;
	}
	else if (board[0][0] == board[2][2] && board[0][0] == '*' && board[1][1] == ' ')
	{
		board[1][1] = '#';
		q = 1;
		return q;
	}
	else if (board[2][2] == board[1][1] && board[1][1] == '*' && board[0][0] == ' ')
	{
		board[0][0] = '#';
		q = 1;
		return q;
	}
	//判断副对角线
	else if (board[0][2] == board[1][1] && board[0][2] == '*' && board[2][0] == ' ')
	{
		board[2][0] = '#';
		q = 1;
		return q;
	}
	else if (board[0][2] == board[2][0] && board[0][2] == '*' && board[1][1] == ' ')
	{
		board[1][1] = '#';
		q = 1;
		return q;
	}
	else if (board[2][0] == board[1][1] && board[2][0] == '*' && board[0][2] == ' ')
	{
		board[0][2] = '#';
		q = 1;
		return q;
	}
	return q;
}

