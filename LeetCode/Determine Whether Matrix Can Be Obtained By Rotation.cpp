#include <iostream>
using namespace std;

bool isEqual(int n, int mat[10][10], int target[10][10])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] != target[i][j])
                return false;
    return true;
}

void rotate90(int n, int mat[10][10])
{
    int temp[10][10];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[j][n - 1 - i] = mat[i][j];
    // Copy back
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = temp[i][j];
}

bool canBeObtainedByRotation(int n, int mat[10][10], int target[10][10])
{
    for (int k = 0; k < 4; k++)
    { // 0°, 90°, 180°, 270°
        if (isEqual(n, mat, target))
            return true;
        rotate90(n, mat);
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter size n: ";
    cin >> n;

    int mat[10][10], target[10][10];

    cout << "Enter mat matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    cout << "Enter target matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> target[i][j];

    if (canBeObtainedByRotation(n, mat, target))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
