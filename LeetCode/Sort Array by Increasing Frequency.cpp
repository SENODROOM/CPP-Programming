#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of your array: ";
    cin >> n;
    int nums[100];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr1[" << i << "]: ";
        cin >> nums[i];
    }

    int freq[201] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[nums[i] + 100]++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int freq_i = freq[nums[i] + 100];
            int freq_j = freq[nums[j] + 100];

            if (freq_i > freq_j || (freq_i == freq_j && nums[i] < nums[j]))
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << nums[i];
        if (i != n - 1)
            cout << ",";
    }

    return 0;
}
