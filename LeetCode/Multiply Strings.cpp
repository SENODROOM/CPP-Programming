#include <iostream>
using namespace std;

int main()
{
    // Input strings representing non-negative integers
    string num1, num2;
    cout << "Enter num1: ";
    cin >> num1;
    cout << "Enter num2: ";
    cin >> num2;

    // If either number is "0", product will be "0"
    if (num1 == "0" || num2 == "0")
    {
        cout << "0";
        return 0;
    }

    // Length of both numbers
    int n = num1.size();
    int m = num2.size();

    // Result array to store multiplication values
    // Maximum size = n + m (e.g., 999 × 999 → 998001 → 6 digits)
    int result[400] = {0};

    /*
        We multiply digits exactly like manual multiplication:

        num1 = 123
        num2 = 456

            123
          × 456
          ------
            738
           615
          492
          ------
          56088
    */

    // Example:
    // num1 = "123"  (n = 3)
    // num2 = "45"   (m = 2)
    //
    // result array size = n + m = 5
    // Initial result = [0, 0, 0, 0, 0]
    // Indexes:            0  1  2  3  4

    // Traverse num1 from right to left (least significant digit first)
    for (int i = n - 1; i >= 0; i--)
    {
        // Traverse num2 from right to left
        for (int j = m - 1; j >= 0; j--)
        {
            // Convert characters to digits and multiply
            // Example: num1[i] = '3', num2[j] = '5'
            // mul = 3 * 5 = 15
            int mul = (num1[i] - '0') * (num2[j] - '0');

            // Add the value already present at result[i + j + 1]
            // i = 2, j = 1 → i + j + 1 = 4
            // sum = 15 + result[4] (initially 0)
            // sum = 15
            int sum = mul + result[i + j + 1];

            // Store the unit digit at position i + j + 1
            // result[4] = 15 % 10 = 5
            result[i + j + 1] = sum % 10;

            // Carry goes to the previous position (i + j)
            // result[3] += 15 / 10 = 1
            result[i + j] += sum / 10;

            /*
            After first multiplication (3 × 5):
            result = [0, 0, 0, 1, 5]
            */
        }
    }

    /*
    Continuing the process:

    3 × 4 = 12
    → result becomes [0, 0, 1, 3, 5]

    2 × 5 = 10
    → result becomes [0, 0, 2, 3, 5]

    2 × 4 = 8
    → result becomes [0, 1, 0, 3, 5]

    1 × 5 = 5
    → result becomes [0, 1, 5, 3, 5]

    1 × 4 = 4
    → result becomes [0, 5, 5, 3, 5]

    Final result array:
    [0, 5, 5, 3, 5]

    Ignoring leading zero → "5535"
    So, 123 × 45 = 5535
    */

    /*
        Result array example for 123 × 456:
        [0, 5, 6, 0, 8, 8]

        Leading zero must be skipped
    */

    // Skip leading zeros
    int i = 0;
    while (i < n + m && result[i] == 0)
        i++;

    // Print remaining digits as the final result
    for (; i < n + m; i++)
        cout << result[i];

    return 0;
}
