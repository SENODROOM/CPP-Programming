#include <iostream>
#include <algorithm>
using namespace std;

int MSFD(int num)
{
    int sum = 0;
    int sum2 = 0;
    int lower = num % 100;
    int upper = num / 100;
    int ll = lower % 10;
    int lp = lower / 10;
    int ul = upper % 10;
    int up = upper / 10;
    int arr[4] = {ll, lp, ul, up};
    sort(arr, arr + 4);
    sum += arr[0] * 10 + arr[3];
    sum += arr[2] + arr[1] * 10;
    return sum;
}
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << MSFD(n);

    return 0;
}

// Example 1:

// Input: num = 2932
// Output: 52
// Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
// The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.
// Example 2:

// Input: num = 4009
// Output: 13
// Explanation: Some possible pairs [new1, new2] are [0, 49], [490, 0], etc.
// The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.