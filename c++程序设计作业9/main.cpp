#include"vector.h"
#include"string.h"
#include<string>
#include<vector>
int main() {
	hqu::vector<hqu::string> strs;
	strs.push_back("hello");
	strs.push_back("world");
	std::cout << "vector<string> - " << strs << std::endl;

	std::cout << "【T1：测试拷贝构造函数】\n";
	hqu::vector<hqu::string> strs2(strs);
	strs2.push_back("haha");
	std::cout << "vector<string> - " << strs2 << std::endl;

	std::cout << "【T2-1：测试operator+vector】\n";
	hqu::vector<hqu::string> strs3 = strs2 + strs;
	std::cout << "vector + vector - " << strs3 << std::endl;

	std::cout << "【T2-2：测试operator+std::vector】\n";
	std::vector<std::string> strs3_2;
	strs3_2.push_back("c++ world");
	strs2 = strs2 + strs3_2;
	std::cout << "vector + std::vector - " << strs2 << std::endl;

	std::cout << "【T5：测试operator[]】\n";
	std::cout << "\nvector strs3[] - ";
	for (int i = 0; i < strs3.size(); ++i)
		std::cout << strs3[i] << ' ';
	std::cout << std::endl;
	strs3[0] = hqu::string("Hi");
	std::cout << "\nvector strs3[] - ";
	for (int i = 0; i < strs3.size(); ++i)
		std::cout << strs3[i] << ' ';
	std::cout << std::endl;

	std::cout << "【T3：测试operator=】\n";
	hqu::vector<hqu::string> strs4;
	strs4 = strs3;
	std::cout << "\nvector=vector - " << strs4 << std::endl;
	
	std::cout << "【T4：测试operator==】\n";
	if (strs4 == strs3)
		std::cout << "\nvector strs4 == vector strs3" << std::endl;

	if(!(strs4 == strs2))
		std::cout << "\nvector strs4 != vector strs2" << std::endl;

	return 0;
}

