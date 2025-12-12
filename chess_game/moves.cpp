#include "moves.h"
#include "board.h"
#include <cmath>

// Helper: inside board
bool isInside(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

bool isWhitePiece(char ch) {
    if (ch == ' ') return false;
    return (ch >= 'A' && ch <= 'Z');
}

bool isBlackPiece(char ch) {
    if (ch == ' ') return false;
    return (ch >= 'a' && ch <= 'z');
}

bool isSameColor(char a, char b) {
    if (a==' ' || b==' ') return false;
    return (isWhitePiece(a) && isWhitePiece(b)) || (isBlackPiece(a) && isBlackPiece(b));
}

bool isPathClear(int sr, int sc, int dr, int dc) {
    int rstep = (dr > sr) ? 1 : (dr < sr) ? -1 : 0;
    int cstep = (dc > sc) ? 1 : (dc < sc) ? -1 : 0;

    int r = sr + rstep;
    int c = sc + cstep;
    while (r != dr || c != dc) {
        if (board[r][c] != ' ') return false;
        r += rstep;
        c += cstep;
    }
    return true;
}

bool isPawnMove(int sr, int sc, int dr, int dc) {
    char p = board[sr][sc];
    int dir = (isWhitePiece(p)) ? -1 : 1; // white pawns move up (decreasing row)
    int startRow = (isWhitePiece(p)) ? 6 : 1;
    // forward move
    if (dc == sc) {
        if (dr == sr + dir && board[dr][dc] == ' ') return true;
        if (sr == startRow && dr == sr + 2*dir && board[sr + dir][sc] == ' ' && board[dr][dc] == ' ')
            return true;
        return false;
    }
    // capture
    if ((dr == sr + dir) && (dc == sc+1 || dc == sc-1)) {
        if (board[dr][dc] != ' ' && !isSameColor(board[sr][sc], board[dr][dc])) return true;
    }
    return false;
}

bool isRookMove(int sr, int sc, int dr, int dc) {
    if (sr != dr && sc != dc) return false;
    if (!isPathClear(sr, sc, dr, dc)) return false;
    if (board[dr][dc] == ' ' || !isSameColor(board[sr][sc], board[dr][dc])) return true;
    return false;
}

bool isBishopMove(int sr, int sc, int dr, int dc) {
    if (abs(dr - sr) != abs(dc - sc)) return false;
    if (!isPathClear(sr, sc, dr, dc)) return false;
    if (board[dr][dc] == ' ' || !isSameColor(board[sr][sc], board[dr][dc])) return true;
    return false;
}

bool isKnightMove(int sr, int sc, int dr, int dc) {
    int drd = abs(dr - sr);
    int dcd = abs(dc - sc);
    if (!((drd == 2 && dcd == 1) || (drd == 1 && dcd == 2))) return false;
    if (board[dr][dc] == ' ' || !isSameColor(board[sr][sc], board[dr][dc])) return true;
    return false;
}

bool isKingMove(int sr, int sc, int dr, int dc) {
    int drd = abs(dr - sr);
    int dcd = abs(dc - sc);
    if (drd <=1 && dcd <=1) {
        if (board[dr][dc] == ' ' || !isSameColor(board[sr][sc], board[dr][dc])) return true;
    }
    return false;
}

bool isQueenMove(int sr, int sc, int dr, int dc) {
    // queen = rook + bishop
    if (sr == dr || sc == dc) return isRookMove(sr, sc, dr, dc);
    if (abs(dr - sr) == abs(dc - sc)) return isBishopMove(sr, sc, dr, dc);
    return false;
}

bool isMoveValid(int sr, int sc, int dr, int dc) {
    if (!isInside(sr,sc) || !isInside(dr,dc)) return false;
    char piece = board[sr][sc];
    if (piece == ' ') return false;
    // turn check
    if (turn == 'w' && !isWhitePiece(piece)) return false;
    if (turn == 'b' && !isBlackPiece(piece)) return false;
    // destination cannot be same color
    if (isSameColor(piece, board[dr][dc])) return false;

    char lower;
    if (piece == 'P' || piece == 'p') return isPawnMove(sr,sc,dr,dc);
    if (piece == 'R' || piece == 'r') return isRookMove(sr,sc,dr,dc);
    if (piece == 'N' || piece == 'n') return isKnightMove(sr,sc,dr,dc);
    if (piece == 'B' || piece == 'b') return isBishopMove(sr,sc,dr,dc);
    if (piece == 'Q' || piece == 'q') return isQueenMove(sr,sc,dr,dc);
    if (piece == 'K' || piece == 'k') return isKingMove(sr,sc,dr,dc);

    return false;
}
