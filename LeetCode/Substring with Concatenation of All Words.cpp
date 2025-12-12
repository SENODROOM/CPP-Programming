#include <iostream>
#include <string>
using namespace std;

int main() {

    string s;
    cout << "Enter the string: ";
    cin >> s;

    int n;
    cout<< "Enter the number of words: ";
    cin >> n;
    string words[5000];
    for(int i = 0; i < n; i++) {
        cout<< "Enter the words["<<i<<"]: ";
        cin >> words[i];
    }
    
    int wordLen = words[0].length();
    int totalLen = n * wordLen;

    for(int i = 0; i <= s.length() - totalLen; i++) {
        string sub = s.substr(i, totalLen);
        bool used[5000] = {0};
        bool ok = true;

        for(int j = 0; j < n; j++) {
            string part = sub.substr(j * wordLen, wordLen);
            bool found = false;

            for(int k = 0; k < n; k++) {
                if(!used[k] && part == words[k]) {
                    used[k] = true;
                    found = true;
                    break;
                }
            }

            if(!found) {
                ok = false;
                break;
            }
        }

        if(ok) cout << i << " ";
    }

    cout << endl;
}
