#pragma once
//ͷ�ļ�����
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//�����
#define ROW 3
#define COL 3
//����������
//��ʼ�����̵ĺ���
void InitBoard(char board[ROW][COL],int row ,int col );
//��ӡ���̵ĺ���
void PrintBoard(char board[ROW][COL], int row, int col);
//�����
void Player(char board[ROW][COL], int row, int col);
//������
void Computer(char board[ROW][COL], int row, int col);
//�ж���Ϸ״̬
char IsWin(char board[ROW][COL],int row,int col);
//�ж��Ƿ�ƽ��
int IsFull(char board[ROW][COL], int row, int col);
//����
int Attack(char board[ROW][COL], int row, int col);
//����
int Defense(char board[ROW][COL], int row, int col);
