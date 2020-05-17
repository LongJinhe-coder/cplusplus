//string.cpp

#include"string.h"
#include<iostream>
#include<string>
#include<string.h>
//namespace::类名::方法
hqu::string::string() {
	_data = NULL;
	_size = 0;
	_capacity = 0;
	std::cout << "in string()\n";
}

//why const in argument list?
//(1)c-style const string given by the users
//(2)semantics
hqu::string::string(const char * str) {
	//copy content from str to _data (local storage)
	_data = new char[strlen(str) + 1];
	if (_data) {
		_capacity = strlen(str) + 1;
		_size = 0;
		for (int i = 0; i < strlen(str); ++i) {
			*(_data + i) = *(str + i);
			_size++;
		}
		*(_data + _size++) = '\0';
	}
	else {
		_size = 0;
		_capacity = 0;
	}
	std::cout << "in string(const char *)\n";
}

hqu::string::~string() {
	if (_data)
		delete[] _data;
}

hqu::string::string(const string & rhs) {
	//非完美版本 == 系统自动创建的那个版本的效果
	//bitwise copy <== stupid <== no idea about your design
	//_data = rhs._data; //consequence
	//_size = rhs._size;
	//_capacity = rhs._capacity;

	//（上面）shallow copy：浅拷贝
	//（下面）deep copy：深拷贝

	//我们理解string的内部数据结构的意义/关联
	//放弃bitwsie copy，定制我们自己的“拷贝”
	if (rhs._data) {
		_data = new char[rhs._capacity];
		if (_data) {
			for (int i = 0; i < rhs._size; ++i)
				*(_data + i) = *(rhs._data + i);
			_size = rhs._size;
			_capacity = rhs._capacity;
		}
		else {
			_size = 0; 
			_capacity = 0;
		}
	}
	else {
		_data = NULL;
		_size = 0;
		_capacity = 0;
	}

	std::cout << "in string(const string&)\n";
}


void hqu::string::print()const {
	if (_data)
		std::cout << _data << std::endl;
}

int hqu::string::size()const {
	return _size;
}

int hqu::string::capacity()const {
	return _capacity;
}

bool hqu::string::empty()const {
	return _size <= 0;
}

bool hqu::string::insert(int off, char ch) {
	bool result = true;
	if (_size + 1>_capacity)
		resize();
	if (result) {
		if (off >= 0) {
			if (off >= _size - 1)
				off = _size - 1;
		}
		else {
			if (off >= -1.0*_size)
				off = off + _size;
			else
				off = 0;
		}
		for (int i = _size; i >= off; i--)
			*(_data + i + 1) = *(_data + i);
		*(_data + off) = ch;
		_size++;
		*(_data + _size) = '\0';
	}
	return result;
}

void hqu::string::resize(int delta) {
	//Pls.implement this function, and pls. pay 
	//attention that delta might be positive, negative and zero
	if (_capacity > 0) {
		if (delta > 0) {
			char * temp = new char[_capacity + delta];
			if (temp) {
				for (int i = 0; i < _size; ++i)
					*(temp + i) = *(_data + i);
				delete[] _data;
				_data = temp;
				_capacity += delta;
			}
		}
		else if (delta < 0) {
			if (_capacity + delta > 0) {
				char * temp = new char[_capacity + delta];
				if (temp) {
					if (_capacity + delta >= _size) {
						for (int i = 0; i < _size; ++i)
							*(temp + i) = *(_data + i);
					}
					else {
						for (int i = 0; i < _capacity + delta - 1; ++i)
							*(temp + i) = *(_data + i);
						_size = _capacity + delta;
						*(temp + _size - 1) = '\0';
					}
					delete[] _data;
					_data = temp;
					_capacity = _capacity + delta;
				}
			}
			else{
				delete[] _data;
				_size = 0;
				_capacity = 0;
			}
		}
		//ignore if delta == 0
	}
	else {
		if (delta > 0) {
			_data = new char[delta];
			if (_data)
				_capacity = delta;
		}
		//ignore if delta <=0 
	}
}

void hqu::string::append(const char * str) {
	//accurate, robust, friendly
	if (str) {
		int len = strlen(str);
		if (len > 0) {
			if (_size + len > _capacity)
				resize(len);
			if (_size + len <= _capacity) {
				for (int i = 0; i < len; ++i) {
					*(_data + _size - 1) = *(str + i);
					++_size;
				}
				*(_data + _size - 1) = '\0';
			}
		}
	}
}

int hqu::string::find(char ch) const{
	int result = -1;
	for(int i =0; i < _size - 1; ++i)
		if (*(_data + i) == ch) {
			result = i;
			break;
		}
	return result;
}

void hqu::string::reverse() {
	if (_size > 2) { //\0, x\0, xy\0
		for (int i = 0; i < (_size - 1) / 2;++i) {
			char temp = *(_data + i);
			*(_data + i) = *(_data + _size - 2 - i);
			*(_data + _size - 2 - i) = temp;
		}
	}
}

//HW6 - 辅助函数
void hqu::string::append(char ch) {
	if (_size + 1 > _capacity)
		resize();
	if (_size + 1 <= _capacity) {
		*(_data + _size - 1) = ch;
		++_size;
		*(_data + _size - 1) = '\0';
	}
}

//HW6 - 辅助函数
hqu::string & hqu::string::operator=(const string & rhs) {
	if (this == &rhs)
		return *this;

	if (rhs._size > _capacity)
		this->resize(rhs._size - _capacity);

	if (rhs._size <= _capacity) {
		for (int i = 0; i < rhs._size; ++i)
			*(_data + i) = *(rhs._data + i);
		_size = rhs._size;
	}
	else {
		for (int i = 0; i < _capacity - 1; ++i)
			*(_data + i) = *(rhs._data + i);
		*(_data + _capacity - 1) = '\0';
		_size = _capacity;
	}
	return *this;
}

//HW6 - Task 1: string + ch
hqu::string hqu::operator+(const string & lhs, char rhs) {
	string result(lhs);		//copy constructor being called
	result.append(rhs);
	return result;			//copy constructor being called again
}

//HW6 - Task 2: string + int
hqu::string hqu::operator+(const string & lhs, int rhs) {
	string result(lhs);
	return result + std::to_string(rhs);
}

//HW6 - Task 3: string += c-string
hqu::string & hqu::operator+=(string & lhs, const char * rhs) {
	string temp(rhs);
	lhs = lhs + temp;
	return lhs;
}

bool hqu::operator==(const string & lhs, const char * rhs) {
	bool result = true;
	
	int rhs_len = strlen(rhs)+1;
	if (lhs._size == rhs_len) {
		for (int i = 0; i < lhs._size; ++i)
			if (*(lhs._data + i) != *(rhs + i)) {
				result = false;
				break;
			}
	}
	else
		result = false;
	
	return result;
}

//fixed at April 26
bool hqu::operator!=(const string & lhs, const string & rhs) {
	bool result = false;

	if (lhs._size == rhs._size) {
		for (int i = 0; i < lhs._size; ++i)
			if (*(lhs._data + i) != *(rhs._data + i)) {
				result = true;
				break;
			}
	}
	else
		result = true;

	return result;
}

std::ifstream & hqu::operator>>(std::ifstream & in, string & rhs) {
	char line[256];
	while (!in.eof()) {
		in.getline(line, 256);
		rhs.append(line);
	}
	return in;
}