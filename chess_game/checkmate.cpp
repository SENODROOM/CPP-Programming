#include "moves.h"
#include "board.h"
#include <cmath>

// ---------------------- Basic move legality ----------------------
bool isLegalMove(int sr, int sc, int dr, int dc)
{
    if (!isInside(sr, sc) || !isInside(dr, dc))
        return false;

    char piece = board[sr][sc];
    if (piece == ' ')
        return false;
    if (sr == dr && sc == dc)
        return false;
    if (isSameColor(piece, board[dr][dc]))
        return false;

    int dx = dc - sc;
    int dy = dr - sr;

    switch (piece)
    {
    case 'P': // White Pawn
        if (dx == 0 && dy == -1 && board[dr][dc] == ' ')
            return true;
        if (dx == 0 && dy == -2 && sr == 6 &&
            board[sr - 1][sc] == ' ' && board[dr][dc] == ' ')
            return true;
        if (abs(dx) == 1 && dy == -1 &&
            board[dr][dc] != ' ' && !isWhitePiece(board[dr][dc]))
            return true;
        return false;

    case 'p': // Black Pawn
        if (dx == 0 && dy == 1 && board[dr][dc] == ' ')
            return true;
        if (dx == 0 && dy == 2 && sr == 1 &&
            board[sr + 1][sc] == ' ' && board[dr][dc] == ' ')
            return true;
        if (abs(dx) == 1 && dy == 1 &&
            board[dr][dc] != ' ' && !isBlackPiece(board[dr][dc]))
            return true;
        return false;

    case 'N':
    case 'n': // Knight
        if ((abs(dx) == 2 && abs(dy) == 1) ||
            (abs(dx) == 1 && abs(dy) == 2))
            return true;
        return false;

    case 'B':
    case 'b': // Bishop
        if (abs(dx) == abs(dy))
        {
            int stepX = (dx > 0) ? 1 : -1;
            int stepY = (dy > 0) ? 1 : -1;
            int x = sc + stepX, y = sr + stepY;

            while (x != dc && y != dr)
            {
                if (board[y][x] != ' ')
                    return false;
                x += stepX;
                y += stepY;
            }
            return true;
        }
        return false;

    case 'R':
    case 'r': // Rook
        if (dx == 0 || dy == 0)
        {
            int stepX = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
            int stepY = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);
            int x = sc + stepX, y = sr + stepY;

            while (x != dc || y != dr)
            {
                if (board[y][x] != ' ')
                    return false;
                x += stepX;
                y += stepY;
            }
            return true;
        }
        return false;

    case 'Q':
    case 'q': // Queen
        if (dx == 0 || dy == 0 || abs(dx) == abs(dy))
        {
            int stepX = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
            int stepY = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);
            int x = sc + stepX, y = sr + stepY;

            while (x != dc || y != dr)
            {
                if (board[y][x] != ' ')
                    return false;
                x += stepX;
                y += stepY;
            }
            return true;
        }
        return false;

    case 'K':
    case 'k': // King
        if (abs(dx) <= 1 && abs(dy) <= 1)
            return true;
        return false;
    }

    return false;
}

