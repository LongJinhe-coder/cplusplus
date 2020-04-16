#ifndef STRING_H_
#define STRING_H_
#include <iostream>
#include <fstream>
#include <cassert>
#include <string.h>
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
namespace hqu
{
class string
{
private:
    char *_data;
    unsigned int _size;
    unsigned int _capacity;

public:
    //构造函数
    string();
    string(const char *str);
    string(const string &rhs);
    //析构函数
    ~string();
    //其他成员函数
    void print() const;
    int size() const;
    int capacity() const;
    bool empty() const;
    bool insert(int off, char ch);
    void append(const char *str);
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

    friend std::ostream &operator<<(std::ostream &out, const string &rhs)
    {
        out << rhs._data; //_data:private
        return out;
    } //该友元函数被视为“inline”（内联）

    //string + int, string + c-string, .....
    //v0.6: string+string:（1）函数名operator+，（2）参数string, string，（3）返回？
    friend const string operator+(const string &lhs, const string &rhs)
    {
        //提问1：为什么两个参数都是const --参加运算的两个参数不应该被修改
        //提问2：为什么返回也是const -- 运算结果可以作为l-value？=
        //提问3：返回为什么没有pass by reference
        string result(lhs); //借用了拷贝构造函数
        result.append(rhs._data);
        return result;
    }

    //v0.6: string+std::string
    friend const string operator+(const string &lhs, const std::string &rhs)
    {
        string result(lhs);
        result.append(rhs.c_str());
        return result;
    }

    //v0.6: std::string+string
    friend const string operator+(const std::string &lhs, const string &rhs)
    {
        string result(lhs.c_str());
        result.append(rhs._data);
        return result;
    }

    //v0.6: string + c-string: str1 + "World!";
    friend const string operator+(const string &lhs, const char *rhs)
    {
        string result(lhs);
        result.append(rhs);
        return result;
    }
    //v0.6: string + char: str1 + "!";
    friend const string operator+(const string &lhs, const char rhs)
    {
        string result(lhs);
        result.insert(result.size() - 1, rhs);
        return result;
    }
    //v0.6: string + int: str1 + "5";
    friend const string operator+(const string &lhs, const int rhs)
    {
        string result(lhs);
        std::string str(std::to_string(rhs));
        result.append(str.c_str());
        return result;
    }

    //v0.8: string += string
    friend string &operator+=(string &lhs, const string &rhs)
    {
        //提问1：为什么左参没有const，右边const - lhs将被修改且返回
        //提问2：为什么返回不是const - 返回可能作为l-value出现
        //提问3：为什么返回是pass by reference - lhs要作为运算数参与后续可能的运算
        lhs.append(rhs._data);
        return lhs;
    }

    //v1.0: string=="hello!";
    friend bool operator==(const string &lhs, const string &rhs)
    {
        if (lhs.size() != rhs.size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < lhs.size(); i++)
            {
                if (*(lhs._data + i) != *(rhs._data))
                    return false;
            }
            return true;
        }
    }

    //v1.0: string=="hello!";
    friend bool operator!=(const string &lhs, const string &rhs)
    {
        for (int i = 0; i < lhs.size(); i++)
        {
            if (*(lhs._data + i) != *(rhs._data))
                return true;
        }
        return false;
    }

    friend std::ifstream &operator>>(std::ifstream &fin, string &rhs)
    {
        string tempStr;
        while (!fin.eof())
        {
            if (tempStr._size >= tempStr._capacity)
                tempStr.resize(DELTA_CAPACITY);
            fin >> tempStr._data;
            if (!fin)
                break;
            rhs.append(tempStr._data);
        }
        fin.close();
        return fin;
    }
    //c-string + string: "Hi!"
    //v0.9
    //[], e.g. (1) cout << str[0]; (2) str[0] = 'h';
    //只能基于成员函数实现
    //返回为什么是pass by reference?
    //返回为什么不是const？
    char &operator[](int i)
    {
        assert(i >= 0 && i < _size);
        return *(_data + i);
    }
    //==

private:
    //成员函数（私有，私用目的，无须对外暴露）
    void resize(int delta = DELTA_CAPACITY);
};
} // namespace hqu
#endif