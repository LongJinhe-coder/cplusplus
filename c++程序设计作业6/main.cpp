#include"string.h"
#include<iostream>
#include<string>
using namespace std;
using namespace hqu;
int main() {
	hqu::string str1("I like coding!");
	hqu::string str2("And you?");

	cout << "\nDemo of operator<<:" << endl;
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;

	//v0.6
	cout << "\nDemo of operator+:(string + string)" << endl;
	cout << (str1 + str2) << endl;

	std::string str3("But I do not like writing.");
	cout << "\nDemo of operator+:(string + std::string)" << endl;
	cout << (str1 + str3) << endl;

	cout << "\nDemo of operator+:(std::string + string)" << endl;
	cout << (str3 + str1) << endl;

	cout << "\nDemo of operator+:(string + c-string)" << endl;
	cout << (str1 + "Coding is not interesting job to everyone") << endl;
	//solution 1 - 提供一个 hqu::string + c-string的专属版本
	//solution 2 - 强制转换

    cout << "\nDemo of operator+:(string + char)" << endl;
    char a='!';
	cout << (str1 + a) << endl;

    cout << "\nDemo of operator+:(string + int)" << endl;
    int b=5;
	cout << (str1 + b) << endl;

	//v0.8
	cout << "\nDemo of operator+=:" << endl;
	//str1 += str2;
	//cout << str1 << endl;
	hqu::string str4("Coding is crazy job.");
	(str1 += str2) += str4;
	cout << str1 << endl;

	//v0.9
	//cout << "\nDemo of operator[]:" << endl;
	for (int i = 0; i < str1.size(); ++i) {
		if (str1[i] >= 'a' && str1[i] <= 'z') {
			str1[i] = 'A' + str1[i] - 'a';
		}
		cout << str1[i];
	}
	cout << endl;
	
    //v1.0 str1 == ”Hello!”;
    hqu::string str5("Hello!");
    cout << "\nDemo of operator==: str1==Hello" << endl;
    if (str1==str5)
    {
        cout<<"str1=="<<str5<<endl;
    }else
    {
        cout<<"str1!="<<str5<<endl;
    }

    //v1.0 str1 == ”Hello!”;
    cout << "\nDemo of operator!=: str1 != str2" << endl;
    if (str1!=str2)
    {
        cout<<"str1!=str2"<<endl;
    }else
    {
        cout<<"str1==str2"<<endl;
    }
    
    //v1.1 读取文件后str5(Hello!)->”Hello!c++ world”
	cout << "\nDemo of operator>>:" << endl;
    ifstream cin;
	cin.open("/home/longjinhe/Documents/cpp_document/homework6/text.txt");
    cin>>str5;
    cout<<str5<<endl;
	system("pause");
	return 0;
}
