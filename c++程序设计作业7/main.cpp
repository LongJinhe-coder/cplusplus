//main.cpp
#include "vector.h"
#include <string>
#include <vector>
#include <iostream>
// using namespace std;
int main()
{
	hqu::vector<float> values;
	values.push_back(1.1f);
	values.push_back(2.2f);
	values.push_back(3.3f);
	values.push_back(4.4f);
	std::cout << "values=" << values << std::endl;
	hqu::vector<std::string> strs;
	strs.push_back("hello");
	strs.push_back("world");
	std::cout << "strs=" << strs << std::endl;
	// hqu::vector<std::string> str1(strs);
	// std::cout << str1 << std::endl;
	hqu::vector<float> values1(values);
	std::cout << "values1" << values1 << std::endl;
	std::cout << "values1+values=" << (values1 + values);
	std::vector<std::string> str;
	str.push_back("hello");
	std::cout << "hqu::vector+std::vector" << std::endl;
	std::cout << "strs+str=" << (strs + str);
	hqu::vector<std::string> str1;
	hqu::vector<std::string> str2;
	str2.push_back("hello");
	str2.push_back("hello");
	str2.push_back("hello");
	std::cout << "str2=" << str2 << std::endl;
	std::cout << "str1 = str2 = strs:" << std::endl;
	str1 = str2 = strs;
	std::cout << "str1=" << str1 << std::endl;
	std::cout << "str2=" << str2 << std::endl;
	hqu::vector<float> values2;
	values2 = values;
	std::cout << "values2=" << values2 << std::endl;
	if (values == values2)
	{
		std::cout << "values" << "=" << "values2" << std::endl;
	}
	else
	{
		std::cout << "values" << "!=" << "values2" << std::endl;
	}
	std::cout << "values2[1]=" << values2[1] << std::endl;
	hqu::vector<std::string> str3;
	str3.push_back("hello");
	std::cout << "strs-str3=" << (strs - str3) << std::endl;

	system("pause");
	return 0;
}
