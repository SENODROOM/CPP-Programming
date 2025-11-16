#include <iostream>
using namespace std;

void longeststr(string str[], int size)
{
    string lg;
    int smallest = str[0].length();
    for (int i = 0; i < size; i++)
    {
        if (smallest > str[i].length())
        {
            smallest = str[i].length();
        }
    }
    int total = 0;
    for (int i = 0; i < smallest; i++)
    {
        int arr[size];
        for (int j = 0; j < size; j++)
        {
            arr[j] = str[j][i];
        }
        int check = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[0] == arr[i])
            {
                check++;
            }
        }
        if (check == size)
        {
            total++;
        }
    }
    cout << "Largest Prefix: " ;
    for (int i = 0; i < total; i++)
    {
        cout << str[0][i];
    }
}

int main()
{
    string strs[] = {"flower", "flow", "floght"};
    longeststr(strs, 3);
    return 0;
}