#include <iostream>
using namespace std;

int LongestValidParenthesis(string s)
{
    int count = 0;
    int open = 0;
    for (char c : s)
    {
        if (c == '(')
            open++;
        else if (c == ')')
        {
            if (open > 0)
            {
                open--;
                count += 2;
            }
        }
    }

    return count;
}

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;
    cout << LongestValidParenthesis(s);
    return 0;
}
