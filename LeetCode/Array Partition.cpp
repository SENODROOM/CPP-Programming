#include <iostream>
using namespace std;

// Simple bubble sort for demonstration
void sortArray(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int arrayPairSum(int arr[], int n) {
    sortArray(arr, n);
    int sum = 0;
    for (int i = 0; i < n; i += 2) {
        sum += arr[i]; // always take the smaller element in each sorted pair
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter the number of pairs (n): ";
    cin >> n;
    int size = 2 * n;
    int arr[200];
    
    cout << "Enter the array of " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int result = arrayPairSum(arr, size);
    cout << "Maximized sum of min pairs: " << result << endl;
    
    return 0;
}
