#include<iostream>
using namespace std;

int reverseInt(int num){
    int value =0;
    if (num < 0)
    {
        num*=-1;
        while (num>0)
        {
            value*=10;
            int s = num%10;
            value+=s;
            num/=10;
        }
        value*=-1;
        return value;
    }else{
        while (num>0)
        {
            value*=10;
            int s = num%10;
            value+=s;
            num/=10;
        }
        return value;
    }
}

int main(){

    int n = 0;
    cout << "Enter the Number: ";
    cin >> n;
    int n2 = reverseInt(n);
    cout << n2;

    return 0;
}