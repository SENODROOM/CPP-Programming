#include <iostream>
using namespace std;

/*
    ============================================================
    LeetCode 258 - Add Digits
    ============================================================

    Problem:
    --------
    Given a non-negative integer num, repeatedly add all its digits
    until the result has only one digit.

    Example:
    --------
    Input: 38

    Step 1:
    3 + 8 = 11

    Step 2:
    1 + 1 = 2

    Output: 2

    ------------------------------------------------------------
    Approach Used Here:
    ------------------------------------------------------------
    We will use a LOOP-BASED approach (no math shortcut).

    Why?
    ----
    • Very easy to understand
    • Good for beginners
    • Matches interview expectations
    • Clearly shows logic

    ------------------------------------------------------------
    Key Concepts Used:
    ------------------------------------------------------------
    • Modulus operator (%) → extract last digit
    • Division (/) → remove last digit
    • While loops
    • Condition checking

    ------------------------------------------------------------
    Constraints:
    ------------------------------------------------------------
    • 0 <= num <= 2^31 - 1
    ============================================================
*/

int addDigits(int num)
{
    /*
        If the number is already a single digit,
        there is nothing to do.
        Example:
        num = 7 → answer is 7
    */
    if (num < 10)
        return num;

    /*
        Outer loop:
        This loop continues until num becomes
        a single digit (0 to 9).
    */
    while (num >= 10)
    {
        int sum = 0;

        /*
            Inner loop:
            Extract each digit of num and add it to sum.

            Example:
            num = 38

            Iteration 1:
            digit = 38 % 10 = 8
            sum = 0 + 8 = 8
            num = 38 / 10 = 3

            Iteration 2:
            digit = 3 % 10 = 3
            sum = 8 + 3 = 11
            num = 3 / 10 = 0

            Inner loop ends here
        */
        while (num > 0)
        {
            int digit = num % 10;  // Extract last digit
            sum = sum + digit;     // Add digit to sum
            num = num / 10;        // Remove last digit
        }

        /*
            After summing all digits,
            assign sum back to num.

            Example:
            sum = 11
            num = 11

            Then outer loop checks again:
            num >= 10 → true
        */
        num = sum;
    }

    /*
        At this point, num is guaranteed
        to be a single digit (0–9).

        Example:
        num = 2
    */
    return num;
}

int main()
{
    /*
        Driver code for testing.

        You can change the value of num
        to test different cases.
    */

    int num;

    cout << "Enter a non-negative number: ";
    cin >> num;

    int result = addDigits(num);

    cout << "Result after repeatedly adding digits: " << result << endl;

    return 0;
}
