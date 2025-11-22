#include <iostream>
#include<string>
using namespace std;

void LetterComb(string dg)
{
    int total = 0;
    for (int i = 0; dg[i] != '\0'; i++)
    {
        total++;
    }

    string values[] = {"", "", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    cout << "[";
    for (int i = 0; i < total; i++)
    {
        int num= to_integer(dg[i]);
        cout << '[';
        for (int j = 0; j < values[num].length() ; j++)
        {
            if (i!=j)
            {
                cout << values[num][j];
                if (j!=values[num].length()-1)
                {
                    cout << ",";
                }
                
            }
            
        }
        cout << ']';
    }
    cout << "]";

}

int main()
{
    string digits = "23";
    LetterComb(digits);
    return 0;
}