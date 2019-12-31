#include<iostream>
using namespace std;

#define max 20

typedef int ElemType;

typedef struct{
    ElemType key;
    int next;
}LNode;

typedef struct{
    LNode r[max+1];
    int lenth;
}SLinkList;

void CreatList(SLinkList &L){
    cout<<"输入数组初始化长度lenth=";
    cin>>L.lenth;
    cout<<"输入初始化key"<<endl;
    for (int i = 1; i <= L.lenth; i++)
    {
        // cout<<"输入key";
        cin>>L.r[i].key;
    }
    
}

void LInsertSort(SLinkList &L){
    
    L.r[0].next=1;
    L.r[1].next=0;
    for (int i = 2; i <= L.lenth; i++)
    {   
        int j,k;
        for (j = 0,k=L.r[0].next; L.r[k].key<=L.r[i].key; j=k,k=L.r[k].next);
        //找到小于i的位置位于j和k之间
        L.r[j].next=i;//插入i
        L.r[i].next=k;
        
        
    }
    
}

void Arrange(SLinkList &L){
    int p=L.r[0].next;
    for (int i = 1; i < L.lenth; i++)
    {
        while (p<i)//确定当前要交换元素的位置p
        {
            p=L.r[p].next;
        }
        int q=L.r[p].next;//记录下一次要交换元素的位置
        
       if (p!=i)
       {
        L.r[0]=L.r[p];//交换
        L.r[p]=L.r[i];
        L.r[i]=L.r[0];
        L.r[i].next=p;//指向交换元素的位置，使得后面在while循环能找到
       }
       

        p=q;//下一个要交换的位置
    }
    
}

void PrintList(SLinkList L){
    for (int i = 1; i <= L.lenth; i++)
    {
        cout<<L.r[i].key<<" ";
    }
    
}

int main(){
    SLinkList sl;
    CreatList(sl);
    // PrintList(sl);
    LInsertSort(sl);
    Arrange(sl);
    PrintList(sl);
}