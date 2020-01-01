#include<iostream>
using namespace std;

#define max 20

typedef struct{
    int key;
}RcdType;

typedef struct{
    RcdType r[max+1];
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

void Merge(SqList SR,SqList &TR,int i,int m,int n){
        int k;//数组TR的下标
        int j;
        for ( j = m+1,k=i; i<=m && j<=n; k++)
        {
            if (SR.r[i].key<=SR.r[j].key){
                TR.r[k]=SR.r[i];
                i++;
            }
            else{
                TR.r[k]=SR.r[j];
                j++;
            }
 
        }
        if (i<=m)
            for (int a = i; a <= m; a++)
            {
                 TR.r[k]=SR.r[a];
                 k++;
            }
        if (j<=n)
            for (int a = j; a <= n; a++)
            {
                 TR.r[k]=SR.r[a];
                 k++;
            }
             
}

void Merge1(SqList &L,int low,int mid,int high){
        SqList TR;
        char a[high-low+1];
        int k;//数组TR的下标
        int left_low=low;
        int right_low=mid+1;

        for ( k = 1;left_low<=mid&&right_low<=high ; k++)
        {
            if (L.r[left_low].key<=L.r[right_low].key)
            {
                TR.r[k]=L.r[left_low];
                left_low++;
            }else
            {
                TR.r[k]=L.r[right_low];
                right_low++;
            }
            
            
        }
        if (left_low<=mid)
        {
            for(int i=left_low;i<=mid;i++){
                TR.r[k]=L.r[i];
                k++;
            }
            
        }
        if (right_low<=high)
        {
            for(int i=right_low;i<=high;i++)
            {
                TR.r[k]=L.r[i];
                k++;
            }
        }
        
        int x=1;
        for (int i = 0; i <=high-low; i++)
        {
            L.r[low+i]=TR.r[x];
            x++;
        }
        //  delete TR.r;
             
}

void MSort(SqList SR,SqList &TR1,int s,int t){
    SqList TR2;
    if (s==t)
    {
        TR1.r[s]=SR.r[s];
    }else
    {
        int m=(s+t)/2;
        MSort(SR,TR2,s,m);
        MSort(SR,TR2,m+1,t);
        Merge(TR2,TR1,s,m,t);
    }
    
    
}

void MSort1(SqList &L,int low,int high){
    int mid=0;
    if (low<high)
    {
        mid=(low+high)/2;
        MSort1(L,low,mid);
        MSort1(L,mid+1,high);
        Merge1(L,low,mid,high);
    }
    return;
    
    
}
void MergeSort(SqList &L){
    //MSort(L,L,1,L.lenth);
    MSort1(L,1,L.lenth);
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
    MergeSort(sl);
    PrintList(sl);
}