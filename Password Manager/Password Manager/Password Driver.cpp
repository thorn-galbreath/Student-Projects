#include "Password Template.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){
	PasswordChecker userPassword;
	string input;
	cout << "Welcome to the Password Manager." << endl;
	cout << "This program is to help you create a great password." << endl;
	cout << "Please enter a password. Your password must have a special character, " << endl;
	cout << "a number, and a capital letter. Make sure you don't have any spaces." << endl;
	getline(cin, input);
	userPassword.setPassword(input);
	userPassword.isValid();
	return 0;
}


