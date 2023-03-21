#include <iostream>
#include <fstream>
#include <string>
#include "Password Template.h"
const int MAX = 4000;
using namespace std;


PasswordChecker::PasswordChecker(){
	userPassword = "";
	passwordArray = new string[MAX];
	size = 0;
	ifstream read("passwords.txt");
	if(!read.is_open())
	{
		//If file is not found exit the program.
		cout << "File could not be found!" << endl;
		exit(1);
	}
	while(!read.eof())
	{
		read >> passwordArray[size];
		size++;
	}
	bubbleSort();
}
PasswordChecker::PasswordChecker(string s){
	userPassword = s;
	passwordArray = new string[MAX];
	size = 0;
	ifstream read("C:\\Users\\Melina\\Documents\\Visual Studio 2012\\Projects\\CSC 211 Projects\\Password Manager\\Password Manager\\passwords.txt");
	if(!read.is_open())
	{
		//If file is not found exit the program.
		cout << "File could not be found!" << endl;
		exit(1);
	}
	while(!read.eof())
	{
		read >> passwordArray[size];
		size++;
	}
	bubbleSort();
}
PasswordChecker::PasswordChecker(PasswordChecker& other)
{
	userPassword = other.userPassword;
	passwordArray = new string[MAX];
	for(int i = 0; i < size; i++)
		passwordArray[i] = other.passwordArray[i];
}
PasswordChecker::~PasswordChecker()
{
	delete [] passwordArray;
}
	
void PasswordChecker::setPassword(string p){
	userPassword = p;
}
void PasswordChecker::search()
{
	foundInList = false;
	for(int a = 0; a < size-1; a++)
	{
		if(userPassword.find(passwordArray[a]) >= 0 && userPassword.find(passwordArray[a]) < userPassword.length())
			foundInList = true;
	}
}
void PasswordChecker::checkLength()
{
	foundLength = true;
	if(userPassword.length() < 8)
		foundLength = false;
}
void PasswordChecker::checkSpaces()
{
	foundSpace = false;
	if(userPassword.find(" ") >= 0 && userPassword.find(" ") < userPassword.length())
		foundSpace = true;
}
void PasswordChecker::checkSpecialChar()
{
	foundChar = false;
	if(userPassword.find_first_of("@!><$&") >=0)
		foundChar = true;
}
void PasswordChecker::checkUpperCase()
{
	int inputLength = userPassword.length();
	foundUpperCase = false;
	for(int i =0; i < inputLength; i++)
	{
		if(isupper(userPassword[i]) != 0)
			foundUpperCase = true;
	}
}
void PasswordChecker::checkLowerCase()
{
	int inputLength = userPassword.length();
	foundLowerCase = false;
	for(int i =0; i < inputLength; i++)
	{
		if(islower(userPassword[i]) != 0)
			foundLowerCase = true;
	}
}
void PasswordChecker::checkDigit()
{
	int inputLength = userPassword.length();
	foundDigit = false;
	for(int i =0; i < inputLength; i++)
	{
		if(isdigit(userPassword[i]) != 0)
			foundDigit = true;
	}
}
void PasswordChecker::isValid()
{
	string newTry = " ";
	foundInList = false;
	search();
	checkLength();
	checkSpaces();
	checkSpecialChar();
	checkUpperCase();
	checkLowerCase();
	checkDigit();
	string results = " ";
	if(!foundLength)
		cout << "Your password is not long enough." <<endl;
	if(foundSpace)
		cout << "Your password has a space in it." << endl;
	if(!foundChar)
		cout << "You need a special character." << endl;
	if(!foundUpperCase)
		cout << "You need a capital letter." << endl;
	if(!foundDigit)
		cout << "You need a number in your password." << endl;
	if(foundInList)
		cout << "This is a common password." << endl;
	if(foundLength && !foundSpace && foundChar && foundUpperCase && foundDigit)
	{
		results = "This is a WEAK password.";
		if(foundLowerCase)
		{
			results = "This is a MEDIUM password.";
			if(!foundInList)
				results = "This is a STRONG password";
		}
	}
	else
		results = "This password does NOT meet all the requirements.";
	cout << results << endl;
	if(binarySearch() != -1)
	{
		cout << "An exact match was found." << endl;
	}
	if(results.find("NOT") >= 0)
	{
		cout << "Would you like to try again? Type yes or no." << endl;
		cin >> newTry;
		if(newTry == "yes")
		{
			cout << "Please enter a password:  ";
			cin >> newTry;
			setPassword(newTry);
			isValid();
		}
		else
			cout << "Thank You for trying!" << endl;
	}
}
void PasswordChecker::bubbleSort()
{
    string temp;
    int iteration;
    int index;

    for (iteration = 1; iteration < size; iteration++)
    {
        for (index = 0; index < size - iteration; index++)
            if (passwordArray[index] > passwordArray[index + 1]) 
            {
                temp = passwordArray[index];
                passwordArray[index] = passwordArray[index + 1];
                passwordArray[index + 1] = temp;
            }
    }
}
int PasswordChecker::binarySearch() 
{
    int first = 0;
    int last = size - 1;
    int mid;

    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;

		if (passwordArray[mid] == userPassword)
            found = true;
		else if (passwordArray[mid] > userPassword)
            last = mid - 1;
        else
            first = mid + 1;
    }

    if (found) 
        return mid;
    else
        return -1;
}