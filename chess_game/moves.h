#ifndef MOVES_H
#define MOVES_H

#include <utility>

bool isInside(int r, int c);
bool isWhitePiece(char ch);
bool isBlackPiece(char ch);
bool isSameColor(char a, char b);

// move validation
bool isMoveValid(int sr, int sc, int dr, int dc);
bool isPawnMove(int sr, int sc, int dr, int dc);
bool isRookMove(int sr, int sc, int dr, int dc);
bool isBishopMove(int sr, int sc, int dr, int dc);
bool isKnightMove(int sr, int sc, int dr, int dc);
bool isKingMove(int sr, int sc, int dr, int dc);
bool isQueenMove(int sr, int sc, int dr, int dc);

// utility
bool isPathClear(int sr, int sc, int dr, int dc);

#endif // MOVES_H
