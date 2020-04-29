//vector.h
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
#include <string.h>
#include<vector>

namespace hqu
{
template <typename T>
class vector
{
private:
	T *_data;
	int _size, _capacity;

public:
	vector(int capacity = 0);
	vector(const vector &v);
	void push_back(const T &x);
	~vector()
	{
		if (_data)
			delete[] _data;
	}
	// void operator=(const vector &lhs);
	vector<T> operator=(const vector<T> &lhs){
	if (*this==lhs)
	{
		return *this;
	}
	
	if (_size < lhs._size)
	{
		T *_temp = new T[_capacity + lhs._size - _size];
		if (_temp)
		{
			// std::cout << "in operator=t\n";
			for (int i = 0; i < _size; i++)
			{
				*(_temp + i) = *(_data + i);
			}
			delete[] _data;
			_data = _temp;
			_capacity += lhs._size - _size;
		}
	}
	if (_capacity >= lhs._size)
	{
		// std::cout << lhs._size << "in operator=\n";
		for (int i = 0; i < lhs._size; i++)
		{
			*(_data + i) = *(lhs._data + i);
		}
		_size = lhs._size;
	}
	else
	{
		for (int i = 0; i < _size; i++)
		{
			*(_data + i) = *(lhs._data + i);
		}
	}
	// std::cout << "in operator==========\n";
	return *this;
	}
	T &operator[](int i);
	// template<typename T>
	// friend vector<T> &operator+( vector<T> &lhs,  vector<T> &rhs);
	template <typename U>
	friend std::ostream &operator<<(std::ostream &out,
									const vector<U> &v);
	template <typename U>
	friend vector<U> operator+(const vector<U> &lhs, const vector<U> &rhs);
	// template<typename U,typename V>
	template<typename U>
	friend vector<U> operator+(const vector<U> &lhs,const std::vector<U> &rhs);
	template <typename U>
	friend bool operator==(const vector<U> &lhs, const vector<U> &rhs);
	template <typename U>
	friend vector<U> operator-(const vector<U> &lhs, const vector<U> &rhs);

private:
	void expand(T *data, int extraSize = 1);
};

template <typename T>
vector<T>::vector(int capacity)
{
	if (capacity <= 0)
	{
		_data = NULL;
		_capacity = 0;
	}
	else
	{
		_data = new T[capacity];
		if (_data)
			_capacity = capacity;
		else
			_capacity = 0;
	}
	_size = 0;
	// std::cout << "in vector()\n";
}

template <typename T>
void vector<T>::push_back(const T &x)
{
	if (!_data || _size >= _capacity)
		expand(_data);
	if (_size < _capacity)
	{
		T *ele = new T(x);
		*(_data + _size) = *ele;
		_size++;
	}
}

template <typename T>
void vector<T>::expand(T *data, int extraSize)
{
	if (extraSize < 1)
		extraSize = 1;
	T *_temp = new T[_capacity + extraSize];
	if (_temp)
	{
		for (int i = 0; i < _size; i++)
			*(_temp + i) = *(_data + i);
		delete[] _data;
		_data = _temp;
		_capacity += extraSize;
	}
}

template <typename U>
std::ostream &operator<<(std::ostream &out,
						 const vector<U> &v)
{
	out << "data[" << v._size << '/'
		<< v._capacity << "] = ";
	for (int i = 0; i < v._size; i++)
		out << *(v._data + i) << ' ';
	out << std::endl;
	return out;
}

//拷贝函数
template <typename T>
vector<T>::vector(const vector &v)
{
	if (v._data)
	{
		_data = new T[v._capacity];
		if (_data)
		{
			for (int i = 0; i < v._size; ++i)
				*(_data + i) = *(v._data + i);
			_size = v._size;
			_capacity = v._capacity;
		}
		else
		{
			_size = 0;
			_capacity = 0;
		}
	}
	else
	{
		_data = NULL;
		_size = 0;
		_capacity = 0;
	}

	// std::cout << "in vector(const &vector)\n";
}

//重载运算符+(hqu::vector+hqu::vector)
template <typename U>
vector<U> operator+(const vector<U> &lhs, const vector<U> &rhs)
{
	vector<U> result(lhs);
	for (int i = 0; i < rhs._size; i++)
	{
		result.push_back(*(rhs._data + i));
	}
	return result;
	// std::cout << "in operator+(hqu::vector+hqu::vector)\n";
}

// template<typename U,typename V>
template<typename U>
vector<U> operator+(const vector<U> &lhs,const std::vector<U> &rhs)
{
	vector<U> result(lhs);
    for (int i = 0; i < rhs.size(); i++)
	{
		result.push_back(rhs[i]);
	}
	// std::cout << "in operator+(hqu::vector+std::vector)\n";
	return result;
}

// 重载运算符=
// template <typename T>
// void vector<T>::operator=(const vector &lhs)
// {
// 	if (_size < lhs._size)
// 	{
// 		T *_temp = new T[_capacity + lhs._size - _size];
// 		if (_temp)
// 		{
// 			// std::cout << "in operator=t\n";
// 			for (int i = 0; i < _size; i++)
// 			{
// 				*(_temp + i) = *(_data + i);
// 			}
// 			delete[] _data;
// 			_data = _temp;
// 			_capacity += lhs._size - _size;
// 		}
// 	}
// 	if (_capacity >= lhs._size)
// 	{
// 		// std::cout << lhs._size << "in operator=\n";
// 		for (int i = 0; i < lhs._size; i++)
// 		{
// 			*(_data + i) = *(lhs._data + i);
// 		}
// 		_size = lhs._size;
// 	}
// 	else
// 	{
// 		for (int i = 0; i < _size; i++)
// 		{
// 			*(_data + i) = *(lhs._data + i);
// 		}
// 	}
// 	std::cout << "in operator=\n";
// }
// template <typename T>
// vector<T>:: operator=(const vector &lhs){

// }

//重载运算符==
template <typename U>
bool operator==(const vector<U> &lhs, const vector<U> &rhs)
{
	if (lhs._size != rhs._size)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < lhs._size; i++)
		{
			if (*(lhs._data + i) != *(rhs._data + i))
			{
				return false;
			}
			return true;
		}
	}
	// std::cout << "in operator==\n";
}

//重载运算符[]
template <typename T>
T &vector<T>::operator[](int i)
{
	return _data[i];
	std::cout << "in []";
}

//重载运算符-
template <typename U>
vector<U> operator-(const vector<U> &lhs, const vector<U> &rhs){
	vector<U> temp;
	for (int i = 0; i < lhs._size; i++)
	{
		bool equal=false;
		for (int j = 0; j < rhs._size; j++)
		{
			if (*(lhs._data+i)==*(rhs._data+j)){
				equal=true;
				break;
			}
		}
		if (!equal)
			temp.push_back(*(lhs._data+i));
		
	}
	// std::cout << "in operator-\n";
	return temp;
}
} // namespace hqu

#endif
