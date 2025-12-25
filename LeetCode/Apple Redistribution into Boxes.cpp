#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int apple[100];
    int user;
    cout << "Enter total apple: ";
    cin >> user;
    for (int i = 0; i < user; i++)
    {
        cout << "Enter apple[" << i << "]: ";
        cin >> apple[i];
    }
    int capacity[100];
    int user2;
    cout << "Enter total capacity: ";
    cin >> user2;
    for (int i = 0; i < user2; i++)
    {
        cout << "Enter capacity[" << i << "]: ";
        cin >> capacity[i];
    }

    int appleSize = user;
    int capacitySize = user2;

    /*
        ---------------------------------
        STEP 1: Calculate total apples
        ---------------------------------
        We must store ALL apples in boxes
    */

    int totalApples = 0;

    for (int i = 0; i < appleSize; i++)
    {
        totalApples = totalApples + apple[i];
    }

    /*
        Example calculation:
        --------------------
        1 + 3 + 2 = 6 apples
    */

    /*
        ---------------------------------
        STEP 2: Sort capacities (DESC)
        ---------------------------------
        Why?
        ----
        Using bigger boxes first reduces
        the total number of boxes needed.
    */

    sort(capacity, capacity + capacitySize, greater<int>());

    /*
        After sorting:
        capacity = [5, 4, 3, 2, 1]
    */

    /*
        ---------------------------------
        STEP 3: Use boxes one by one
        ---------------------------------
        Subtract capacity from apples
        until apples become <= 0
    */

    int boxesUsed = 0;

    for (int i = 0; i < capacitySize; i++)
    {
        if (totalApples <= 0)
        {
            break; // all apples placed
        }

        totalApples = totalApples - capacity[i];
        boxesUsed = boxesUsed + 1;
    }

    /*
        Example walkthrough:
        --------------------
        Apples = 6

        Use box 5  → apples = 1 → boxes = 1
        Use box 4  → apples = -3 → boxes = 2

        Done.
    */

    /*
        ---------------------------------
        STEP 4: Output result
        ---------------------------------
    */

    cout << "Minimum boxes needed: " << boxesUsed << endl;

    /*
        ---------------------------------
        TIME COMPLEXITY:
        ---------------------------------
        Sorting: O(n log n)
        Looping: O(n)

        Overall: O(n log n)

        ---------------------------------
        SPACE COMPLEXITY:
        ---------------------------------
        O(1) (no extra data structures)
    */

    return 0;
}
