#include <iostream>
#include <string>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;

    int count[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
            return false;
    }

    return true;
}

int main()
{
    string s, t;
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the string: ";
    cin >> t;

    if (isAnagram(s, t))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
