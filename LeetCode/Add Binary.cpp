#include <iostream>
#include <string>
using namespace std;

int main()
{
    char arr1[200], arr2[200];
    cout << "Enter first binary: ";
    cin.getline(arr1, 200);
    cout << "Enter second binary: ";
    cin.getline(arr2, 200);

    int count1 = 0, count2 = 0;
    while (arr1[count1] != '\0')
        count1++;
    while (arr2[count2] != '\0')
        count2++;

    int maxlen = max(count1, count2);
    char arr3[201]; 
    arr3[maxlen] = '\0';
    bool carry = false;

    for (int i = 0; i < maxlen; i++)
    {
        int bit1 = (count1 - 1 - i >= 0) ? arr1[count1 - 1 - i] - '0' : 0;
        int bit2 = (count2 - 1 - i >= 0) ? arr2[count2 - 1 - i] - '0' : 0;
        int sum = bit1 + bit2 + carry;
        arr3[maxlen - 1 - i] = (sum % 2) + '0';
        carry = sum / 2;
    }

    if (carry)
    {
        for (int i = maxlen; i > 0; i--)
            arr3[i] = arr3[i - 1];
        arr3[0] = '1';
        arr3[maxlen + 1] = '\0';
    }

    cout << "Sum: " << arr3 << endl;
    return 0;
}
