#include <iostream>
#include <string>
using namespace std;

int LongestSubstring(string st, string nd)
{
    int length = st.length();
    int nlength = nd.length();

    for (int i = 0; i <= length - nlength; i++)
    {
        int check = 0;
        for (int j = 0; j < nlength; j++)
        {
            if (st[i + j] == nd[j])
                check++;
        }
        if (check == nlength)
            return i;
    }
    return -1;
}

int main()
{
    string s, n;
    cout << "Enter the haystack: ";
    getline(cin, s); 
    cout << "Enter the needle: ";
    getline(cin, n); 

    cout << LongestSubstring(s, n);
}
