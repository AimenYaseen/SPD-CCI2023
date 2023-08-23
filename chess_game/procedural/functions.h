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

void initializeBoard(char board[][8])
{

}


// initialization
void init(string playerNames[], char board[][8], int& turn)
{
    getPlayerNames(playerNames);

    initializeBoard(board);
}