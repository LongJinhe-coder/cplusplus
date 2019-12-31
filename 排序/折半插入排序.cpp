#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define max 20

typedef int ElemType;
typedef int status;

typedef struct{
    ElemType key;
}RedType;

typedef struct{
    RedType r[max];
    int lenth;
}SqList;

status CreatList(SqList &L){
    cout<<"输入数组初始化长度lenth=";
    cin>>L.lenth;
    cout<<"输入每一个元素的key值"<<endl;
    for (int i = 1; i <= L.lenth; i++)
    {
        cin>>L.r[i].key;
    }

    return OK;
}

status BInsertSort(SqList &L){
    
    for (int i = 2; i <= L.lenth; i++)
    {
        L.r[0]=L.r[i];
        int low=1,high=i-1;
        int mid;
        while (low<=high)
        {
             mid=(high-low)/2+low;
            if(L.r[0].key<L.r[mid].key)
            high=mid-1;
            else
            low=mid+1;
        }

        for (int j = i-1; j >= high+1; j--)
        {
            L.r[j+1]=L.r[j];
        }
        L.r[high+1]=L.r[0];
        
    }
    return OK;
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
    BInsertSort(sl);
    PrintList(sl); 
}