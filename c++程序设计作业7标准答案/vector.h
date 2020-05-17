//vector.h
#ifndef VECTOR_H_
#define VECTOR_H_
#include<iostream>
#include<cassert>
#include<vector>
namespace hqu {
	template<typename T>
	class vector {
	private:
		T * _data;
		int _size, _capacity;
	public:
		vector(int capacity = 0);
		void push_back(const T & x);
		~vector() {
			if (_data)
				delete[] _data;
		}
		template<typename U>
		friend std::ostream & operator<<(std::ostream & out,vector<U> & v);
		int size() const{ return _size; }
		int capacity()const { return _capacity; }
		//HW7
		//Task 1 - 拷贝构造函数
		vector(const vector<T> & v);
		//Task 2 - operator+hqu::vector
		vector<T> operator+(const vector<T> & rhs)const;
		vector<T> operator+(const std::vector<T> & rhs)const;
		//Task 3 - operator=
		vector<T> & operator=(const vector<T> & rhs);
		//Task 4 - operator==
		bool operator==(const vector<T> & rhs);
		//Task 5 - operator[]
		T & operator[](int i) const {
			assert(i >= 0 && i < _size);
			return *(_data + i);
		}
	private:
		void expand(unsigned int extraSize = 1);
	};
	
	template<typename T>
	vector<T>::vector(int capacity) {
		if (capacity <= 0) {
			_data = NULL;
			_capacity = 0;
		}
		else {
			_data = new T[capacity];
			if (_data)
				_capacity = capacity;
			else
				_capacity = 0;
		}
		_size = 0;
	}

	template<typename T>
	void vector<T>::push_back(const T & x) {
		if (!_data || _size >= _capacity)
			expand();
		if (_size < _capacity) {
			T * ele = new T(x);
			*(_data + _size++) = * ele;
		}
	}

	template<typename T>
	void vector<T>::expand(unsigned int extraSize) {
		if (extraSize < 1)
			extraSize = 1;
		T * _temp = new T[_capacity + extraSize];
		if (_temp) {
			for (int i = 0; i < _size; i++)
				*(_temp + i) = *(_data + i);
			delete[] _data;
			_data = _temp;
			_capacity += extraSize;
		}
	}

	template<typename U>
	std::ostream & operator<<(std::ostream & out, vector<U> & v) {
		out << "data[" << v._size << '/'
			<< v._capacity << "] = ";
		for (int i = 0; i < v._size; i++)
			out << *(v._data + i) << ' ';
		out << std::endl;
		return out;
	}

	//Task 1 - 拷贝构造函数
	template<typename T>
	vector<T>::vector(const vector<T> & v) {
		if (v.size()) {
			_data = new T[v.size()];
			if (_data) {
				_capacity = v.size();
				for (int i = 0; i < v.size(); ++i)
					*(_data + i) = *(v._data + i);
				_size = v._size;
			}
		}
		else {
			_data = NULL;
			_size = 0; 
			_capacity;
		}
	}

	//Task 2.1 - operator+hqu::vector
	template<typename T>
	vector<T> vector<T>::operator+(const vector<T> & rhs)const {
		vector<T> result(this->size() + rhs.size());
		for (int i = 0; i < this->size(); ++i)
			result.push_back((*this)[i]);
		for (int i = 0; i < rhs.size(); ++i)
			result.push_back(rhs[i]);
		return result;
	}

	//Task 2.2 - operator+std::vector
	template<typename T>
	vector<T> vector<T>::operator+(const std::vector<T> & rhs)const {
		vector<T> result(this->size() + rhs.size());
		for (int i = 0; i < this->size(); ++i)
			result.push_back((*this)[i]);
		for (int i = 0; i < rhs.size(); ++i)
			result.push_back(rhs[i]);
		return result;
	}

	//Task 3 - operator=
	template<typename T>
	vector<T> & vector<T>::operator=(const vector<T> & rhs) {
		if (this != &rhs) {
			if (rhs.size() > this->capacity())
				expand(rhs.size() - this->capacity());
			if (rhs.size() <= this->capacity()) {
				for (int i = 0; i < rhs.size(); ++i)
					*(_data + i) = *(rhs._data + i);
				_size = rhs.size();
			}
		}
		return *this;
	}

	//Task 4 - operator==
	template<typename T>
	bool vector<T>::operator==(const vector<T> & rhs) {
		bool result = true;
		if (this != &rhs) {
			if (this->size() == rhs.size()) {
				for (int i = 0; i < this->size(); ++i)
					if ((*this)[i] != rhs[i]) {
						result = false;
						break;
					}
			}
			else
				result = false;
		}
		return result;
	}


}

#endif 