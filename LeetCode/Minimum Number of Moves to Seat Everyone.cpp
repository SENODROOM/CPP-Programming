#include <iostream>
using namespace std;

// Function to sort an array using bubble sort
// Bubble sort repeatedly swaps adjacent elements if they are in the wrong order
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    { // Outer loop for number of passes
        for (int j = 0; j < n - i - 1; j++)
        { // Inner loop for comparing adjacent elements
            if (arr[j] > arr[j + 1])
            { // If current element is greater than next
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to calculate the minimum number of moves required
int minMovesToSeat(int seats[], int students[], int n)
{
    // Step 1: Sort both arrays so that smallest student goes to smallest seat
    // This ensures the total moves are minimized
    bubbleSort(seats, n);
    bubbleSort(students, n);

    int moves = 0; // Initialize total moves to 0

    // Step 2: Calculate the absolute difference between each student and seat
    for (int i = 0; i < n; i++)
    {
        // Absolute difference: |seat position - student position|
        moves += (seats[i] > students[i]) ? (seats[i] - students[i]) : (students[i] - seats[i]);
    }

    return moves; // Return the total minimum moves
}

int main()
{
    int n;
    cout << "Enter number of seats/students: ";
    cin >> n; // Input the number of seats/students

    int seats[100], students[100]; // Arrays to store seat and student positions

    // Input seat positions
    cout << "Enter seat positions: ";
    for (int i = 0; i < n; i++)
        cin >> seats[i];

    // Input student positions
    cout << "Enter student positions: ";
    for (int i = 0; i < n; i++)
        cin >> students[i];

    // Call function to calculate minimum moves
    int result = minMovesToSeat(seats, students, n);

    // Output the result
    cout << "Minimum number of moves: " << result << endl;

    return 0; // Program ends
}
