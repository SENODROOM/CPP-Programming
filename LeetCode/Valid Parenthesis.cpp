#include <iostream>
using namespace std;

bool isValid(string s) {
    char arr[10000];
    int top = -1;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            arr[++top] = c;
        } else {
            if (top == -1) return false; 

            if (c == ')' && arr[top] != '(') return false;
            if (c == '}' && arr[top] != '{') return false;
            if (c == ']' && arr[top] != '[') return false;

            top--; 
        }
    }

    return top == -1;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    if (isValid(s))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
