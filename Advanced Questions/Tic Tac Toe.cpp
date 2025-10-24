#include<iostream>
using namespace std;
int main(){
	bool x1 , x2 , x3 , x4 , x5 , x6 , x7 , x8 , x9;
	cout << "Enter a 1 or 0:";
	cin >> x1;
	cout << "Enter a 1 or 0:";
	cin >> x2;
	cout << "Enter a 1 or 0:";
	cin >> x3;
	cout << "Enter a 1 or 0:";
	cin >> x4;
	cout << "Enter a 1 or 0:";
	cin >> x5;
	cout << "Enter a 1 or 0:";
	cin >> x6;
	cout << "Enter a 1 or 0:";
	cin >> x7;
	cout << "Enter a 1 or 0:";
	cin >> x8;
	cout << "Enter a 1 or 0:";
	cin >> x9;
	
	if(x1 == x2 && x2 ==x3){
		cout << x1 << "Won";
	}
	else if(x1 == x5 && x5 ==x9){
		cout << x1 << "Won";
	}
	else if(x1 == x4 && x4 ==x7){
		cout << x1 << "Won";
	}
	else if(x7 == x8 && x8 ==x9){
		cout << x7 << "Won";
	}
	else if(x3 == x6 && x6 ==x9){
		cout << x5 << "Won";
	}
	else if(x4 == x5 && x5 ==x6){
		cout << x4 << "Won";
	}
	else if(x2 == x5 && x5 ==x8){
		cout << x2 << "Won";
	}
	else if(x3 == x5 && x5 ==x7){
		cout << x3 << "Won";
	}
	else {
		cout << "Draw";
	}
}