#include <iostream>
using namespace std;

int leastFrequentDigit(int n)
{
    int freq[10] = {0};

    while (n > 0)
    {
        freq[n % 10]++;
        n /= 10;
    }

    int minFreq = 1e9;
    int digit = -1;

    for (int i = 0; i < 10; i++)
    {
        if (freq[i] > 0 && freq[i] < minFreq)
        {
            minFreq = freq[i];
            digit = i;
        }
    }

    return digit;
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    cout << leastFrequentDigit(n);
    return 0;
}



// Example 1:

// Input: n = 1553322

// Output: 1

// Explanation:

// The least frequent digit in n is 1, which appears only once. All other digits appear twice.

// Example 2:

// Input: n = 723344511

// Output: 2

// Explanation:

// The least frequent digits in n are 7, 2, and 5; each appears only once.

 