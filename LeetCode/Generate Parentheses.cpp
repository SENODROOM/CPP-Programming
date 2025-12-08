#include <iostream>
using namespace std;

void generateParentheses(int n, string current = "", int open = 0, int close = 0) {
    if (current.length() == 2 * n) {
        cout << current << endl;
        return;
    }
    if (open < n) {
        generateParentheses(n, current + "(", open + 1, close);
    }
    if (close < open) {
        generateParentheses(n, current + ")", open, close + 1);
    }
}

int main() {
    int n;
    cout << "Enter number of pairs of parentheses: ";
    cin >> n;

    cout << "All combinations of well-formed parentheses:" << endl;
    generateParentheses(n);

    return 0;
}
