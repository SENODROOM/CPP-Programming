#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    char character;
    cout << "Enter a Character: ";
    cin >> character;

    if (character >= '0' && character <= '9') {
        cout << "Number" << endl;
    } 
    else if (character >= 'a' && character <= 'z') {
        cout << "Lowercase Alphabet" << endl;
    } 
    else if (character >= 'A' && character <= 'Z') {
        cout << "Uppercase Alphabet" << endl;
    } 
    else if (character == '.' || character == ',' || character == '?' || character == '"' || character == '\'' ||
             character == ';' || character == ':' || character == '`') {
        cout << "Punctuation Mark" << endl;
    } 
    else if (character == '(' || character == ')' || character == '{' || character == '}' ||
             character == '[' || character == ']') {
        cout << "Bracket/Parenthesis" << endl;
    } 
    else if (character == '_' || character == '-' || character == '+' || character == '*' || character == '&' ||
             character == '^' || character == '%' || character == '$' || character == '#' || character == '@' ||
             character == '!' || character == '~' || character == '<' || character == '>' || character == '/' || character == '\\') {
        cout << "Symbol" << endl;
    } 
    else if (character == ' ') {
        cout << "Space" << endl; // cin dont detect space
    } 
    else {
        cout << "Special Character" << endl;
    }

    return 0;
}