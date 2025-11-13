#include <iostream>
#include <string>
using namespace std;

bool check(string s, string p)
{
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '*')
        {
            int k;
            int c = i - 1;
            if (c == -1)
            {
                k = 0;
            }
            else
            {
                k = s[c];
            }
            p[i] = k;
        }
    }
    if (s.length() == p.length())
    {
        int tr = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == p[i])
            {
                tr++;
            }
            else if (p[i] == '.')
            {
                tr++;
            }
        }
        if (tr == s.length())
        {
            return true;
        }
    }

    return false;
}

int main()
{
    string s;
    cout << "Enter the main string: ";
    cin >> s;
    string p;
    cout << "Enter the pattern: ";
    cin >> p;
    if (check(s, p))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}