/*
 ============================================================================
 Name        : TicTacToe.c
 Author      : Alex Perrakis
 Version     : 1.0
 Copyright   : Alex Perrakis @ Rhodes
 Description : A simple Tic Tac Toe game in C, Ansi-style
 Start date  : 22/12/2016, 1:35
 End date    : --- not yet ----
 ============================================================================
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
 
int win_check(char grid_data[3][3])
{
    int k,l;
    int counter;
 
    counter = 0;
    for(k = 0; k < 3; k++)
    {
        for(l = 0; l < 3; l++)
        {
            if(grid_data[k][l] == ' ')
                counter++; 
        }
    }
    if(counter == 9)
        return 0;
    counter = 0; 
 
// Row Check
    for(k = 0; k < 3; k++)
    {
        if(grid_data[k][0] == grid_data[k][1] && grid_data[k][0] == grid_data[k][2])
        { 
            if(grid_data[k][0] != ' ' && grid_data[k][1] != ' ' && grid_data[k][2] != ' ')
                    return 1;
        }
    } 
// Column Check
    for(k = 0; k < 3; k++)
    {
        if(grid_data[0][k] == grid_data[1][k] && grid_data[0][k] == grid_data[2][k])
        {
            if(grid_data[0][k] != ' ' && grid_data[1][k] != ' ' &&  grid_data[2][k] != ' ')
                return 1;
        }
    } 
// Diag 1
    if(grid_data[0][0] == grid_data[1][1] && grid_data[0][0] == grid_data[2][2])
    {
        if(grid_data[0][0] != ' ' && grid_data[1][1] != ' ' && grid_data[2][2] != ' ')
            return 1;
    }
// Diag 2
    if(grid_data[0][2] == grid_data[1][1] && grid_data[0][2] == grid_data[2][0])
    {
        if(grid_data[0][2] != ' ' && grid_data[1][1] != ' ' &&  grid_data[2][0] != ' ')
            return 1;
    } 
    return 0; 
}
 
void display_game(char grid_data[3][3], int player, int round, int wins1, int wins2, int draws, int drawFlag)
{
    int i; 
 
    printf(" _________________________________________________________\n\n");
    printf("\n\t    Welcome to the TIC TAC TOE game!");
    printf("\n\n\t\t\t ROUND: %d\n\n", round);
    if(player == 2)
        printf("Playing NOW");
    if(player == 1)
        printf("\t\t\t\t\t       Playing NOW");
    printf("\n PLAYER 1       \t");
    printf("  DRAWS: \t");
    printf("\tPLAYER 2 \n");
    printf(" WINS:");
 
    printf("[%d]\t\t   [%d] \t\t        WINS:[%d]\n\n", wins1, draws, wins2); 
 
    for(i = 0; i < 3; i++)
    {
        printf("\t\t        %c | %c | %c \n", grid_data[i][0], grid_data[i][1], grid_data[i][2]);
 
        if(i == 2)
            break;
        printf("\t\t       ---|---|---\n");
    } 
 
    if (!win_check(grid_data) && !drawFlag)
    {
        if (player == 1)
            printf("\n\n\t     It's PLAYER 2's turn to play!\t\t\t");
        else if(player == 2)
            printf("\n\n\t     It's PLAYER 1's turn to play!\t\t\t");
        else
            printf("\n\n    Play typing 2 numbers between 1-3 in x,y format.\n\t  Do you want to start the game? (y/n)\t\t");
    }
    else if(win_check(grid_data))
    {
        printf("\n\n\t    Congratulations! PLAYER %d wins! \n", player);
        printf("\t     Do you want to continue? (y/n)  \t\t\t");
    }
    else if(drawFlag)
    {
        printf("\n\n\t        The match ended in a draw!  \n");
        printf("\t      Do you want to continue? (y/n)  \t\t\t");
    }
 
    printf("\n\n\n _________________________________________________________\n"); 
} 
 
int main(void)
{
    int player = 0;
    int round = 1;
    int wins1 = 0;
    int wins2 = 0;
    int draws = 0;
    int i, j;
    char grid_data[3][3] = {{' ', ' ', ' '},{ ' ', ' ', ' '},{' ', ' ', ' '}};
    char startAnswer;
    char endAnswer;
    int user_input_1;
    int user_input_2;
    int spaceFlag = 0;
    int drawFlag = 0;
    int x;
    int y;
    int checkflag;
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin , NULL, _IONBF, 0); 
    
    do
    { 
        display_game(grid_data, player, round, wins1, wins2, draws, drawFlag);
        
        if(player == 0)
        { 
            while(startAnswer != 'y' && startAnswer != 'n')
                scanf("%c", &startAnswer);
 
            if (startAnswer == 'n')
            { 
                system("cls");
                printf("\n\n *************************\n \tEND OF GAME\n *************************\n\n");
                system("pause");
                exit(0); 
            }
            else if (startAnswer == 'y')
            {
                player = 2;
                system("cls");
                display_game(grid_data, player, round, wins1, wins2, draws, drawFlag);
            }
        }
 
        for(i = 0; i < 9; i++)
        { 
            checkflag = 0;
            while(!checkflag)
            {
                if(!scanf("%d,%d", &user_input_1, &user_input_2))
                { 
                    printf(" Please use ONLY numbers between 1 - 3 in x,y format.\n");
                    fflush(stdin);
                    continue; 
                }
 
                if((user_input_1 == 1 || user_input_1 == 2 || user_input_1 == 3) && (user_input_2 == 1 || user_input_2 == 2 || user_input_2 == 3))
                    {
                        if(grid_data[user_input_1-1][user_input_2-1] == ' ')
                            checkflag = 1;
                        else
                            printf("This block is already filled.\n");
                    }
                else
                    {
                        printf("Please use numbers between 1 - 3 in (x,y) format.\n");
 
                    } 
            } 
 
            if(player == 2)
            {
                grid_data[user_input_1 - 1][user_input_2 - 1] = 'X';
 
                if(win_check(grid_data))
                {
                    wins1++;
                    player = 1;
                    system("cls");
                    display_game(grid_data, player, round, wins1, wins2, draws, drawFlag); 
                    break;
                 }
                player = 1;
            }
            else
            {
                grid_data[user_input_1 - 1][user_input_2 - 1] = 'O';
 
            if(win_check(grid_data))
                { 
                    wins2++;
                    player = 2;
                    system("cls");
                    display_game(grid_data, player, round, wins1, wins2, draws, drawFlag);  
                    break; 
                }
                player = 2;
            }
 
            if(i == 8 && !win_check(grid_data))
                {
                    draws++;
                    drawFlag = 1;
                } 
            system("cls");
            display_game(grid_data, player, round, wins1, wins2, draws, drawFlag);
            drawFlag = 0; 
        }
 
        endAnswer = ' ';
        //End Question
        while(endAnswer != 'y' && endAnswer != 'n')
        {
            scanf("%c", &endAnswer);
        }
        
        player = 2;
        for(i  =0; i < 3; i++)
        {
            for(j = 0; j < 3; j++)
                grid_data[i][j] = ' ';
        }
    round++;
    system("cls");
    }
    while(endAnswer == 'y'); 
 
    printf("\n\n *************************\n \tEND OF GAME\n *************************\n\n");   
    system("pause");
    return 0;
}
