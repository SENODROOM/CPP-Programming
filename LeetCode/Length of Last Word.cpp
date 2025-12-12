#include <iostream>
#include <string>
using namespace std;

int LLW(string s)
{
    bool started = false; 
    int count = 0;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            started = true;
            count++;
        }
        else
        {
            if (started)
                break;
        }
    }

    return count;
}

int main()
{
    string s;
    cout << "Enter the string: ";
    getline(cin, s);
    cout << LLW(s);
}
