#include <iostream>
#include <string>
using namespace std;

int LLW(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        bool check = true;
        for (int j = 0; j < s.length(); j++)
            if (i != j && s[i] == s[j])
                check = false;
        if (check)
            return i;
    }
    return -1;
}

int main()
{
    string s;
    cout << "Enter the string: ";
    getline(cin, s);
    cout << LLW(s);
}

// Example 1:

// Input: s = "leetcode"

// Output: 0

// Explanation:

// The character 'l' at index 0 is the first character that does not occur at any other index.

// Example 2:

// Input: s = "loveleetcode"

// Output: 2

// Example 3:

// Input: s = "aabb"

// Output: -1