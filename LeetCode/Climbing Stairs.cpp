#include <iostream>
using namespace std;

int climbStairs(int n)
{
    if (n == 1)
        return 1;

    int first = 1;  
    int second = 2; 
    int current;

    for (int i = 3; i <= n; i++)
    {
        current = first + second;
        first = second;  
        second = current;
    }

    return second;
}

int main()
{
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    int result = climbStairs(n);
    cout << "Number of distinct ways to climb to the top: " << result << endl;

    return 0;
}
