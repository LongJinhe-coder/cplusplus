#include<iostream>
using namespace std;

#define True 1
#define False 0

typedef int status;
typedef int Elemtype;

typedef struct BiTNode{
    Elemtype data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree SearchTree(BiTree T,BiTree &p,Elemtype key){
    if (!T)
    {
        p=T;
        return NULL;
    }else if (key<T->data)
    {   
        p=T;
        return SearchTree(T->lchild,p,key);
    }else if (key>T->data)
    {   
        p=T;
        return SearchTree(T->rchild,p,key);
    }else
    {
        return T;
    }
    
    
    
}

status InsertTree(BiTree &T,Elemtype key){
    if (!T)
    {
        T=new BiTNode;
        T->data=key;
        T->lchild=NULL;
        T->rchild=NULL;
    }else if (key<T->data)
    {
        InsertTree(T->lchild,key);
    }else if (key>T->data)
    {
        InsertTree(T->rchild,key);
    }else
    {
        return False;//树中已经有相同节点
    }
    
    return True;
    
}

status CreatTree(BiTree &T){
    int n;
    
    cout<<"输入初始化树的数目"<<endl;
    cin>>n;
    cout<<"输入初始树的结点"<<endl;
    for (int i = 0; i < n; i++)
    {   
        Elemtype key;
        cin>>key;
        InsertTree(T,key);
    }
    
}

void PrintTree(BiTree T){
    if (T)
    {
        PrintTree(T->lchild);
        cout<<T->data<<" ";
        PrintTree(T->rchild);
    }
    
}
int main(){
    BiTree t;
    CreatTree(t);
    PrintTree(t);
    cout<<"插入一个新结点"<<endl;
    int k;
    cin>>k;
    InsertTree(t,k);
    PrintTree(t);
    cout<<endl;
    cout<<"搜索结点"<<endl;
    int a;

    cin>>a;
    BiTree s;
    
    cout<<"值=";
    cout<<SearchTree(t,s,a)->data;
}