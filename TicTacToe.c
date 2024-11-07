
// at the backend values stored in 2D array are 2,3 and 5 
// 2 = empty
// 3 = X (move)
// 5 = O (move)


#include<stdio.h>
#include<stdlib.h>
int board[3][3];
int gameMenu()
{
    int choice;
    system("clear");
    printf("\n1.Two Player Game");
    printf("\n2.Exit");
    printf("\nEnter Your Choice");
    scanf("%d",&choice);
    return choice;
}
void resetGame()
{
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            board[i][j]=2;
}
void displayBoard()
{
    int i,j,k=1;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]==2)
                printf("%3d",k);
            else if(board[i][j]==3)
                printf("%3c",'X');
            else if(board[i][j]==5)
                printf("%3c",'O');
            k++;
        }
        printf("\n\n");
    }
}
int isMoveValid(int move)
{
    switch(move)
    {
        case 1:
            if(board[0][0]==2)
                return 1;
            break;
        case 2:
            if(board[0][1]==2)
                return 1;
            break;
        case 3:
            if(board[0][2]==2)
                return 1;
            break;
        case 4:
            if(board[1][0]==2)
                return 1;
            break;
        case 5:
            if(board[1][1]==2)
                return 1;
            break;
        case 6:
            if(board[1][2]==2)
                return 1;
            break;
        case 7:
            if(board[2][0]==2)
                return 1;
            break;
        case 8:
            if(board[2][1]==2)
                return 1;
            break;
        case 9:
            if(board[2][2]==2)
                return 1;
            break;
    }
    return 0;
}
int inputMove(int player)
{
    int move;
    do{
        printf("Player %d (Type square number to mark your move)  ",player);
        scanf("%d",&move);
    }while(!isMoveValid(move));

    return move;
}

void makeMove(int player,int move)
{
    switch(move)
    {
        case 1:
            if(player==1)
                board[0][0]=3;
            else
                board[0][0]=5;
            break;
        case 2:
            if(player==1)
                board[0][1]=3;
            else
                board[0][1]=5;
            break;
        case 3:
            if(player==1)
                board[0][2]=3;
            else
                board[0][2]=5;
            break;
        case 4:
            if(player==1)
                board[1][0]=3;
            else
                board[1][0]=5;
            break;
        case 5:
            if(player==1)
                board[1][1]=3;
            else
                board[1][1]=5;
            break;
        case 6:
            if(player==1)
                board[1][2]=3;
            else
                board[1][2]=5;
            break;
        case 7:
            if(player==1)
                board[2][0]=3;
            else
                board[2][0]=5;
            break;
        case 8:
            if(player==1)
                board[2][1]=3;
            else
                board[2][1]=5;
            break;
        case 9:
            if(player==1)
                board[2][2]=3;
            else
                board[2][2]=5;
            break; 
    }
}
int checkWin(int player)
{
    if(player==1)
    {
        int i,j;
        for(i=0;i<3;i++)
            if(board[i][0]*board[i][1]*board[i][2]==27)
                return 1;
        for(j=0;j<3;j++)
            if(board[0][j]*board[1][j]*board[2][j]==27)
                return 1;
        if(board[0][0]*board[1][1]*board[2][2]==27)
            return 1;
        if(board[0][2]*board[1][1]*board[2][0]==27)
            return 1;
    }
    else
        {
        int i,j;
        for(i=0;i<3;i++)
            if(board[i][0]*board[i][1]*board[i][2]==125)
                return 1;
        for(j=0;j<3;j++)
            if(board[0][j]*board[1][j]*board[2][j]==125)
                return 1;
        if(board[0][0]*board[1][1]*board[2][2]==125)
            return 1;
        if(board[0][2]*board[1][1]*board[2][0]==125)
            return 1;
    }
    return 0;
}

int main()
{
    int turn,player,move;
    while(1)
    {
        switch(gameMenu())
        {
            case 1:
                resetGame();
                displayBoard();
                for(turn=1,player=1;turn<=9;turn++)
                {
                    move=inputMove(player);
                    makeMove(player,move);
                    system("clear");
                    displayBoard();
                    if( checkWin(player))
                    {
                        printf("\nPlayer %d WON the Game ",player);
                        break;
                    }
                    if(player ==1)
                        player=2;
                    else    
                        player=1;
                }
                if(turn==10)
                    printf("\n\n\nGame is draw\n\n");
                break;
                case 2:
                    exit(0);
                default:
                    printf("\nInvalid Choice, retry");

        }
    }
    

    printf("\n");
    return 0;
}