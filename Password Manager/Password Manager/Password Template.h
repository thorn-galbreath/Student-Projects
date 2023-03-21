#include <iostream>
#include <string>
using namespace std;

class PasswordChecker{
private:
	int size;
	string userPassword;
	string * passwordArray;
	bool foundInList, foundLength, foundUpperCase, foundLowerCase;
	bool foundChar, foundDigit, foundSpace;
public:
	PasswordChecker();
	PasswordChecker(string);
	PasswordChecker(PasswordChecker& other);
	~PasswordChecker();
	void setPassword(string);
	void search();
	void checkLength();
	void checkSpaces();
	void checkSpecialChar();
	void checkUpperCase();
	void checkLowerCase();
	void checkDigit();
	void isValid();
	void bubbleSort();
	int binarySearch();

};