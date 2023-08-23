using namespace std;

#include <array>
#include <iostream>
#include "functions.h"


int main()
{
    cout << " ----------- LET'S PLAY CHESS ------------------" << endl;

    string playerNames[2];
    char board[8][8];
    int turn;
    int sr, sc, er, ec;

    // initialization
    init(playerNames, board, turn);

    // display board
    displayBoard(board);
}