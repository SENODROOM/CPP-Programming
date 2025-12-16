#include <iostream>
using namespace std;

int main() {
    int g[100], s[100];
    int n, m;
    
    cout << "Enter number of children: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter g[" << i << "]: ";
        cin >> g[i];
    }
    
    cout << "Enter number of cookies: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        cout << "Enter s[" << i << "]: ";
        cin >> s[i];
    }
    
    int total = 0;
    
    for (int i = 0; i < n; i++) {           // for each child
        for (int j = 0; j < m; j++) {       // find a cookie
            if (s[j] >= g[i]) {             // cookie satisfies child
                total++;
                s[j] = -1;                  // mark cookie as used
                break;
            }
        }
    }
    
    cout << "Max content children: " << total;
}
