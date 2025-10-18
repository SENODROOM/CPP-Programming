#include <iostream>
using namespace std;

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int totalwaitingtime(int arr[], int n) {
    sortArray(arr, n);
    int total_waiting_time = 0;
    int current_wait = 0;

    for (int i = 0; i < n - 1; i++) {
        current_wait += arr[i];
        total_waiting_time += current_wait;
    }

    return total_waiting_time;
}

void minimalschedule(int arr[], int n) {
    sortArray(arr, n);
    cout << "Minimal Schedule (Shortest Job First): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int jobs[] = {4, 5, 2};
    int n = sizeof(jobs) / sizeof(jobs[0]);

    minimalschedule(jobs, n);

    int result = totalwaitingtime(jobs, n);
    cout << "Minimal Total Waiting Time: " << result << endl;

    return 0;
}
