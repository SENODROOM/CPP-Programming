#include <iostream>
using namespace std;

void ZigZag(char s[], int numRows)
{
    int ch = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        ch++;
    }
    cout << "Length: " << ch << endl;

    if (numRows == 1)
    {
        cout << s;
        return;
    }

    int gap = numRows - 1;

    // First row
    for (int i = 0; i < ch; i = i + 2 * gap)
    {
        cout << s[i];
        for (int j = 0; j < gap - 1; j++)
        {
            cout << ' ';
        }
    }
    cout << endl;

    // Middle rows
    for (int row = 1; row < numRows - 1; row++)
    {
        int i = row;
        while (i < ch)
        {
            cout << s[i];
            
            // Calculate spaces after first character
            int spaces_after_first = gap - row - 1;
            for (int j = 0; j < spaces_after_first; j++)
            {
                cout << ' ';
            }
            
            // Print second character if exists
            int second_char_pos = i + 2 * gap - 2 * row;
            if (second_char_pos < ch)
            {
                cout << s[second_char_pos];
            }
            
            // Calculate spaces after second character
            int spaces_after_second = row - 1;
            for (int j = 0; j < spaces_after_second; j++)
            {
                cout << ' ';
            }
            
            i += 2 * gap;
        }
        cout << endl;
    }

    // Last row
    for (int i = gap; i < ch; i = i + 2 * gap)
    {
        cout << s[i];
        for (int j = 0; j < gap - 1; j++)
        {
            cout << ' ';
        }
    }
    cout << endl;
}

int main()
{
    char s[] = "PAYPALISHIRING";
    int numRows = 4;
    ZigZag(s, numRows);
    return 0;
}