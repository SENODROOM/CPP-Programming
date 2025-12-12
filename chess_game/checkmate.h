#ifndef CHECKMATE_H
#define CHECKMATE_H

// Check/checkmate/stalemate functions
bool isSquareAttacked(int r, int c, char attackerColor);
bool findKing(char side, int *kr, int *kc);
bool isKingInCheck(char side);
bool hasAnyLegalMove(char side);
bool isCheckmate(char side);
bool isStalemate(char side);
int getLegalKingMoves(char side,int out[16]);

#endif // CHECKMATE_H
