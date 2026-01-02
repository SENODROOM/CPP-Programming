#include <iostream>
using namespace std;

/*
    Function: reverseBits
    Purpose:
        Reverses all 32 bits of an unsigned integer.

    Parameter:
        n -> 32-bit unsigned integer

    Return:
        Unsigned integer after reversing its bits
*/
unsigned int reverseBits(unsigned int n)
{
    // This variable will store the reversed result
    unsigned int reversed = 0;

    /*
        We must process exactly 32 bits because:
        - Unsigned integer has 32 bits
        - Leading zeros are also important
    */
    for (int i = 0; i < 32; i++)
    {
        /*
            Step 1:
            Extract the last bit of n

            Example:
            n = 13  -> 1101
            n % 2 = 1
        */
        unsigned int lastBit = n % 2;

        /*
            Step 2:
            Shift reversed to the left to make space

            Example:
            reversed = 2 -> 10
            reversed << 1 -> 100
        */
        reversed = reversed << 1;

        /*
            Step 3:
            Add the extracted bit

            If lastBit = 1, it becomes the new LSB
            If lastBit = 0, nothing changes
        */
        reversed = reversed + lastBit;

        /*
            Step 4:
            Remove last bit from n

            Example:
            n = 13 -> 1101
            n / 2 -> 110
        */
        n = n / 2;
    }

    // Return the fully reversed number
    return reversed;
}

int main()
{
    /*
        Example input:
        43261596
        Binary:
        00000010100101000001111010011100
    */
    unsigned int n;

    // Take input from user
    cout << "Enter an unsigned integer: ";
    cin >> n;

    // Call reverseBits function
    unsigned int answer = reverseBits(n);

    // Display the reversed result
    cout << "Reversed bits result: " << answer << endl;

    return 0;
}
