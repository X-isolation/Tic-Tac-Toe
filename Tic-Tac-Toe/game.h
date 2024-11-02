#pragma once
//头文件引用
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//定义宏
#define ROW 3
#define COL 3
//函数的声明
//初始化棋盘的函数
void InitBoard(char board[ROW][COL],int row ,int col );
//打印棋盘的函数
void PrintBoard(char board[ROW][COL], int row, int col);
//玩家走
void Player(char board[ROW][COL], int row, int col);
//电脑走
void Computer(char board[ROW][COL], int row, int col);
//判断游戏状态
char IsWin(char board[ROW][COL],int row,int col);
//判断是否平局
int IsFull(char board[ROW][COL], int row, int col);
//进攻
int Attack(char board[ROW][COL], int row, int col);
//防守
int Defense(char board[ROW][COL], int row, int col);
