#pragma once

using namespace std;

#include <iostream>


int WHITE = 0;
int BLACK = 1;

void getPlayerNames(string playerNames[])
{
    cout << endl << "Enter Player Name 1:  ";
    cin >> playerNames[0];
    cout << endl;

    cout << endl << "Enter Player Name 2:  ";
    cin >> playerNames[1];
    cout << endl;
}

void setBoardElements(char board[][8], char E[], int r1, int r2)
{
    int cl = 0, cr = 7;

    for(int i=0; i<=3; i++)
    {
        // set queen and king
        if(i == 3)
        {
            board[r1][cl] = E[i];
            board[r1][cr] = E[i+1];
        }
        else
        {
            board[r1][cl] = E[i];
            board[r1][cr] = E[i];
            cl++;
            cr--;
        }
    }

    // set pawns
    for(int c = 0; c <= 7; c++)
        board[r2][c] = E[5];
}

void initializeBoard(char board[][8])
{
    // Initializing each element with an empty string
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            board[i][j] = ' ';
        
    // ------------ BLACK WILL BE SMALL --------------
    char BE[6] = {'r', 'h', 'b', 'q', 'k', 'p'};
    setBoardElements(board, BE, 0, 1);

    // ------------ WHITE WILL BE CAPITAL ------------
    char WE[6] = {'R', 'H', 'B', 'Q', 'K', 'P'};
    setBoardElements(board, WE, 7, 6);
}


// initialization
void init(string playerNames[], char board[][8], int& turn)
{
    getPlayerNames(playerNames);

    initializeBoard(board);

    turn = WHITE;
}

// display board
void displayBoard(char board[][8])
{
    cout << endl << "    0   1   2   3   4   5   6   7" << endl;
    cout << "  _________________________________" << endl;

    for (int i = 0; i < 8; ++i) {
        cout << i << " |";
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == '\0') {
                cout << "  ";
            } else {
                cout << " " << board[i][j];
            }
            cout << " |";
        }
        cout << endl << "  _________________________________" << endl;
    }
}