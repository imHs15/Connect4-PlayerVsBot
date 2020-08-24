#include<stdio.h>
#include<string.h>
#include<time.h>
#define p 88
#define c 79

//Player Coin:X Computer Coin:O EmptySpace:-


int players_turn(int board[6][7],int flag[6][7])
{
    int i,column,l=0;
    printf("\nEnter the column number:");
    scanf("%d",&column);
    column-=1;
    if(flag[0][column]==1)
        l=1;
    else if(column>=0&&column<=6)
    {
        for(i=5;i>=0;i--)
        {
            if(flag[i][column]==0)
            {
                board[i][column]=p;
                flag[i][column]=1;
                break;
            }
        }
        l=0;
    }
    else
        l=1;
    return l;
}

//Horizontal sum check
int horizontalcheck(int row,int column,int board[6][7],int flag[6][7])
{
    int sum=0,a=0,i;
    sum=board[row][column]+board[row][column+1]+board[row][column+2]+board[row][column+3];
    if(sum==282)
    {
            if(row==5)
            {
                for(i=0;i<4;i++)
                {
                    if(flag[row][column+i]==0)
                    {
                        board[row][column+i]=c;
                        flag[row][column+i]=1;
                        a=1;
                        break;
                    }
                }
            }
            else
            {
                for(i=0;i<4;i++)
                {
                    if(flag[row][column+i]==0&&flag[row+1][column+i]==1)
                    {
                        board[row][column+i]=c;
                        flag[row][column+i]=1;
                        a=1;
                        break;
                    }
                }
            }
    }
    else if(sum==309)
    {
            if(row==5)
            {
                for(i=0;i<4;i++)
                {
                    if(flag[row][column+i]==0)
                    {
                        board[row][column+i]=c;
                        flag[row][column+i]=1;
                        a=1;
                        break;
                    }
                }
            }
            else
            {
                for(i=0;i<4;i++)
                {
                    if(flag[row][column+i]==0&&flag[row+1][column+i]==1)
                    {
                        board[row][column+i]=c;
                        flag[row][column+i]=1;
                        a=1;
                        break;
                    }
                }
            }
    }
    if(a==1)
    {
        a=0;
        return 1;
    }
    else
    {
        return 0;
    }
}

//Vertical sum check
int verticalcheck(int row,int column,int board[6][7],int flag[6][7])
{
    int sum=0,a=0,i;
    sum=board[row][column]+board[row-1][column]+board[row-2][column]+board[row-3][column];
    if(sum==282)
    {
        board[row-3][column]=c;
        flag[row-3][column]=1;
        a=1;
    }
    if(sum==309)
    {
        board[row-3][column]=c;
        flag[row-3][column]=1;
        a=1;
    }
    if(a==1)
    {
        a=0;
        return 1;
    }
    else
        return 0;
}

//Left diagonal sum check
int dleftcheck(int row,int column,int board[6][7],int flag[6][7])
{
    int sum,i,a=0;
    sum=board[row][column]+board[row-1][column-1]+board[row-2][column-2]+board[row-3][column-3];
    if(sum==282)
    {
        if(row==5)
        {
            for(i=0;i<4;i++)
            {
                if(i==0)
                {
                   if(flag[row-i][column-i]==0)
                    {
                        board[row-i][column-i]=c;
                        flag[row-i][column-i]=1;
                        a=1;
                        break;
                    }
                }
                else
                {
                    if(flag[row-i][column-i]==0&&flag[row-i+1][column-i]==1)
                    {
                        board[row-i][column-i]=c;
                        flag[row-i][column-i]=1;
                        a=1;
                        break;
                    }
                }
            }
        }
        else
        {
            for(i=0;i<4;i++)
            {
                if(flag[row-i][column-i]==0&&flag[row-i+1][column-i]==1)
                {
                    board[row-i][column-i]=c;
                    flag[row-i][column-i]=1;
                    a=1;
                    break;
                }
            }
        }
    }
    else if(sum==309)
    {
        if(row==5)
        {
            for(i=0;i<4;i++)
            {
                if(i==0)
                {
                   if(flag[row-i][column-i]==0)
                    {
                        board[row-i][column-i]=c;
                        flag[row-i][column-i]=1;
                        a=1;
                        break;
                    }
                }
                else
                {
                    if(flag[row-i][column-i]==0&&flag[row-i+1][column-i]==1)
                    {
                        board[row-i][column-i]=c;
                        flag[row-i][column-i]=1;
                        a=1;
                        break;
                    }
                }
            }
        }
        else
        {
            for(i=0;i<4;i++)
            {
                if(flag[row-i][column-i]==0&&flag[row-i+1][column-i]==1)
                {
                    board[row-i][column-i]=c;
                    flag[row-i][column-i]=1;
                    a=1;
                    break;
                }
            }
        }
    }
    if(a==1)
    {
        a=0;
        return 1;
    }
    else
        return 0;
}

