#include<iostream>
using namespace std;
int main(){
	int x1 , x2;
	cout << "Enter a number:";
	cin >> x1;
	cout << "Enter a number:";
	cin >> x2;
	
	if(x1>x2){
		cout << "The first number is greater.";
	}
	else if (x1<x2){
		cout << "The second number is greater.";
	}
	else{
		cout << "Both numbers are equal.";
	}
}