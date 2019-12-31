#include<iostream>
using namespace std;

#define OK 1
#define REEOR 0
#define max 20

typedef int keytype;
typedef int status;

typedef struct{
    keytype key;
}Redtype;

typedef struct{
    Redtype r[max+1];
    int lenth;
}SqList;

void CreatList(SqList &L){
    cout<<"输入元素个数lenth=";
    cin>>L.lenth;
    cout<<"依次输入元素的key";
    for (int i = 1; i <= L.lenth; i++)
    {
        cin>>L.r[i].key;
    }
    
}

void InsertSort(SqList &L){
    
    for (int i = 2; i <=L.lenth ; i++)
    {   
        
        if (L.r[i].key<L.r[i-1].key)
        {
            L.r[0].key=L.r[i].key;
            int j;
            for ( j = i-1; L.r[0].key<L.r[j].key; j--)
            {
                L.r[j+1].key=L.r[j].key;
            }
            L.r[j].key=L.r[0].key;
        }
        
    }
    
}

void PrintList(SqList L){
    for (int i = 1; i <= L.lenth; i++)
    {
        cout<<L.r[i].key<<" ";
    }
    cout<<endl;
}

int main(){
    SqList sl;
    CreatList(sl);
    PrintList(sl);
    InsertSort(sl);
    PrintList(sl);
}