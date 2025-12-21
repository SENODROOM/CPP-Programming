#include <iostream>
using namespace std;

/*
    ============================================================
    LeetCode 383 - Ransom Note
    ============================================================

    Problem Statement:
    ------------------
    Given two strings ransomNote and magazine,
    return true if ransomNote can be constructed by using
    the letters from magazine.

    Each letter in magazine can be used ONLY ONCE.

    ------------------------------------------------------------
    Important Notes:
    ------------------------------------------------------------
    • Only lowercase English letters ('a' to 'z')
    • Length of strings can be large
    • We must NOT use STL (vector, map, etc.)
    • We will use a simple integer array of size 26

    ------------------------------------------------------------
    Example:
    ------------------------------------------------------------
    ransomNote = "aa"
    magazine   = "aab"

    magazine count:
    a → 2
    b → 1

    ransomNote requires:
    a → 2

    Result → true
    ============================================================
*/

bool canConstruct(char ransomNote[], char magazine[])
{
    /*
        Step 1:
        Create an array to store frequency of characters
        from 'a' to 'z'.

        index 0 → 'a'
        index 1 → 'b'
        index 2 → 'c'
        ...
        index 25 → 'z'
    */
    int freq[26] = {0};

    /*
        Step 2:
        Count characters of magazine

        Example:
        magazine = "aab"

        freq['a' - 'a'] = freq[0] → 2
        freq['b' - 'a'] = freq[1] → 1
    */
    for (int i = 0; magazine[i] != '\0'; i++)
    {
        char ch = magazine[i];
        freq[ch - 'a']++;
    }

    /*
        Step 3:
        Try to build ransomNote using the frequency array

        For each character in ransomNote:
        - Reduce its count
        - If count becomes negative → impossible
    */
    for (int i = 0; ransomNote[i] != '\0'; i++)
    {
        char ch = ransomNote[i];
        freq[ch - 'a']--;

        /*
            If frequency becomes negative,
            it means magazine does not have enough
            of this character.
        */
        if (freq[ch - 'a'] < 0)
        {
            return false;
        }
    }

    /*
        If all characters were successfully matched,
        ransomNote can be constructed.
    */
    return true;
}

int main()
{
    /*
        Driver code to test the function.

        Using character arrays instead of string
        to avoid STL.
    */

    char ransomNote[1000];
    char magazine[1000];

    cout << "Enter ransom note: ";
    cin >> ransomNote;

    cout << "Enter magazine: ";
    cin >> magazine;

    bool result = canConstruct(ransomNote, magazine);

    if (result)
        cout << "true (Ransom note CAN be constructed)" << endl;
    else
        cout << "false (Ransom note CANNOT be constructed)" << endl;

    return 0;
}
