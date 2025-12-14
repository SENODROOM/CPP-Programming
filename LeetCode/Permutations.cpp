#include <iostream>
using namespace std;

// Function to swap two numbers
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Recursive function to generate permutations
void permute(int arr[], int start, int end) {
    // Base case: if start index reaches end, print the permutation
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    // Loop through each element starting from 'start'
    for (int i = start; i <= end; i++) {
        // Swap current element with start
        swap(arr[start], arr[i]);

        // Recur for the next position
        permute(arr, start + 1, end);

        // Backtrack: undo the swap for next iteration
        swap(arr[start], arr[i]);
    }
}

int main() {
    int n;

    // Ask user for number of elements
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100]; // Array to store elements

    // Input array elements
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "All permutations:\n";
    // Call permute function from index 0 to n-1
    permute(arr, 0, n - 1);

    return 0;
}