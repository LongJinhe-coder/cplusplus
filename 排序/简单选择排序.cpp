#include<iostream>
using namespace std;

#define max 20

typedef struct{
    int key;
}Node;

typedef struct{
    Node r[max+1];
    int lenth;
}SqList;

void CreatList(SqList &L){
    cout<<"初始化数组长度lenth=";
    cin>>L.lenth;
    cout<<"初始化key"<<endl;
    for (int i = 1; i <= L.lenth; i++)
    {
        cin>>L.r[i].key;
    }
    
}

void SelectSort(SqList &L){
    for (int i = 1; i < L.lenth; i++)
    {
        int min=i;
        for (int j = i+1; j <= L.lenth; j++)
        {
            if(L.r[j].key<L.r[min].key)
            min=j;
        }
        if (min!=i)
        {
            L.r[0]=L.r[min];
            L.r[min]=L.r[i];
            L.r[i]=L.r[0];
        }
        
    }
    
}

void PrintList(SqList L){
    for (int i = 1; i <= L.lenth; i++)
    {
        cout<<L.r[i].key<<" ";
    }
    
}

int main(){
    SqList sl;
    CreatList(sl);
    SelectSort(sl);
    PrintList(sl);
}