#include <iostream>
using namespace std;


// Both Decalaration are same
// void combineArrays(int *a, int *b, int size1, int size2, int *c)
void combineArrays(int a[], int b[], int size1, int size2, int c[]){

    for (int i = 0; i < size1; i++) {
        c[i] = a[i];
    }

    for (int i = 0; i < size2; i++) {
        c[size1 + i] = b[i];
    }
}

int main() {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {5, 6, 7, 9, 10};
    int n1 = sizeof(arr1) / sizeof(int);
    int n2 = sizeof(arr2) / sizeof(int);

    int arr3[n1 + n2]; 

    combineArrays(arr1, arr2, n1, n2, arr3);

    cout << "Combined Array: ";
    for (int i = 0; i < n1 + n2; i++) {
        cout << arr3[i] << " ";
    }

    return 0;
}