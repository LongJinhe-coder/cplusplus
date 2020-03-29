#include"string.h"
#include<iostream>
#include<string>
using namespace std;
using namespace hqu;
int main() {
	//int x;
	hqu::string str1("Hello");
	hqu::string str2("world");
	
	str1.print();
	cout << "size of str1:" << str1.size() << endl;
	cout << "size of str2:" << str2.size() << endl;

	if (str2.empty())
		cout << "str2 is empty\n";
	str1.append("world");
	cout<<"字符串拼接后输出:";
	str1.print();
	cout << "size of str1:" << str1.size() << endl;
	char a='r';
	cout<<"字符"<<a<<"在str中的位置是"<<str1.find(a)+1<<endl;
	str1.reverse();
	cout<<"字符串翻转后输出:";
	str1.print();
	system("pause");
	return 0;
}
