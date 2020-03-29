#include"string.h"
#include<iostream>
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
	_data = new char[INIT_CAPACITY];
	if (_data) {
		_size = strlen(str) + 1;
		for (int i = 0; i < _size; ++i)
			*(_data + i) = *(str + i);
		*(_data + _size) = '\0';
		_capacity = INIT_CAPACITY;
	}
	else {
		//_data == NULL;
		_size = 0;
		_capacity = 0;
	}
	std::cout << "in string(const char *)\n";
}

hqu::string::~string() {
	//destroy myself
	//multiple statements can be prepared here
	if (_data)
		delete[] _data;
}

hqu::string::string(const string & rhs) {
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

void hqu::string::append(const char * str){
	if (_data) {
		int init_size=_size;
		_size = strlen(str) + init_size;
		for (int i = init_size-1; i < _size-1; ++i){
			*(_data + i) = *(str + i-init_size+1);
			// std::cout<<*(_data+i);
		}
		*(_data + _size) = '\0';
		_capacity = INIT_CAPACITY;
	}
	else {
		//_data == NULL;
		_size = 0;
		_capacity = 0;
	}
	
}

int hqu::string::find(char ch)const{
	for (int i = 0; i < _size; i++)
	{
		if (*(_data+i)==ch)
		return i;
	}
	return -1;
}

void hqu::string::reverse()const{
	int times=_size/2;
	for (int i = 0; i < times; i++)
	{
		char temp=*(_data+i);
		*(_data+i)=*(_data+_size-i-2);
		// std::cout<<*(_data+i)<<std::endl;
		*(_data+_size-i-2)=temp;
		// std::cout<<*(_data+_size-i-2);
	}
	
}
