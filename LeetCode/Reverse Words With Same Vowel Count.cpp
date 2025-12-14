#include <iostream>
#include <string>
using namespace std;

string p;

void r(string s, int i, int size, int vowels)
{
    while (i < size && s[i] == ' ')
    {
        p += s[i];
        i++;
    }

    if (i >= size) return;

    int count = 0;
    string temp = "";
    for (; i < size && s[i] != ' '; i++)
    {
        temp += s[i];
        if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
            s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
            count++;
    }

    if (count == vowels)
    {
        string temp2 = "";
        for (int j = temp.length()-1; j >= 0; j--)
            temp2 += temp[j];
        p += temp2;
    }
    else
    {
        p += temp;
    }

    r(s, i, size, vowels);
}

void reverseString(string s)
{
    int count = 0;
    int i = 0;
    int size = s.length();

    while (i < size && s[i] == ' ')
    {
        p += s[i];
        i++;
    }

    if (i >= size) return;

    string temp = "";
    for (; i < size && s[i] != ' '; i++)
    {
        temp += s[i];
        if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
            s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
            count++;
    }

    p += temp;

    r(s, i, size, count);
}

int main()
{
    string s;
    cout << "Enter the main string: ";
    getline(cin, s);

    reverseString(s);

    cout << p << endl;
    return 0;
}
