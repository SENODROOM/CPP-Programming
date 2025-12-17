#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    int count = 0;
    int i = 1;

    while (n >= i)
    {
        n -= i;
        count++;
        i++;
    }

    cout << count;
    return 0;
}
