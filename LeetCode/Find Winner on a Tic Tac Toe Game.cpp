#include <iostream>
using namespace std;

bool check(int arr[3][3])
{
    // Rows
    for (int i = 0; i < 3; i++)
        if (arr[i][0] != -1 && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
            return true;

    // Columns
    for (int j = 0; j < 3; j++)
        if (arr[0][j] != -1 && arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j])
            return true;

    // Diagonals
    if (arr[0][0] != -1 && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
        return true;

    if (arr[0][2] != -1 && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
        return true;

    return false;
}

int main()
{
    int arr[3][3];

    // Initialize board
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            arr[i][j] = -1;

    bool Draw = true;

    for (int i = 0; i < 9; i++)
    {
        int x, y;
        cout << "X = ";
        cin >> x;
        cout << "Y = ";
        cin >> y;

        if (x < 0 || x > 2 || y < 0 || y > 2 || arr[x][y] != -1)
        {
            cout << "Invalid move, try again\n";
            i--;
            continue;
        }

        arr[x][y] = (i % 2 == 0) ? 1 : 0;

        if (check(arr))
        {
            cout << ((i % 2 == 0) ? "A wins\n" : "B wins\n");
            Draw = false;
            break;
        }
    }

    if (Draw)
        cout << "DRAW\n";

    return 0;
}





// Example 1:
// Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
// Output: "A"
// Explanation: A wins, they always play first.
// Example 2:
// Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
// Output: "B"
// Explanation: B wins.
// Example 3:
// Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
// Output: "Draw"
// Explanation: The game ends in a draw since there are no moves to make.