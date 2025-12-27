#include <iostream>
using namespace std;

int Pivot(int num)
{
    if (num == 1)
        return 1;

    for (int i = 1; i < num; i++)
    {
        int left = 0, right = 0;
        for (int j = 1; j <= i; j++)
            left += j;
        for (int j = i; j <= num; j++)
            right += j;
        if (left == right)
            return i;
    }

    return -1;
}

int main()
{
    int user;
    cout << "Enter the number: ";
    cin >> user;
    cout << Pivot(user);

    return 0;
}