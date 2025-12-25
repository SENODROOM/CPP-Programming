#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

// --------------------------------------------------
// Function to convert number to Excel column title
// --------------------------------------------------
string convertToTitle(int columnNumber)
{
    // --------------------------------------------------
    // This string will store the final result
    // --------------------------------------------------
    string result = "";

    // --------------------------------------------------
    // Continue until columnNumber becomes zero
    // --------------------------------------------------
    while (columnNumber > 0)
    {
        // --------------------------------------------------
        // Subtract 1 to handle 1-based indexing
        // --------------------------------------------------
        columnNumber = columnNumber - 1;

        // --------------------------------------------------
        // Get remainder in range 0–25
        // --------------------------------------------------
        int remainder = columnNumber % 26;

        // --------------------------------------------------
        // Convert remainder to corresponding character
        // --------------------------------------------------
        char letter = char('A' + remainder);

        // --------------------------------------------------
        // Add character at the beginning of result
        // --------------------------------------------------
        result = letter + result;

        // --------------------------------------------------
        // Reduce the column number
        // --------------------------------------------------
        columnNumber = columnNumber / 26;
    }

    // --------------------------------------------------
    // Return the final Excel column title
    // --------------------------------------------------
    return result;
}

int main()
{
    int arr[100];
    int user;
    cout << "Enter colnumber: ";
    cin >> user;
    cout << convertToTitle(user);

    return 0;
}