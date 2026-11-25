#include "game.h"

void InitBoard(char board[ROWS][COLS], int r, int c, char set)
{
    for (int i = 0; i<r; i++)
    {
        for (int j = 0; j<c; j++)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS], int r, int c)
{
    //打印列号
    printf("   ");
    for (int i = 1; i<=c; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 1; i<=r; i++)
    {
        printf("%d  ", i);
        for (int j = 1; j<=c; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void setmine(char board[ROWS][COLS], int r, int c)
{
    int count = MINE_COUNT;
    while (count)
    {
        int x = rand() % r + 1;
        int y = rand() % c + 1;
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
    return mine[x-1][y-1] + mine[x-1][y] + mine[x-1][y+1] +
           mine[x][y-1]                + mine[x][y+1] +
           mine[x+1][y-1] + mine[x+1][y] + mine[x+1][y+1] - 8 * '0';
}

// 递归展开空白
void OpenBlank(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
    // 1.越界直接返回
    if(x < 1 || x > ROW || y <1 || y > COL)
        return;
    // 2.已经展开过了，返回
    if(show[x][y] != '*')
        return;
    // 3.如果这个位置周围有雷，只填数字，不继续递归扩散
    int n = GetMineCount(mine, x, y);
    if(n > 0)
    {
        show[x][y] = (char)n + '0';
        return;
    }
    // 4.周围0个雷，标记为空白，继续向8个方向递归
    show[x][y] = ' ';
    OpenBlank(mine, show, x-1, y-1);
    OpenBlank(mine, show, x-1, y);
    OpenBlank(mine, show, x-1, y+1);
    OpenBlank(mine, show, x,   y-1);
    OpenBlank(mine, show, x,   y+1);
    OpenBlank(mine, show, x+1, y-1);
    OpenBlank(mine, show, x+1, y);
    OpenBlank(mine, show, x+1, y+1);
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS],int r, int c)
{
    int x, y;
    int win = 0;
    while (win < r * c - MINE_COUNT)
    {
        printf("请输入坐标：");
        scanf("%d %d", &x, &y);
        if (x >= 1 && x <= r && y >= 1 && y <= c)
        {
            if (show[x][y] != '*')
            {
                printf("该坐标已经被排查过，请重新输入\n");
                continue;
            }
            if (mine[x][y] == '1')
            { 
                printf("很遗憾，你踩到雷了，游戏结束！\n");
                DisplayBoard(mine, r, c);
                break;
            }
            else
            {
                OpenBlank(mine, show, x, y);
                //统计已经排开的格子数量
                win = 0;
                for(int i = 1; i <= ROW; i++)
                {
                    for(int j = 1; j <= COL; j++)
                    {
                        if(show[i][j] != '*')
                            win++;
                    }
                }
                DisplayBoard(show, ROW, COL);
                if(win == r*c - MINE_COUNT)
                {
                    printf("恭喜你，排雷成功！\n");
                    DisplayBoard(show, ROW, COL);
                    break;
                }
            }
        }
        else
        {
            printf("输入坐标有误，请重新输入\n");
        }
    }
}