//Right diagonal sum check
int drightcheck(int row,int column,int board[6][7],int flag[6][7])
{
    int sum,i,a=0;
    sum=board[row][column]+board[row-1][column+1]+board[row-2][column+2]+board[row-3][column+3];
    if(sum==282)
    {
        if(row==5)
        {
            for(i=0;i<4;i++)
            {
                if(i==0)
                {
                   if(flag[row-i][column+i]==0)
                    {
                        board[row-i][column+i]=c;
                        flag[row-i][column+i]=1;
                        a=1;
                        break;
                    }
                }
                else
                {
                    if(flag[row-i][column+i]==0&&flag[row-i+1][column+i]==1)
                    {
                        board[row-i][column+i]=c;
                        flag[row-i][column+i]=1;
                        a=1;
                        break;
                    }
                }
            }
        }
        else
        {
            for(i=0;i<4;i++)
            {
                if(flag[row-i][column+i]==0&&flag[row-i+1][column+i]==1)
                {
                    board[row-i][column+i]=c;
                    flag[row-i][column+i]=1;
                    a=1;
                    break;
                }
            }
        }
    }
    else if(sum==309)
    {
        if(row==5)
        {
            for(i=0;i<4;i++)
            {
                if(i==0)
                {
                   if(flag[row-i][column+i]==0)
                    {
                        board[row-i][column+i]=c;
                        flag[row-i][column+i]=1;
                        a=1;
                        break;
                    }
                }
                else
                {
                    if(flag[row-i][column+i]==0&&flag[row-i+1][column+i]==1)
                    {
                        board[row-i][column+i]=c;
                        flag[row-i][column+i]=1;
                        a=1;
                        break;
                    }
                }
            }
        }
        else
        {
            for(i=0;i<4;i++)
            {
                if(flag[row-i][column+i]==0&&flag[row-i+1][column+i]==1)
                {
                    board[row-i][column+i]=c;
                    flag[row-i][column+i]=1;
                    a=1;
                    break;
                }
            }
        }
    }
    if(a==1)
    {
        a=0;
        return 01;
    }
    else
        return 0;
}

//Print current board
void print_board(int board[6][7])
{
    int i,j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            printf("%c\t",board[i][j]);
        }
        printf("\n");
    }
}

//Insert in random column
void random(int board[6][7],int flag[6][7])
{
    int column,i;
    column=(rand()%(7));
    if(flag[0][column]!=1)
    {
        for(i=5;i>=0;i--)
        {
            if(flag[i][column]==0)
            {
                board[i][column]=c;
                flag[i][column]=1;
                break;
            }
        }
    }
    else
        random(board,flag);
}

//Check winner
int winner(int board[6][7])
{
    int i,j,l,sum1=0,sum2=0,sum3=0,sum4=0;
    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            sum1=board[i][j]+board[i][j+1]+board[i][j+2]+board[i][j+3];
            sum2=board[i][j]+board[i-1][j]+board[i-2][j]+board[i-3][j];
            if(sum1==352||sum2==352)
                l=1;
            else if(sum1==316||sum2==316)
                l=-1;
        }
    }
    for(i=5;i>=3;i--)
    {
    	for(j=0;j<4;j++)
    	{
            sum3=board[i][j]+board[i-1][j+1]+board[i-2][j+2]+board[i-3][j+3];
            if(sum3==352)
            	l=1;
            else if(sum3==316)
            	l=-1;
        }
    }
    for(i=5;i>=3;i--)
    {
    	for(j=6;j>=3;j--)
    	{
            sum4=board[i][j]+board[i+1][j+1]+board[i+2][j+2]+board[i+3][j+3];
            if(sum4==352)
            	l=1;
            else if(sum4==316)
            	l=-1;
         }
    }
    if(l==1)
    	return 1;
    else if(l==-1)
    	return -1;
    else
    	return 0;
}


int main()
{
    int board[6][7],flag[6][7],i,j,k,h,v,dl,dr,win=0;
    for(i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            board[i][j]=45;
            flag[i][j]=0;
        }
    }
    printf("||4 IN A ROW||\n\n");
    printf("Player coin:X\tComputer Coin:O\n\n");
    printf("The board looks like this.\n");
    print_board(board);
    while(win!=1||win!=-1)
    {
    	k=1;
        while(k!=0)
        {
        	k=players_turn(board,flag);
        	if(k==1)
        	    printf("Entered column is full or invalid column number entered.\n");
       	}
       	print_board(board);
        for(i=5;i>=0;i--)
        {
            for(j=0;j<4;j++)
            {
                h=horizontalcheck(i,j,board,flag);
                if(h==1)
                    break;
            }
            if(h==1)
                break;
        }
        if(h!=1)
        {
            for(i=5;i>=3;i--)
            {
                for(j=0;j<7;j++)
                {
                    v=verticalcheck(i,j,board,flag);
                    if(v==1)
                        break;
                }
                if(v==1)
                    break;
            }
        }
        if(h!=1&&v!=1)
        {
           for(i=5;i>=3;i--)
            {
                for(j=6;j>=3;j--)
                {
                    dl=dleftcheck(i,j,board,flag);
                    if(dl==1)
                        break;
                }
                if(dl==1)
                    break;
            }
        }
        if(h!=1&&v!=1&&dl!=1)
        {
           for(i=5;i>=3;i--)
            {
                for(j=0;j<=3;j++)
                {
                    dl=drightcheck(i,j,board,flag);
                    if(dr==1)
                        break;
                }
                if(dr==1)
                    break;
            }
        }
        if(h!=1&&v!=1&&dl!=1&&dr!=1)
        {
            srand(time(0));
            random(board,flag);
        }
        printf("\nAfter Computer's turn.\n");
        print_board(board);
        win=winner(board);
        if(win==1)
        {
            printf("\nPlayer is the winner!!");
            break;
        }
        else if(win==-1)
        {
            printf("\nComputer is the winner!!");
            break;
        }
    }
}