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

void CreatList(SqList &H){
    cout<<"初始化数组长度lenth=";
    cin>>H.lenth;
    cout<<"初始化key"<<endl;
    for (int i = 1; i <= H.lenth; i++)
    {
        cin>>H.r[i].key;
    }
    
}

void HeapAdjust(SqList &H,int s, int m){
    H.r[0]=H.r[s];
    for (int j = 2*s; j <= m; j*=2)
    {
        if (j<m&&H.r[j].key<H.r[j+1].key)
        j++;//找到key较大的孩子
        if(H.r[0].key>=H.r[j].key) break;
        H.r[s]=H.r[j];
        s=j;
        
    }
    H.r[s]=H.r[0];
}

void HeapSort(SqList &H){
    for (int i = H.lenth/2; i > 0; i--)
    {
        HeapAdjust(H,i,H.lenth);
    }

    for (int i = H.lenth; i > 1; i--)
    {
        H.r[0]=H.r[i];
        H.r[i]=H.r[1];
        H.r[1]=H.r[0];
        HeapAdjust(H,1,i-1);
    }
    
    
}

void PrintList(SqList H){
    for (int i = 1; i <= H.lenth; i++)
    {
        cout<<H.r[i].key<<" ";
    }
    
}

int main(){
    SqList H;
    CreatList(H);
    HeapSort(H);
    PrintList(H);
}