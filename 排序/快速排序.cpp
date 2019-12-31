#include<iostream>
using namespace std;

#define max 20

typedef struct{
    int key;
}Node;

typedef struct{
    Node r[max];
    int lenth;
}SqList;

void CreatList(SqList &L){
     cout<<"输入数组初始化长度lenth=";
    cin>>L.lenth;
    cout<<"输入初始化key"<<endl;
    for (int i = 1; i <= L.lenth; i++)
    {
        // cout<<"输入key";
        cin>>L.r[i].key;
    }
}

int Partition(SqList &L,int low,int high){
    L.r[0]=L.r[low];
    int pivokey=L.r[low].key;
    int i=low,j=high;
    while (i<j)
    {
        while (i<j&&L.r[j].key>=pivokey)
        j--;
        L.r[i]=L.r[j];

        while (i<j&&L.r[i].key<=pivokey)
        i++;
        L.r[j]=L.r[i];
        
    }
    L.r[i]=L.r[0];
    return i;//返回基准的位置
}

void QSort(SqList &L,int low, int high){
    if (low<high)
    {
        int pivokey=Partition(L,low,high);
        QSort(L,low,pivokey-1);
        QSort(L,pivokey+1,high);
    }
    
}

void QuickSort(SqList &L){
    QSort(L,1,L.lenth);
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
    QuickSort(sl);
    PrintList(sl);
}