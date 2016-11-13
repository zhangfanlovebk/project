//三子棋
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char arr[3][3] = { 0 }; //直接定义外部变量所有的函数可以直接使用 因为考虑到棋盘大小是固定的
int size = 9;           //棋盘大小固定  每下一个子都会使可以下子的容量-1
void chessboard()       //打印棋盘
{
    int i = 0, j = 0;
    printf("   |   |   \n");
    for (i = 0; i < 3; i++)
    {
        printf("_%c_|_%c_|_%c_\n", arr[i][0], arr[i][1], arr[i][2]);//棋盘对应位置下棋
        if (i < 2)
            printf("   |   |   \n");
    }
}

void player()       //玩家下棋
{
    int m = 0, n = 0;
    printf("玩家(@ 输入位置信息，以空格隔开)：");      //输入的是对应的坐标   
    scanf_s("%d %d", &m, &n);      //玩家输入的坐标必须在范围内并且不能是被下过的地方
    if (m<1 || m>3 || n<1 || n>3 || arr[m - 1][n - 1] != ' ')
    {
        printf("这个位置不可使用!\n"); //如果不符合要求则继续调用这个函数
        player();
    }
    else
    {
        arr[m - 1][n - 1] = '@';   //将棋子放入相应的内容 棋盘容量-1
        size--;
    }
}

void computer()                 //电脑下棋
{
    int m = 0, n = 0;
    printf("电脑(#):\n");
    srand(time(NULL));       //电脑的坐标是随机产生的  以时间为种子
    m = rand() % 3;          //对3取余产生0-2的随机数赋给数组下标
    n = rand() % 3;
    while (arr[m][n] != ' ') //如果产生的坐标不符合要求则循环产生 （效率比较低）
    {
        m = rand() % 3;
        n = rand() % 3;
    }
    arr[m][n] = '#';               //操作后容量-1
    size--;
}

int winner()   //判断获胜者
{              //虽然代码多但是效率高  本来想采用函数比较考虑到效率太低就放弃了
    if ((arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] && arr[0][2] == '@') ||
        (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && arr[1][2] == '@') ||
        (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && arr[2][2] == '@') ||
        (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[2][0] == '@') ||
        (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && arr[2][1] == '@') ||
        (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && arr[2][2] == '@') ||
        (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] == '@') ||
        (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] == '@'))

        return 1;                     //玩家获胜
    else if
        (
        (arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2] && arr[0][2] == '#') ||
        (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2] && arr[1][2] == '#') ||
        (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2] && arr[2][2] == '#') ||
        (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0] && arr[2][0] == '#') ||
        (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1] && arr[2][1] == '#') ||
        (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2] && arr[2][2] == '#') ||
        (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] == '#') ||
        (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] == '#')   )
        return 0;                     //电脑获胜
    else if (size == 0)
        return -1;                     //平局
    else
        return 2;            //只是为了消除编译的警告并无实际意义
}

int main()
{
    int i = 0, j = 0;    //将数组初始化为空格
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            arr[i][j] = ' ';
        }
    }
    while (1)          //循环对弈直到一方获胜或者平局
    {
        chessboard();          //循环每次开始都打印棋盘
        if (winner() == -1 || winner() == 0 || winner() == 1)
        {
            break;
        }
        player();        //每下一个子后都打印棋盘 然后就判断又没有人获胜
        chessboard();
        if (winner() == -1 || winner() == 0 || winner() == 1)
        {
            break;
        }
        computer();
    }
    if (winner() == 1)
    {
        printf("玩家获胜!\n");
    }
    else if (winner() == 0)
    {
        printf("电脑获胜!\n");
    }
    else
    {
        printf("都没有获胜，平局!\n");
    }
    system("pause");
    return 0;
}