#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter number of students: ";
    cin >> N;

    int count = 0;
    float sum = 0, grade;

    for (int i = 1; i <= N; i++) {
        cout << "Enter grade for student " << i << ": ";
        cin >> grade;

        if (grade >= 0 && grade <= 100) {
            sum += grade;
            count++;
        } else {
            cout << "Invalid grade! Skipped.\n";
        }
    }

    if (count > 0)
        cout << "Average grade = " << sum / count << ", Valid grades entered = " << count << endl;
    else
        cout << "No valid grades entered.\n";

    return 0;
}