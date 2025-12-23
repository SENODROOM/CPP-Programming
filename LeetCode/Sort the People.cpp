#include <iostream>
using namespace std;

int main()
{
    string names[200];
    int n;
    cout << "Enter total names: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter names[" << i << "]: ";
        cin >> names[i];
    }
    int heights[200];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter heights[" << i << "]: ";
        cin >> heights[i];
    }

    /*
        ================================
        BUBBLE SORT (DESCENDING HEIGHT)
        ================================

        Bubble Sort works by:
        - Comparing adjacent elements
        - Swapping if order is wrong
        - Repeating until sorted
    */

    // Outer loop controls number of passes
    for (int i = 0; i < n - 1; i++)
    {
        /*
            Inner loop compares adjacent elements
            After every pass, one largest element
            moves to its correct position
        */
        for (int j = 0; j < n - i - 1; j++)
        {
            /*
                If current height is smaller than next height,
                swap them to maintain descending order
            */
            if (heights[j] < heights[j + 1])
            {
                // -------- SWAP HEIGHTS --------
                int tempHeight = heights[j];
                heights[j] = heights[j + 1];
                heights[j + 1] = tempHeight;

                /*
                    VERY IMPORTANT:
                    Height and name belong to same person
                    So we MUST swap names also
                */

                // -------- SWAP NAMES --------
                string tempName = names[j];
                names[j] = names[j + 1];
                names[j + 1] = tempName;
            }
        }
    }
    // Print final sorted names
    cout << "Sorted people by height (descending):\n";
    for (int i = 0; i < n; i++)
    {
        cout << names[i];
        if (i != n - 1)
            cout << ",";
    }

    return 0;
}
