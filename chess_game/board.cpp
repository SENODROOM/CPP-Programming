#include <iostream>
#include "board.h"

char board[8][8];
char turn = 'w';
int whiteWins = 0;
int blackWins = 0;

void initializeBoard() {
    char temp[8][8] = {
        {'r','n','b','q','k','b','n','r'},
        {'p','p','p','p','p','p','p','p'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'P','P','P','P','P','P','P','P'},
        {'R','N','B','Q','K','B','N','R'}
    };
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            board[i][j] = temp[i][j];
    turn = 'w';
}

void printBoardConsole() {
    std::cout << "Turn: " << (turn=='w'?"White":"Black") << "\n";
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j)
            std::cout << (board[i][j]==' ' ? '.' : board[i][j]) << ' ';
        std::cout << '\n';
    }
}
