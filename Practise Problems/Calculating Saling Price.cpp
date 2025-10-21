#include <iostream>
using namespace std;

int main(){
    double price;
    cout << "Enter the price: ";
    cin >> price;
    double marked_price = price * 1.8;
    double selling_price = marked_price * 0.9;
    cout << "Selling Price: ";
    cout << selling_price;
    
    return 0;
} 