#include <iostream>
#include <string>
using namespace std;

int stringconvert(string s)
{
    int num = 0;
    bool negative = false;
    
    cout << "Input string: " << s << endl;
    
    int start_index = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            start_index = i;
            break;
        }
    }
    
    if (start_index == -1)
    {
        cout << "No valid number found" << endl;
        return 0;
    }
    
    if (s[start_index] == '-')
    {
        negative = true;
        start_index++; 
    }
    else if (s[start_index] == '+')
    {
        start_index++;
    }
    
    int end_index = start_index;
    for (int i = start_index; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            end_index = i;
        }
        else
        {
            break;
        }
    }
    
    for (int i = start_index; i <= end_index; i++)
    {
        num = num * 10 + (s[i] - '0');
    }
    
    if (negative)
    {
        num = -num;
    }
    
    return num;
}

int main()
{
    string s = "                              -123u8";
    int o = stringconvert(s);
    cout << "Converted number: " << o << endl;
    return 0;
}