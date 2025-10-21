#include<iostream>
using namespace std;
int main(){
	char alpha;
	cout << "Enter a single character: ";
	
	cin >> alpha;
	
	if(alpha == 'a' || alpha == 'e' || alpha == 'i' || alpha == 'o' || alpha == 'u' || alpha == 'A' || alpha == 'E' || alpha == 'I' ||alpha == 'O' || alpha == 'U'){
		cout << "The character is a vowel.";
	}
	else{
		cout << "The character is a consonant.";
	}
}