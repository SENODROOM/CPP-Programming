#include <iostream>
using namespace std;

bool isDuplicate(int res[][3], int resSize, int a, int b, int c) {
    for (int i = 0; i < resSize; i++) {
        int x = res[i][0], y = res[i][1], z = res[i][2];
        if ((a == x || a == y || a == z) &&
            (b == x || b == y || b == z) &&
            (c == x || c == y || c == z)) {
            return true;
        }
    }
    return false;
}

void Sum3(int arr[], int size) {
    int res[100][3];
    int resSize = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j != i) {
                for (int k = 0; k < size; k++) {
                    if (k != i && k != j) {
                        if (arr[i] + arr[j] + arr[k] == 0) {
                            int a = arr[i], b = arr[j], c = arr[k];
                            if (!isDuplicate(res, resSize, a, b, c)) {
                                res[resSize][0] = a;
                                res[resSize][1] = b;
                                res[resSize][2] = c;
                                resSize++;
                                cout << "[" << a << "," << b << "," << c << "]" << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, -3, -4, -1};
    Sum3(arr, 6);

    return 0;
}
