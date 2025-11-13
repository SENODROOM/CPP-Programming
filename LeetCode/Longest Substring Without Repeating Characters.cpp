#include<iostream>
using namespace std;
void LongestSubstring(string st){
    string value = "";
    int total = 0;
    int length = st.length();
    for (int i = 0; i < length; i++)
    {
        int unique = 0;
        for (int j=0; j < i; j++)
        {
            if (st[j] == st[i])
            {
                unique++;
            }
        }
        if(unique==0){
            value += st[i];
            total++;
        }
    }
    cout << "The answer is \""<< value << "\", with the length of " << total;
}

int main(){
    string s;
    cout << "Enter the string: ";
    cin >> s;
    cout << s <<endl;
    LongestSubstring(s);
}