#include <iostream>
#include <string>
using namespace std;

// Function to generate the nth term of the Count-and-Say sequence
string countAndSay(int n) {
    // Base case: the first term is always "1"
    if (n == 1) return "1";

    // Recursively get the previous term (n-1)
    string prev = countAndSay(n - 1);

    // String to store the current term
    string result = "";

    // Loop through the previous term to generate the current term
    for (int i = 0; i < prev.size(); ) {
        char current = prev[i];  // Current digit we are counting
        int count = 0;           // Count consecutive occurrences of current digit

        // Count how many times 'current' repeats consecutively
        while (i < prev.size() && prev[i] == current) {
            i++;
            count++;
        }

        // Append the count and the digit to the result string
        result += to_string(count) + current;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Term " << n << " of Count-and-Say sequence: " << countAndSay(n) << endl;
}
