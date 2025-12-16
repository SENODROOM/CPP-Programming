#include <iostream>
using namespace std;

char FTD(char arr1[], char arr2[])
{
    int freq1[256] = {0};
    int freq2[256] = {0};

    for (int i = 0; arr1[i] != '\0'; i++)
        freq1[arr1[i]]++;

    for (int i = 0; arr2[i] != '\0'; i++)
        freq2[arr2[i]]++;

    for (int i = 0; i < 256; i++)
    {
        if (freq2[i] > freq1[i])
            return char(i);
    }

    return '\0';
}

int main()
{
    char arr[20];
    cout << "Enter name: ";
    cin.getline(arr, 20);
    char arr2[20];
    cout << "Enter name: ";
    cin.getline(arr2, 20);
    cout << FTD(arr, arr2);

    return 0;
}