// ---------------------- Helpers ----------------------
bool isSquareAttacked(int r, int c, char attackerColor)
{
    // Pawn attacks
    if (attackerColor == 'w')
    {
        if (isInside(r - 1, c - 1) && board[r - 1][c - 1] == 'P')
            return true;
        if (isInside(r - 1, c + 1) && board[r - 1][c + 1] == 'P')
            return true;
    }
    else
    {
        if (isInside(r + 1, c - 1) && board[r + 1][c - 1] == 'p')
            return true;
        if (isInside(r + 1, c + 1) && board[r + 1][c + 1] == 'p')
            return true;
    }

    // Knight attacks
    int knightMoves[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    for (int i = 0; i < 8; i++)
    {
        int nr = r + knightMoves[i][0];
        int nc = c + knightMoves[i][1];
        if (!isInside(nr, nc))
            continue;
        char ch = board[nr][nc];

        if ((attackerColor == 'w' && ch == 'N') ||
            (attackerColor == 'b' && ch == 'n'))
            return true;
    }

    // Rooks/Queens (straight lines)
    int lines[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int d = 0; d < 4; d++)
    {
        int nr = r + lines[d][0];
        int nc = c + lines[d][1];

        while (isInside(nr, nc))
        {
            char ch = board[nr][nc];
            if (ch != ' ')
            {
                if ((attackerColor == 'w' && (ch == 'R' || ch == 'Q')) ||
                    (attackerColor == 'b' && (ch == 'r' || ch == 'q')))
                    return true;
                break;
            }
            nr += lines[d][0];
            nc += lines[d][1];
        }
    }

    // Bishops/Queens (diagonals)
    int diag[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    for (int d = 0; d < 4; d++)
    {
        int nr = r + diag[d][0];
        int nc = c + diag[d][1];

        while (isInside(nr, nc))
        {
            char ch = board[nr][nc];
            if (ch != ' ')
            {
                if ((attackerColor == 'w' && (ch == 'B' || ch == 'Q')) ||
                    (attackerColor == 'b' && (ch == 'b' || ch == 'q')))
                    return true;
                break;
            }
            nr += diag[d][0];
            nc += diag[d][1];
        }
    }

    // King adjacency
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++)
        {
            if (dr == 0 && dc == 0)
                continue;
            int nr = r + dr, nc = c + dc;
            if (!isInside(nr, nc))
                continue;

            char ch = board[nr][nc];
            if ((attackerColor == 'w' && ch == 'K') ||
                (attackerColor == 'b' && ch == 'k'))
                return true;
        }

    return false;
}

bool findKing(char side, int *kr, int *kc)
{
    char k = (side == 'w') ? 'K' : 'k';

    for (int r = 0; r < 8; r++)
        for (int c = 0; c < 8; c++)
            if (board[r][c] == k)
            {
                *kr = r;
                *kc = c;
                return true;
            }

    *kr = *kc = -1;
    return false;
}

bool isKingInCheck(char side)
{
    int kr, kc;
    if (!findKing(side, &kr, &kc))
        return false;

    char opp = (side == 'w') ? 'b' : 'w';
    return isSquareAttacked(kr, kc, opp);
}

// ---------------------- Move simulation ----------------------
bool hasAnyLegalMove(char side)
{
    for (int sr = 0; sr < 8; sr++)
    {
        for (int sc = 0; sc < 8; sc++)
        {
            char piece = board[sr][sc];
            if (piece == ' ')
                continue;

            if (side == 'w' && !isWhitePiece(piece))
                continue;
            if (side == 'b' && !isBlackPiece(piece))
                continue;

            for (int dr = 0; dr < 8; dr++)
            {
                for (int dc = 0; dc < 8; dc++)
                {

                    if (!isLegalMove(sr, sc, dr, dc))
                        continue;

                    // Simulate move
                    char savedDest = board[dr][dc];
                    char savedSrc = board[sr][sc];

                    board[dr][dc] = savedSrc;
                    board[sr][sc] = ' ';

                    bool inCheck = isKingInCheck(side);

                    // Undo move
                    board[sr][sc] = savedSrc;
                    board[dr][dc] = savedDest;

                    if (!inCheck)
                        return true;
                }
            }
        }
    }
    return false;
}

bool isCheckmate(char side)
{
    return isKingInCheck(side) && !hasAnyLegalMove(side);
}

bool isStalemate(char side)
{
    return !isKingInCheck(side) && !hasAnyLegalMove(side);
}

// ---------------------- King moves ----------------------
int getLegalKingMoves(char side, int out[16])
{
    int count = 0;
    int kr, kc;

    if (!findKing(side, &kr, &kc))
        return 0;

    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++)
        {
            if (dr == 0 && dc == 0)
                continue;

            int nr = kr + dr;
            int nc = kc + dc;

            if (!isInside(nr, nc))
                continue;
            if (isSameColor(board[kr][kc], board[nr][nc]))
                continue;
            if (!isLegalMove(kr, kc, nr, nc))
                continue;

            // simulate
            char savedDest = board[nr][nc];
            char savedKing = board[kr][kc];

            board[nr][nc] = savedKing;
            board[kr][kc] = ' ';

            bool inCheck = isKingInCheck(side);

            // undo
            board[kr][kc] = savedKing;
            board[nr][nc] = savedDest;

            if (!inCheck)
            {
                out[count++] = nr;
                out[count++] = nc;
            }
        }

    return count;
}
