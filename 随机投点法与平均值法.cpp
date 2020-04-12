#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

double f(double x)
{ //第一题函数计算方法
    return (exp(x) - 1) / (exp(1) - 1);
}

double F(double x)
{ //第二题函数计算方法
    return (exp(2 * x - 1) - exp(-1)) / (exp(1) - exp(-1));
}
double random1(int n)
{
    int count = 0;
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        // double a = rand() % 1000 / (double)1000;
        double a = rand() / (double)(RAND_MAX+1.0);
        // cout<<"a="<<a<<endl;
        double b = rand() / (double)(RAND_MAX+1.0);
        // cout<<"b="<<b<<endl;
        if (a <= f(b))
        {
            count++;
        }
    }
    return count / (double)n;
}
double random2(int n)
{
    int count = 0;
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        double a = rand() / (double)(RAND_MAX+1.0);
        // cout<<"a="<<a<<endl;
        double b = rand() / (double)(RAND_MAX+1.0);
        // cout<<"b="<<b<<endl;
        if (a <= F(b))
        {
            count++;
        }
    }
    return 2 * (exp(1) - exp(-1)) * (count / (double)n) + 2 * exp(-1);
}

double average1(int n)
{
    srand(time(0));
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        double a = rand() / (double)(RAND_MAX+1.0);
        sum += f(a);
    }
    return sum / (double)n;
}
double average2(int n)
{
    srand(time(0));
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        double a = rand() / (double)(RAND_MAX+1.0);
        sum += F(a);
    }
    return 2 * (exp(1) - exp(-1)) * (sum / (double)n) + 2 * exp(-1);
}

int main()
{
    int times = 100000000; //试验次数
    cout << "第一题随机投点法=" << random1(times) << endl;
    cout << "第一题平均值法=" << average1(times) << endl;
    cout << "第二题随机投点法=" << random2(times) << endl;
    cout << "第二题平均值法=" << average2(times) << endl;
}