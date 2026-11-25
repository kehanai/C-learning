#pragma once
#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define MINE_COUNT 10

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int r, int c, char set);
// 打印棋盘
void DisplayBoard(char board[ROWS][COLS], int r, int c);
//布置雷
void setmine(char board[ROWS][COLS], int r, int c);
//统计周围雷
int GetMineCount(char mine[ROWS][COLS], int x, int y);
//空白递归展开
void OpenBlank(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
//排雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c);
void menu();
void game();
