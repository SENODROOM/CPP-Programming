#include <iostream>
using namespace std;

int main() {
    int n; // number of arrays
    cout << "Enter number of arrays: ";
    cin >> n;

    int sizes[10];       // store sizes of each array, assuming max 10 arrays
    int arr[10][100];    // store the arrays, assuming max size 100

    // Read arrays
    for (int i = 0; i < n; i++) {
        cout << "Enter size of array " << i + 1 << ": ";
        cin >> sizes[i];
        for (int j = 0; j < sizes[i]; j++) {
            cout << "Enter element arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    int freq[101] = {0}; // frequency array for numbers 1..100

    // Count occurrences in each array
    for (int i = 0; i < n; i++) {
        int temp[101] = {0}; // to avoid counting duplicates in same array
        for (int j = 0; j < sizes[i]; j++) {
            temp[arr[i][j]] = 1;
        }
        for (int k = 1; k <= 100; k++) {
            freq[k] += temp[k];
        }
    }

    // Print elements that appear in all arrays
    cout << "[";
    bool first = true;
    for (int i = 1; i <= 100; i++) {
        if (freq[i] == n) { // present in all arrays
            if (!first) cout << ",";
            cout << i;
            first = false;
        }
    }
    cout << "]" << endl;

    return 0;
}














// Example 1:

// Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
// Output: [3,4]
// Explanation: 
// The only integers present in each of nums[0] = [3,1,2,4,5], nums[1] = [1,2,3,4], and nums[2] = [3,4,5,6] are 3 and 4, so we return [3,4].
// Example 2:

// Input: nums = [[1,2,3],[4,5,6]]
// Output: []
// Explanation: 
// There does not exist any integer present both in nums[0] and nums[1], so we return an empty list [].
