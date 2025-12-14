#include <iostream>
#include <string>
using namespace std;

// Function to check if string s matches pattern p
// '?' matches any single character
// '*' matches any sequence of characters (including empty)
bool isMatch(string s, string p)
{
    int n = s.size();  // Length of input string
    int m = p.size();  // Length of pattern
    bool dp[200][200]; // DP table: dp[i][j] = true if first i chars of s match first j chars of p

    // Initialize DP table to false
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = false;

    dp[0][0] = true; // Empty string matches empty pattern

    // Handle patterns like "*", "**", "***" that can match empty string
    for (int j = 1; j <= m; j++)
    {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1]; // '*' can match empty, so inherit value from left
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
            {
                // If current chars match or pattern has '?', take diagonal value
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                // '*' can match zero characters (dp[i][j-1]) or one/more characters (dp[i-1][j])
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            }
            else
            {
                // Characters do not match and pattern is not '?' or '*'
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m]; // Return if full string matches full pattern
}

int main()
{
    string s, p;
    cout << "Enter the main string: ";
    cin >> s;
    cout << "Enter the pattern: ";
    cin >> p;
    cout << (isMatch(s, p) ? "true" : "false") << endl;
    return 0;
}

/*
Example:

s = "abcd"
p = "a*d"

Step by step:

1. dp[0][0] = true
2. '*' in pattern at position 2 can match empty string, so dp[0][2] = true
3. Now we fill the table:
   - 'a' matches 'a' -> dp[1][1] = true
   - '*' can match remaining chars 'bc' -> dp[2][2] = true, dp[3][2] = true
   - 'd' matches 'd' -> dp[4][3] = true
4. Final dp[n][m] = dp[4][4] = true

Output: true
*/
