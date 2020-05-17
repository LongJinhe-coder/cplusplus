
//main.cpp

#include"string.h"
#include<iostream>
#include<string>
using namespace std;
using namespace hqu;
int main() {
	cout << "--- Constructing two objects ---\n";
	hqu::string str1("I like coding!");
	hqu::string str2("And you?");

	//HW6
	cout << "\n--- Testing append(char) ---\n";
	str1.append('!');
	cout << str1 << endl;

	cout << "\n--- Testing string + char and operator= ---\n";
	str1 = str1 + '!';
	cout << str1 << endl;

	cout << "\n--- Testing string + int and operator= ---\n";
	str1 = str1 + 9999;
	cout << str1 << endl;

	cout << "\n--- Testing string += c-string ---\n";
	str1 += "-1111";
	cout << str1 << endl;

	cout << "\n--- Testing string == c-string ---\n";
	if (str2 == "And you?")
		cout << "str2(" << str2 << ") is equal to \'And you?\'\n";

	cout << "\n--- Testing ifstream >> string ---\n";
	ifstream fin("c:\\fushunkai\\test\\hw6.txt");
	fin >> str2;
	fin.close();
	cout << str2 << endl;

	system("pause");
	return 0;
}
