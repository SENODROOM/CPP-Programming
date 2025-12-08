#include <iostream>
using namespace std;

void combinesort(int arr1[], int arr2[], int size1, int size2) {
    int total = size1 + size2;
    int arr3[200];
    for (int i = 0; i < size1; i++) {
        arr3[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        arr3[size1 + i] = arr2[i];
    }
    for (int k = 0; k < total; k++) {
        for (int m = k + 1; m < total; m++) {
            if (arr3[m] < arr3[k]) {
                int temp = arr3[k];
                arr3[k] = arr3[m];
                arr3[m] = temp;
            }
        }
    }
    cout << "[";
    for (int i = 0; i < total; i++) {
        cout << arr3[i];
        if (i < total - 1)
            cout << ",";
    }
    cout << "]";
}

int main() {
    int user;
    int arr[200];
    cout << "Enter the size of your array: ";
    cin >> user;
    for (int i = 0; i < user; i++) {
        cout << "Enter arr1[" << i << "]: ";
        cin >> arr[i];
    }

    int user2;
    int arr2[200];
    cout << "Enter the size of your second array: ";
    cin >> user2;
    for (int i = 0; i < user2; i++) {
        cout << "Enter arr2[" << i << "]: ";
        cin >> arr2[i];
    }

    combinesort(arr, arr2, user, user2);
}
