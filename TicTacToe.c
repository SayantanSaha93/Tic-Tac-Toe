/*

This project is about making a simple tic tac toe game playable on the command line prompt :)

***********************  UNFINISHED  ****************************

ISSUES
#1
After winner is declared the game asks for input but causes crash.
    Crash fixed but can't take input after game ends.

#2
Even after 2 days of trying to figure out what went wrong with this program I can't seem to find anything at all.

After quite a long time when you finally sit down to look at your code ...
23/03/2022

Made a change as to remove the scanf bug
Edit : the change causes new bug where game exit needs to be revoked twice
Also reverted back the changes

Breakthrough @ 21:41 hrs
Made change : scanf in while condition

Known issues fixed =)

will make an unbeatable algorithm after I learn a bit about DSA (expect around September)

signing off
Sayantan Saha
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

char board[3][3];

const char PLAYER = 'X';

const char COMPUTER = 'O';

void chooseSymbol();        // Intended to let user choose what symbol they want to use (STARTED AFTER BUG FIX)

void resetBoard();          // Resets the board to initial postition
void printBoard();          // Prints the current view of the board
int checkFreeSpaces();      // aho, it does what it says
void playerMove();          // Hey there! Your move pal.
void computerMove();        // Hmm AI is going to destroy the world XD
char checkWinner();         // Is there a winner? @-@
void printWinner(char);     // The winner is ...

int main()
{
    char winner = ' ';
    char response = ' ';

    do
    {
        char winner = ' ';
        // char response = ' ';

        resetBoard();

        while (winner == ' ' && checkFreeSpaces() != 0)
        {

            printBoard();

            playerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }

            computerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }
        }
        printBoard();
        printWinner(winner);

        printf("Would you like to play again? (Y/N): \n");

    } while (scanf(" %c", &response) && (response == 'Y' || response == 'y'));

    printf("Thanks for playing\n");

    return 0;
}

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int checkFreeSpaces()
{
    int freeSpaces = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}
void playerMove()
{
    int x;
    int y;

    do
    {
        printf("Enter row number #(1-3): ");
        scanf("%d", &x);

        // Put check for isNum

        x--;
        printf("Enter column number #(1-3): ");
        scanf("%d", &y);

        // Put check for isNum

        y--;

        if (board[x][y] != ' ')
        {
            printf("Invalid move!\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
}
void computerMove()
{
    // creates a seed based on current time
    srand(time(0));
    int x;
    int y;

    if (checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;

        } while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' ');
    }
}
char checkWinner()
{
    // check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    // check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    // chekc diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' ';
}
void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("You win!\n");
    }
    else if (winner == COMPUTER)
    {
        printf("You lose!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }
}

// void chooseSymbol()
// {
//     char choice = ' ';
//     printf("What symbol do you want to choose ? (X / O)\n");
//     scanf(" %c", &choice);
// }