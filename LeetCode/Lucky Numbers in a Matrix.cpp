#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows (m) and columns (n): ";
    cin >> m >> n;

    int mat[50][50];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    int rowMin[50];
    int colMax[50];

    // Compute row minimums
    for (int i = 0; i < m; i++) {
        int minVal = mat[i][0];
        for (int j = 1; j < n; j++)
            if (mat[i][j] < minVal)
                minVal = mat[i][j];
        rowMin[i] = minVal;
    }

    // Compute column maximums
    for (int j = 0; j < n; j++) {
        int maxVal = mat[0][j];
        for (int i = 1; i < m; i++)
            if (mat[i][j] > maxVal)
                maxVal = mat[i][j];
        colMax[j] = maxVal;
    }

    // Check for lucky numbers
    cout << "Lucky numbers: ";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == rowMin[i] && mat[i][j] == colMax[j])
                cout << mat[i][j] << " ";
        }
    }
    cout << endl;

    return 0;
}
