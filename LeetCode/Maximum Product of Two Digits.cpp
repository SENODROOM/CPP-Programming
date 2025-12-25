#include <iostream>
using namespace std;
int find(int num)
{
    int max = 0;
    int sec = 0;
    for (int i = num; i > 0; i /= 10)
    {
        if (i % 10 > max)
        {
            sec = max;
            max = i % 10;
        }
        else if (i % 10 <= max && i % 10 > sec)
            sec = i % 10;
    }
    return max * sec;
}
int main()
{
    int user;
    cout << "Enter total elements: ";
    cin >> user;
    cout << find(user);
    return 0;
}