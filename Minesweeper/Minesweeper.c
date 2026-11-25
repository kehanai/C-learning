#include "game.h"

void menu()
{
    printf("---------------------\n");
    printf("--------1.开始游戏--------\n");
    printf("--------0.exit--------\n");
    printf("---------------------\n");

}

void game()
{
    printf("扫雷\n");
    char mine[ROWS][COLS];
    char show[ROWS][COLS];
    // 写函数初始化棋盘
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    // 打印棋盘
    DisplayBoard(show, ROW, COL);
    // DisplayBoard(mine, ROW, COL);
    setmine(mine , ROW, COL);
     DisplayBoard(mine, ROW, COL);
    //排雷
    FindMine(mine, show, ROW, COL);
}

int main()
{
    int input;
    srand((unsigned int)time(NULL));
    do
    {  
        menu();
        printf("请选择：");
        scanf("%d", &input);
        switch (input)
        {
            case 1: game();break;
            case 0: printf("退出游戏\n");break;
            default: printf("选择错误，请重新选择\n");break;
        }
    } while (input);

    system("pause");
    return 0;
}