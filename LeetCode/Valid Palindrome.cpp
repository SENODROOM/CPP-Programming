#include <iostream>
#include <string>
using namespace std;

string removecharacters(const string &s)
{
    string s2;
    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            s2.push_back(c);
        }
    }
    return s2;
}

string reversestring(const string &s)
{
    string s2;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        s2.push_back(s[i]);
    }
    return s2;
}

// Check if string is palindrome after filtering
bool isValid(const string &s)
{
    string filtered = removecharacters(s);
    return reversestring(filtered) == filtered;
}

int main()
{
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    if (isValid(s))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
