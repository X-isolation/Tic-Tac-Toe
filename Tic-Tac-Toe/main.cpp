#define _CRT_SECURE_NO_WARNINGS	
#include "game.h"

void menu()
{
	printf("******************************\n"); 
	printf("******   ��1.��ʼ��Ϸ   ******\n"); 
	printf("******   ��0.������Ϸ   ******\n"); 
	printf("******************************\n");

}
void game() 
{
	char ret = 0;
	char board[ROW][COL];
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	PrintBoard(board, ROW, COL);
	int tmp = rand() % 2;
	while (1)
	{
		if (0 == tmp)
		{
			//�����
			Player(board, ROW, COL);
			PrintBoard(board, ROW, COL);
			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
				break;
			//������+�ж�
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
			//������
			Computer(board, ROW, COL);
			PrintBoard(board, ROW, COL);
			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
				break;
			//�����
			Player(board, ROW, COL);
			PrintBoard(board, ROW, COL);
			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
				break;

		}
	}
	if ('*' == ret)
	{
		printf("��Ӯ�ˣ�\n");
	}
	else if ('#' == ret)
	{
		printf("�����ˣ�\n");
	}
	else
		printf("ƽ��\n");
}
int main()
{
	srand((unsigned) time(NULL));
	int input = 0;
	do
	{
		
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}
