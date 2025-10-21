#include<iostream>
using namespace std;
int main(){
	int temp;
	cout << "Enter the temperature in fahrenheit: ";
	cin >> temp;
	if(temp>=80){
		cout << "Hot";
	}
	else if (temp<=79 && temp>=60){
		cout << "Warm";
	}
	else if (temp<=59 && temp>=40){
		cout << "Cool";
	}
	else{
		cout << "Cold";
	}
}