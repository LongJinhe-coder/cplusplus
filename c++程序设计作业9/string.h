//string.h

#ifndef STRING_H_
#define STRING_H_
#include<iostream>
#include<cassert>
#include<fstream>

const unsigned int INIT_CAPACITY = 32;
const unsigned int DELTA_CAPACITY = (unsigned int)(INIT_CAPACITY * 0.5);

//v0.1：empty class，仍然可以实例化(系统为我们
//	自动创建了一个称为“默认构造函数”的成员）
//v0.2：构造函数（两个）；析构函数、print
//v0.3：+拷贝构造函数：让你创建一个和给定对象一致的对象
//v0.4：revised拷贝构造函数
//v0.5：+size()、+capacity()、+empty()、insert(char), insert(char *)
//v0.6(1/2)：operator<<
///---------------------This week job----------------------
//v0.6(2/2)：operator+(string + string - done, string + std::string, std::string + string)
//v0.7: operator+(string + c-string, c-string + string)
//v0.8: operator+=(string+=string)
//v0.9: []
//v0.10: ==
namespace hqu {
	class string {
	private:
		char * _data;
		unsigned int _size;
		unsigned int _capacity;
	public:	
		//构造函数
		string();
		string(const char * str); 
		string(const string & rhs);
		//析构函数
		~string();	
		//其他成员函数
		void print() const;
		int size() const;
		int capacity() const;
		bool empty()const;
		bool insert(int off, char ch);
		void append(const char * str);
		int find(char ch) const;
		void reverse();
		//运算符：1元(&，++，--)、2元(+,-,*,/,%,==,+=,...)、3元(?:)
		//重载方式有两种：friend/member function
		//区别（1）友元函数重载时，需要我们分别描述两个参数，即左参、右参
		//operator<<：只能通过友元函数形式重载（why？）, cout << obj;
		//obj1 << obj2 ==>obj1.operator<<(obj2)
		//友元函数并非成员函数
		//（2）成员函数重载时，仅仅需要描述右参，因为左参被默认为“自己”
		//运算符成员函数（重载overload）
		//[]

		friend std::ostream & operator<<(std::ostream & out, const string & rhs) {
			out << rhs._data; //_data:private
			return out;
		}	//该友元函数被视为“inline”（内联）
		
		//string + int, string + c-string, .....
		//v0.6: string+string:（1）函数名operator+，（2）参数string, string，（3）返回？
		friend const string operator+(const string & lhs, const string & rhs) {
			//提问1：为什么两个参数都是const --参加运算的两个参数不应该被修改
			//提问2：为什么返回也是const -- 运算结果可以作为l-value？=
			//提问3：返回为什么没有pass by reference
			string result(lhs);		//借用了拷贝构造函数
			result.append(rhs._data);
			return result;		
		}

		//v0.6: string+std::string
		friend const string operator+(const string & lhs, const std::string & rhs) {
			string result(lhs);
			result.append(rhs.c_str());
			return result;
		}

		//v0.6: std::string+string
		friend const string operator+(const std::string & lhs, const string & rhs) {
			string result(lhs.c_str());
			result.append(rhs._data);
			return result;
		}

		//v0.6: string + c-string: str1 + "World!";
		friend const string operator+(const string & lhs, const char * rhs) {
			string result(lhs);
			result.append(rhs);
			return result;
		}

		//v0.8: string += string
		friend string & operator+=(string & lhs, const string & rhs) {
			//提问1：为什么左参没有const，右边const - lhs将被修改且返回
			//提问2：为什么返回不是const - 返回可能作为l-value出现
			//提问3：为什么返回是pass by reference - lhs要作为运算数参与后续可能的运算
			lhs.append(rhs._data);
			return lhs;
		}
		
		//c-string + string: "Hi!"
		
		//[], e.g. (1) cout << str[0]; (2) str[0] = 'h'; 
		//只能基于成员函数实现
		//返回为什么是pass by reference?
		//返回为什么不是const？
		char & operator[](int i) {
			assert(i >= 0 && i < _size);
			return *(_data + i);
		}
		//==

		//HW6 - comments
		void append(char ch);
		string & operator=(const string & rhs);		//另一个必须基于成员函数实现的运算符
		//(1) string + char
		friend string operator+(const string & lhs, char rhs);
		//(2) string + int
		friend string operator+(const string & lhs, int rhs);
		//(3) string += c-string
		friend string & operator+=(string & lhs, const char * rhs);
		//(4) string == c-string
		friend bool operator==(const string & lhs, const char * rhs);
		//(5) string != string
		friend bool operator!=(const string & lhs, const string & rhs);
		//(6) ifstream >> string
		friend std::ifstream & operator>>(std::ifstream & in, string & rhs);

		//Tasks of this week
		//Operator overloading by member functions, operator+
		
	private:
		//成员函数（私有，私用目的，无须对外暴露）
		void resize(int delta = DELTA_CAPACITY);
	};
}
#endif 