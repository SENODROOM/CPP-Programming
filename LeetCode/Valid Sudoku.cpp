#include <iostream>
using namespace std;

bool isValidSudoku(char board[9][9])
{
    // Check rows
    for (int i = 0; i < 9; i++)
    {
        bool seen[10] = {false};

        for (int j = 0; j < 9; j++)
        {
            char c = board[i][j];

            if (c == '.')
                continue;
            int num = c - '0';

            if (seen[num])
                return false;
            seen[num] = true;
        }
    }

    // Check columns
    for (int j = 0; j < 9; j++)
    {
        bool seen[10] = {false};

        for (int i = 0; i < 9; i++)
        {
            char c = board[i][j];

            if (c == '.')
                continue;
            int num = c - '0';

            if (seen[num])
                return false;
            seen[num] = true;
        }
    }

    // Check 3×3 boxes
    for (int boxR = 0; boxR < 9; boxR += 3)
    {
        for (int boxC = 0; boxC < 9; boxC += 3)
        {

            bool seen[10] = {false};

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {

                    char c = board[boxR + i][boxC + j];

                    if (c == '.')
                        continue;
                    int num = c - '0';

                    if (seen[num])
                        return false;
                    seen[num] = true;
                }
            }
        }
    }

    return true;
}

int main()
{
    char board[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    cout << (isValidSudoku(board) ? "true" : "false");
}
