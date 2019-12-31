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

void BubbleSort(SqList &L){
    for (int i = 2; i <= L.lenth; i++)
    {
        int move=0;
        for (int j = L.lenth; j >= i; j--)
        {
            if (L.r[j].key<L.r[j-1].key)
            {
                L.r[0]=L.r[j];
                L.r[j]=L.r[j-1];
                L.r[j-1]=L.r[0];
                move=1;
            }
            
        }
        if(!move) return;
    }
    
}

void Bubble(SqList &L){
    for (int i = 1; i < L.lenth; i++)
    {
        int move=0;
        for (int j = 1; j <= L.lenth-i; j++)
        {
            if (L.r[j].key>L.r[j+1].key)
            {
                L.r[0]=L.r[j];
                L.r[j]=L.r[j+1];
                L.r[j+1]=L.r[0];
                move=1;
            }
            if(!move) return;
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
    //BubbleSort(sl);
    Bubble(sl);
    PrintList(sl);
}