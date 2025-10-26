#include <iostream>
using namespace std;

int reversesum(int nums1[], int n1)
{
    int sum1 = 0;
    for (int i = n1; i > 0; i--)
    {
        int length = 1;
        for (int j = i - 1; j > 0; j--)
        {
            length = length * 10;
        }
        int digit = nums1[i - 1] * length;
        sum1 = sum1 + digit;
    }
    return sum1;
}

int main()
{
    int nums1[3] = {2, 7, 1};
    int nums2[3] = {5, 4, 3};
    int n1 = sizeof(nums1) / sizeof(int);
    int n2 = sizeof(nums2) / sizeof(int);

    int sum1 = reversesum(nums1, n1);
    int sum2 = reversesum(nums2, n2);

    int total = sum1 + sum2;

    // Count digits
    int temp = total, len = 0;
    while (temp > 0)
    {
        temp /= 10;
        len++;
    }

    int sumarr[len];
    for (int i = len - 1; i >= 0; i--)
    {
        sumarr[i] = total % 10;
        total /= 10;
    }

    cout << '{';
    for (int i = 0; i < len; i++)
    {
        cout << sumarr[i];
        if (i != len - 1)
            cout << ',';
    }
    cout << '}';

    return 0;
}
