#include <iostream>
using namespace std;

bool isTriangle(int a, int b, int c) {
    return (a + b > c && a + c > b && b + c > a);
}

int largestTrianglePerimeter(int arr[], int n) {
    int largest = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (isTriangle(arr[i], arr[j], arr[k])) {
                    int perimeter = arr[i] + arr[j] + arr[k];
                    if (perimeter > largest)
                        largest = perimeter;
                }
            }
        }
    }
    return largest;
}

int main() {
    int n;
    cout << "Enter total elements of array: ";
    cin >> n;

    int arr[200];
    for (int i = 0; i < n; i++) {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }

    int result = largestTrianglePerimeter(arr, n);
    if (result > 0)
        cout << "Largest perimeter: " << result << endl;
    else
        cout << "NO TRIANGLE" << endl;

    return 0;
}
