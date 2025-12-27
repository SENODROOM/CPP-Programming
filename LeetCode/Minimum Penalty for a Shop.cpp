#include <iostream>
#include <climits> // For INT_MAX

using namespace std;

int bestClosingTime(char c[], int n) {
    int LN = 0;        // Count of 'N's before current hour
    int totaly = 0;    // Total 'Y's in the entire log

    // Count total 'Y's
    for (int i = 0; i < n; i++) {
        if (c[i] == 'Y') totaly++;
    }

    int Y = 0;         // 'Y's before current hour
    int mpen = INT_MAX; // Minimum penalty
    int ans = 0;       // Best closing hour

    for (int i = 0; i < n; i++) {
        int RY = totaly - Y; // Remaining 'Y's after current hour
        int penalty = RY + LN;
        if (penalty < mpen) {
            ans = i;
            mpen = penalty;
        }

        if (c[i] == 'Y') Y++;
        if (c[i] == 'N') LN++;
    }

    // Check for closing after the last hour
    int RY = totaly - Y;
    int penalty = RY + LN;
    if (penalty < mpen) {
        ans = n;
    }

    return ans;
}

int main() {
    char c[1000]; // Maximum size of customer log
    cin >> c;

    int length = 0;
    while (c[length] != '\0') length++; // Calculate length manually

    int result = bestClosingTime(c, length);
    cout << result << endl;

    return 0;
}
