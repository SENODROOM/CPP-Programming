#include<iostream>
using namespace std;
int main(){
	int x1 , x2 ,x3;
	cout << "Enter a number:";
	cin >> x1;
	cout << "Enter a number:";
	cin >> x2;
	cout << "Enter a number:";
	cin >> x3;
	
	if(x1>=x2){
		if(x1>=x3){
			cout << x1;
		}
		else{
			cout << x3;
		}
	}
	else if (x2>=x1){
		if(x2>=x3){
			cout << x2;
		}
		else{
			cout << x3;
		}
	}
	else{
		cout << x3;
	}
}