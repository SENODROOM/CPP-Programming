#include <iostream>
using namespace std;

bool checkPalindrome(string s)
{
    string revs = "";
    for (int i = s.length() - 1; i >= 0; i--)
    {
        revs += s[i];
    }
    if (revs == s)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void LongestPalindrome(string st)
{
    string palindromes[100];
    int count = 0;

    for (int i = 0; i < st.length(); i++)
    {
        string value = "";
        for (int j = 0; j <= i; j++)
        {
            value += st[j];
        }

        for (int k = 0; k < value.length(); k++)
        {
            string val = "";
            for (int z = k; z < value.length(); z++)
            {
                val += value[z]; 
            }
            bool check = checkPalindrome(val);
            if (check)
            {
                palindromes[count] = val;
                count++;
            }
        }
    }

    string longest = palindromes[0];
    for (int i = 0; i < count; i++)
    {
        if (palindromes[i].length() > longest.length())
        {
            longest = palindromes[i];
        }
    }
    cout << longest;
}

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;
    LongestPalindrome(s);
}
