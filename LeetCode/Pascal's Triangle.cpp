#include <iostream>
using namespace std;

/*
    ============================================================
    LEETCODE 118 - PASCAL'S TRIANGLE
    ============================================================

    STRICT CONSTRAINTS FOLLOWED:
    ----------------------------
    ✔ No STL (no vector, no array library)
    ✔ No pointers
    ✔ No class / solution object
    ✔ Only void function + main
    ✔ Only <iostream>
    ✔ University-level explanation

    ------------------------------------------------------------
    LOGIC:
    ------
    Pascal’s Triangle follows these rules:

    1) First and last element of each row = 1
    2) Middle elements:
       triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]

    ------------------------------------------------------------
    MAX SIZE:
    ---------
    LeetCode constraints allow numRows ≤ 30
    We safely take MAX = 35
*/

const int MAX = 35;

/*
    Function: generatePascal
    ------------------------
    This function fills the 2D array with Pascal's Triangle
*/
void generatePascal(int triangle[MAX][MAX], int numRows) {

    for (int i = 0; i < numRows; i++) {

        for (int j = 0; j <= i; j++) {

            // First and last element of every row is 1
            if (j == 0 || j == i) {
                triangle[i][j] = 1;
            }
            else {
                // Middle elements = sum of two above elements
                triangle[i][j] =
                    triangle[i - 1][j - 1] +
                    triangle[i - 1][j];
            }
        }
    }
}

/*
    Function: printPascal
    ---------------------
    Prints Pascal's Triangle
*/
void printPascal(int triangle[MAX][MAX], int numRows) {

    for (int i = 0; i < numRows; i++) {

        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << " ";
        }

        cout << endl;
    }
}

int main() {

    int numRows;
    int triangle[MAX][MAX] = {0};

    cout << "Enter number of rows: ";
    cin >> numRows;

    generatePascal(triangle, numRows);

    cout << "\nPascal's Triangle:\n";
    printPascal(triangle, numRows);

    return 0;
}
