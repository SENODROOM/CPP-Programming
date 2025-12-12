#ifndef BOARD_H
#define BOARD_H

// board globals and basic functions
extern char board[8][8];
extern char turn; // 'w' or 'b'
extern int whiteWins;
extern int blackWins;

void initializeBoard();
void printBoardConsole(); // optional debugging helper

#endif // BOARD_H
