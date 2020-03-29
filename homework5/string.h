#ifndef STRING_H_
#define STRING_H_
const unsigned int INIT_CAPACITY = 32;

//v0.1：empty class，仍然可以实例化(系统为我们
//	自动创建了一个称为“默认构造函数”的成员）
//v0.2：构造函数（两个）；析构函数、print
//v0.3：+拷贝构造函数：让你创建一个和给定对象一致的对象
//v0.4：revised拷贝构造函数
//v0.5：+size()、+capacity()、+empty()
namespace hqu {
	class string {
	private:
		char * _data;
		unsigned int _size;
		unsigned int _capacity;
	public:	
		string(); //长得就是一个默认构造函数
		string(const char * str);
		string(const string & rhs);
		//(1)special naming;(2)no arguments
		//(3)only one;(4) no return
		~string();
		//通常
		void print() const;
		int size() const;
		int capacity() const;
		bool empty()const;
		void append(const char * str);
		int find(char ch)const;
		void reverse()const;
	};
}
#endif 