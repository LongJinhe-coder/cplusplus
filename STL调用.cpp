#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> OPND;
    int e;
    for (int i = 0; i < 3; i++)
    {
        OPND.push(i+1);
    }
    
    for (int i = 0; i < 2; i++)
    {
        OPND.pop();
    }
    cout<<OPND.top();
    
}