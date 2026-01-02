#include <iostream>
using namespace std;

/*------------------------------------------------------------
    Maximum constraints according to problem:
    row * col <= 20000
------------------------------------------------------------*/
const int MAX = 20005;

/*------------------------------------------------------------
    Global arrays (since STL is not allowed)
------------------------------------------------------------*/
int grid[201][201];        // Grid to mark land/water
int qr[MAX], qc[MAX];     // Queue arrays for BFS

/*------------------------------------------------------------
    Function: canCross
    Purpose:
        Checks if crossing from top to bottom is possible
        on a given day using BFS
------------------------------------------------------------*/
bool canCross(int row, int col, int cells[][2], int day) {

    /*--------------------------------------------------------
        Step 1: Initialize grid with land (0)
    --------------------------------------------------------*/
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            grid[i][j] = 0;   // Land
        }
    }

    /*--------------------------------------------------------
        Step 2: Mark flooded cells up to 'day'
    --------------------------------------------------------*/
    for (int i = 0; i < day; i++) {
        int r = cells[i][0] - 1;   // Convert to 0-based index
        int c = cells[i][1] - 1;
        grid[r][c] = 1;            // Water
    }

    /*--------------------------------------------------------
        Step 3: Manual BFS setup
        We use arrays instead of STL queue
    --------------------------------------------------------*/
    int front = 0;
    int rear = 0;

    /*--------------------------------------------------------
        Step 4: Push all LAND cells of top row into queue
    --------------------------------------------------------*/
    for (int c = 0; c < col; c++) {
        if (grid[0][c] == 0) {
            qr[rear] = 0;
            qc[rear] = c;
            rear++;
            grid[0][c] = 1;   // Mark visited
        }
    }

    /*--------------------------------------------------------
        Direction arrays for 4-directional movement
    --------------------------------------------------------*/
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    /*--------------------------------------------------------
        Step 5: BFS traversal
    --------------------------------------------------------*/
    while (front < rear) {

        int r = qr[front];
        int c = qc[front];
        front++;

        // If bottom row reached → crossing possible
        if (r == row - 1) {
            return true;
        }

        // Explore neighbors
        for (int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            // Boundary and land check
            if (nr >= 0 && nr < row &&
                nc >= 0 && nc < col &&
                grid[nr][nc] == 0) {

                grid[nr][nc] = 1;  // Mark visited
                qr[rear] = nr;
                qc[rear] = nc;
                rear++;
            }
        }
    }

    // Bottom row not reachable
    return false;
}

/*------------------------------------------------------------
    Function: latestDayToCross
    Purpose:
        Uses Binary Search to find last valid day
------------------------------------------------------------*/
int latestDayToCross(int row, int col, int cells[][2]) {

    int left = 1;
    int right = row * col;
    int answer = 0;

    /*--------------------------------------------------------
        Binary Search on days
    --------------------------------------------------------*/
    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (canCross(row, col, cells, mid)) {
            answer = mid;      // Valid day
            left = mid + 1;    // Try later days
        } else {
            right = mid - 1;   // Try earlier days
        }
    }

    return answer;
}

/*------------------------------------------------------------
    MAIN FUNCTION
------------------------------------------------------------*/
int main() {

    int row = 2;
    int col = 2;

    /*--------------------------------------------------------
        Example input:
        Day-wise flooded cells
    --------------------------------------------------------*/
    int cells[4][2] = {
        {1, 1},
        {2, 1},
        {1, 2},
        {2, 2}
    };

    int result = latestDayToCross(row, col, cells);

    cout << "Latest day to cross: " << result << endl;

    return 0;
}










// Example 1:


// Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
// Output: 2
// Explanation: The above image depicts how the matrix changes each day starting from day 0.
// The last day where it is possible to cross from top to bottom is on day 2.
// Example 2:


// Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
// Output: 1
// Explanation: The above image depicts how the matrix changes each day starting from day 0.
// The last day where it is possible to cross from top to bottom is on day 1.
// Example 3:


// Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
// Output: 3
// Explanation: The above image depicts how the matrix changes each day starting from day 0.
// The last day where it is possible to cross from top to bottom is on day 3.