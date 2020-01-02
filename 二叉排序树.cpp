#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*Bitree;

Bitree SearchTree(Bitree T,Bitree &p,ElemType key){
    if(!T){
        return NULL;
    }else{
        if(key<T->data){
            p=T;
            SearchTree(T->lchild,p,key);
        }
        else if(key>T->data){
            p=T;
            SearchTree(T->rchild,p,key);
        }else
        return T;
        
    }
}

void InsertTree(Bitree &T,ElemType key){
    if(!T){
        T=new BiTNode;
        T->data=key;
        T->lchild=NULL;
        T->rchild=NULL;
    }else{
        if(key<T->data)
        InsertTree(T->lchild,key);
        else if(key>T->data)
        InsertTree(T->rchild,key);
        else
        return;
    }
}

void CreatTree(Bitree &T){
    cout<<"输入初始化元素个数";
    int n;
    cin>>n;
    cout<<"输入初始化元素key"<<endl;
    for(int i=0;i<n;i++){
        int key;
        cin>>key;
        InsertTree(T,key);
    }
}

void DeleteTree(Bitree &T,int key){
    Bitree parent=NULL;
    if(!SearchTree(T,parent,key))
    return;
    else{
        Bitree p=SearchTree(T,parent,key);
        if(p->lchild&&p->rchild){
            Bitree q=p;
            Bitree s=p->lchild;
            while(s->rchild){
                q=s;
                s=s->rchild;
            }
            if(q!=p){
                p->data=s->data;
                q->rchild=s->lchild;
                delete s;
            }else{
                p->data=s->data;
                q->lchild=s->lchild;
                delete s; 
            }
        }else{
            Bitree q=p->lchild?p->lchild:p->rchild;
            if(!parent){
                T=q;
                delete p;
            }else{
                if(parent->lchild==p){
                    parent->lchild=q;
                    delete p;
                }else{
                    parent->rchild=q;
                    delete p;
                }
            }
        }
    }
}

void PrintTree(Bitree T){
    if(T){
        PrintTree(T->lchild);
        cout<<T->data<<" ";
        PrintTree(T->rchild);
    }
}

int main(){

    Bitree t=NULL;
    CreatTree(t);
    PrintTree(t);
    cout<<"输入你想要删除的元素";
    int key;
    cin>>key;
    DeleteTree(t,key);
    PrintTree(t);
}