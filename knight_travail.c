#include<stdio.h>
void print();
int board[8][8] = {0};
int solve(int,int,int);
int nextX(int,int);
int nextY(int,int);
int main()
{
    solve(0,0,0);
    print();

    return 0;
}


int solve(int x,int y,int number)
{
    int move = 0;
    if(number == 64)
    {
        return 1;
    }

    if(board[x][y] == 0)
    {
        while(move<8)
        {
            if(nextX(x,move) != -1 && nextY(y,move) != -1)
            {
                board[x][y] = number;
                if(solve(nextX(x,move),nextY(y,move),number+1))
                {
                    return 1;
                }
            }
            move++;
        }
        board[x][y] = 0;
    }
    return 0;
}


int nextX(int x,int move)
{
    if(move == 0)
    {
        x = x + 1;
    }
    else if(move == 1)
    {
        x = x + 2;
    }
    else if(move == 2)
    {
        x = x + 2;
    }
    else if(move == 3)
    {
        x = x + 1;
    }
    else if(move == 4)
    {
        x = x - 1;
    }
    else if(move == 5)
    {
        x = x - 2;
    }
    else if(move == 6)
    {
        x = x - 2;
    }
    else if(move == 7)
    {
        x = x - 1;
    }



    if(x < 0 || x > 7)
    {
        return -1;
    }
    else
    {
        return x;
    }

}




int nextY(int y,int move)
{
    if(move == 0)
    {
        y = y - 2;
    }
    else if(move == 1)
    {
        y = y - 1;
    }
    else if(move == 2)
    {
        y = y + 1;
    }
    else if(move == 3)
    {
        y = y + 2;
    }
    else if(move == 4)
    {
        y = y + 2;
    }
    else if(move == 5)
    {
        y = y + 1;
    }
    else if(move == 6)
    {
        y = y - 1;
    }
    else if(move == 7)
    {
        y = y - 2;
    }



    if(y < 0 || y > 7)
    {
        return -1;
    }
    else
    {
        return y;
    }
}


void print()
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            printf(" %d  ", board[j][i]);
        }
        printf("\n\n");
    }
}
