#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    cout << "Unique pairs: ";
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            cout << "(" << i << ", " << j << ")";
            if (!(i == N - 1 && j == N))
                cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
