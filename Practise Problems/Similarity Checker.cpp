#include<iostream>
using namespace std;
int main(){
	int x1 , x2;
	cout << "Enter a number:";
	cin >> x1;
	cout << "Enter a number:";
	cin >> x2;
	bool a1 = x1;
	bool a2 = x2;
	if(a1 == a2){
		cout << "False";
	}else{
		cout << "True";
	}
}