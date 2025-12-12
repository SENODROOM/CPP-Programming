#include <iostream>
using namespace std;

/*
====================================================================
  FUNCTION: isValid
  PURPOSE : Check if placing digit 'num' at board[row][col] violates
            any Sudoku rule.

  Sudoku Rules:
    1) No same number in the same ROW
    2) No same number in the same COLUMN
    3) No same number in the same 3×3 SUBGRID

  This function returns:
      true  → if the number CAN be placed safely
      false → if the number breaks a rule
====================================================================
*/
bool isValid(char board[9][9], int row, int col, char num) {

    /*
    ------------------------------------------------------------
     RULE 1 — Check the entire ROW
     If the number already exists in row 'row', placing it here 
     would create a duplicate — INVALID
    ------------------------------------------------------------
    */
    for (int c = 0; c < 9; c++) {
        if (board[row][c] == num)
            return false;
    }

    /*
    ------------------------------------------------------------
     RULE 2 — Check the entire COLUMN
     If the number already exists in the same column, INVALID
    ------------------------------------------------------------
    */
    for (int r = 0; r < 9; r++) {
        if (board[r][col] == num)
            return false;
    }

    /*
    ------------------------------------------------------------
     RULE 3 — CHECK THE 3×3 SUBGRID

     We find which of the 9 subgrids (0–8) the cell belongs to.
     Example: 
        Rows 0–2  belong to box row 0
        Rows 3–5  belong to box row 1
        Rows 6–8  belong to box row 2

     startRow gives the top row of the box.
     startCol gives the left column of the box.

     Example:
       If row = 5, col = 7:
         startRow = (5/3)*3 = 1*3 = 3
         startCol = (7/3)*3 = 2*3 = 6

       Meaning the box starts at (3,6)
    ------------------------------------------------------------
    */
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    // Check all 9 cells inside this 3×3 box
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[startRow + r][startCol + c] == num)
                return false;
        }
    }

    // If all 3 rules passed, the number is safe to place
    return true;
}



/*
====================================================================
  FUNCTION: solveSudoku
  PURPOSE : Solve the board using BACKTRACKING.

  Backtracking Concept:
    - Find an empty cell
    - Try placing numbers '1' to '9'
    - For each number:
           If valid → place it → go deeper (recursive call)
           If deeper call fails → undo (backtrack) and try next number
    - If no number fits → report failure

  This function returns:
      true  → board solved
      false → no solution exists from current state
====================================================================
*/
bool solveSudoku(char board[9][9]) {

    /*
    =====================================================================
      The algorithm begins by searching for the next empty cell on 
      the 9×9 Sudoku grid. Empty cells are represented by the character '.'.

      We scan the board left to right (columns) and top to bottom (rows)
      like reading a book. This ensures we solve the puzzle in a logical
      order, starting from the top-left corner.

      NOTE: If no empty cell exists anymore, then the Sudoku is solved.
    =====================================================================
    */
    for (int row = 0; row < 9; row++) {         // Loop through all 9 rows
        for (int col = 0; col < 9; col++) {     // Loop through all 9 columns

            // --------------------------------------------------------------
            // If the current cell has '.', it means it is EMPTY 
            // and needs to be filled with a correct number.
            // --------------------------------------------------------------
            if (board[row][col] == '.') {       // Found an empty position!

                /*
                =================================================================
                  STEP 2: Try placing digits '1' to '9' in this empty cell.

                  This is the core idea of BACKTRACKING:
                    → Try a candidate number.
                    → Check if it's valid.
                    → If valid, go deeper and try solving the rest of the board.
                    → If deeper fails, undo (backtrack) and try another number.

                  Each number is a different "path" the program explores.
                =================================================================
                */
                for (char num = '1'; num <= '9'; num++) {

                    // ----------------------------------------------------------
                    // Check whether putting 'num' in board[row][col]
                    // follows all Sudoku rules (row, column, 3×3 grid).
                    // If not valid → skip and try next number.
                    // ----------------------------------------------------------
                    if (isValid(board, row, col, num)) {

                        /*
                        ==========================================================
                          STEP 3: Place the number tentatively (temporarily)

                          This is a "guess". We assume that placing this number
                          might lead to a correct full solution.

                          IMPORTANT:
                            This does NOT mean it's correct. We are just trying.
                        ==========================================================
                        */
                        board[row][col] = num;

                        /*
                        ==========================================================
                          STEP 4: Recursively attempt to solve the rest of the board
                          
                          The recursion continues solving other empty cells.

                          If solveSudoku(board) returns TRUE:
                            → It means that from this point onward,
                              everything fits perfectly.
                            → So we immediately return TRUE because
                              the entire puzzle is solved.

                          This is the "success path".
                        ==========================================================
                        */
                        if (solveSudoku(board))
                            return true;   // FULL solution found → stop everything

                        /*
                        ==========================================================
                          STEP 5: BACKTRACK (Undo the decision)

                          If placing 'num' eventually led to a contradiction
                          deeper in the puzzle, then recursion returned FALSE.

                          That means:
                            → Our guess was WRONG.
                            → We must UNDO it (erase the number)
                            → And try the next number.

                          This is the heart of backtracking:
                            Make a move → Test → Undo if wrong.
                        ==========================================================
                        */
                        board[row][col] = '.';   // Undo wrong guess
                    }
                }

                /*
                =================================================================
                  If we tried ALL digits from '1' to '9' and NONE of them fit,
                  then this empty cell CANNOT be solved with the current board 
                  configuration.

                  This means:
                    → We made a wrong choice earlier in the board.
                    → We need to return FALSE to trigger backtracking 
                      in the previous recursive level.

                  Essentially this says:
                    "I cannot solve from this state,
                     go back and try a different number somewhere else."
                =================================================================
                */
                return false;   // No valid number found → backtrack required
            }
        }
    }

    /*
    =====================================================================
      If the loops finished AND we never found ANY empty cell,
      then the entire board is filled correctly.

      This means:
        → No '.' remained
        → No contradictions occurred
        → Sudoku is SOLVED

      So we return TRUE to signal success.
    =====================================================================
    */
    return true;
}




/*
====================================================================
  FUNCTION: printBoard
  PURPOSE : Print the 9×9 Sudoku grid.
====================================================================
*/
void printBoard(char board[9][9]) {
    cout << "-------------------------------------\n";
    for (int i = 0; i < 9; i++) {

        // Print row separators every 3 rows
        if (i % 3 == 0 && i != 0)
            cout << "-------------------------------------\n";

        for (int j = 0; j < 9; j++) {

            // Print column separators every 3 columns
            if (j % 3 == 0 && j != 0)
                cout << " | ";

            cout << " " << board[i][j];
        }
        cout << endl;
    }
    cout << "-------------------------------------\n";
}



/*
====================================================================
  MAIN FUNCTION
====================================================================
*/
int main() {

    // Initial unsolved Sudoku puzzle
    char board[9][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},

        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},

        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << "Solving Sudoku...\n\n";

    // Try solving
    if (solveSudoku(board)) {
        cout << "Solved Sudoku:\n";
        printBoard(board);
    } 
    else {
        cout << "No valid solution exists.\n";
    }

    return 0;
}
