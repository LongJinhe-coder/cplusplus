#include<iostream>
#include<string.h>
using namespace std;

#define True 1
#define False 0

typedef int status;
typedef int Elemtype;

 
typedef struct BiTNode{
    Elemtype data;
    char message[10];
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//同时标记双亲结点
BiTree SearchTree(BiTree T,BiTree &p,Elemtype key){
    if (!T)
    {
        
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
//不标记双亲结点
BiTree SearchTrees(BiTree T,Elemtype key){
    if (!T)
    {
        
        return NULL;
    }else if (key<T->data)
    {   
        
        return SearchTrees(T->lchild,key);
    }else if (key>T->data)
    {   
        
        return SearchTrees(T->rchild,key);
    }else
    {
        return T;
    }
    
    
    
}

status InsertTree(BiTree &T,Elemtype key,char *message){
    if (!T)
    {
        T=new BiTNode;
        T->data=key;
        //T->message=message;
        strcpy(T->message,message);
        T->lchild=NULL;
        T->rchild=NULL;
    }else if (key<T->data)
    {
        InsertTree(T->lchild,key,message);
    }else if (key>T->data)
    {
        InsertTree(T->rchild,key,message);
    }else
    {
        return False;//树中已经有相同节点
    }
    
    return True;
    
}

status InsertTrees(BiTree &T,Elemtype key,char *message,int &count){
    if (!T)
    {
        T=new BiTNode;
        T->data=key;
        //T->message=message;
        strcpy(T->message,message);
        T->lchild=NULL;
        T->rchild=NULL;
        count++;
    }else if (key<T->data)
    {
        count++;
        InsertTrees(T->lchild,key,message,count);
    }else if (key>T->data)
    {   
        count++;
        InsertTrees(T->rchild,key,message,count);
    }else
    {
        return False;//树中已经有相同节点
    }
    
    return True;
    
}
status DeleteTree(BiTree &T,Elemtype key){
    BiTree parent=NULL;//找到双亲结点
    BiTree p=SearchTree(T,parent,key);
    
    //度为2
    if(p->lchild&&p->rchild)
    {
        BiTree s=p->lchild;
        BiTree q=p;    
        while (s->rchild)
        {
            q=s;
            s=s->rchild;
        }
        // if (parent->lchild==p)
        // {
        //     parent->lchild=p->lchild;
        //     s->rchild=p->rchild;
        //     delete p;
        // }else if(parent->rchild==p)
        // {
        //     parent->rchild=p->lchild;
        //     s->rchild=p->rchild;
        //     delete p;
        // }
       if (q!=p)
       {
           p->data=s->data;
           strcpy( p->message,s->message);
           q->rchild=s->lchild;
           delete s;
       }else
       {
           p->data=s->data;
           strcpy( p->message,s->message);
           q->lchild=s->lchild;
           delete s;
       }  
    }else//度为1或0
    {
        BiTree q=p->lchild?p->lchild:p->rchild;
    if (!parent)
    {
        T=q;
        delete p;
    }else if(parent->lchild==p)
    {
        parent->lchild=q;
        delete p;
    }else
    {
        parent->rchild=q;
        delete p;
    }
    }
    
     return True;
}
//不用双亲结点的删除方法
status Delete(BiTree &T,Elemtype key){
    BiTree p=SearchTrees(T,key);
    BiTree q=p;
    if (!p->lchild)//度为1or0
    {
        p=p->rchild;
        delete q;
        cout<<p->data<<"我是p";
        if (p)
        {
           cout<<"我还在"<<endl;
        }
        
        // p->data=p->rchild->data;
        // free(p);
    }else if (!p->rchild)
    {
        p=p->lchild;
    }else//度为2
    {
        BiTree s=p->lchild;
        while (s->rchild)
        {
            s=s->rchild;
        }
        cout<<"此时s="<<s->data<<endl;
        // p=p->lchild;
        cout<<"此时p="<<p->data<<endl;
        s->rchild=q->rchild;
        BiTree left=p->lchild;
        p->data=p->lchild->data;
        p->lchild=left->lchild;
        p->rchild=left->rchild;

        cout<<"6de右孩子="<<T->rchild->data<<endl;
        
        
}
return True;
}
status CreatTree(BiTree &T){
    int n;
    
    cout<<"输入初始化树的数目"<<endl;
    cin>>n;
    cout<<"输入初始树的结点data与messige"<<endl;
    for (int i = 0; i < n; i++)
    {   
        Elemtype key;
        cin>>key;
        char message[10];
        cin>>message;
        InsertTree(T,key,message);
    }
    
}

void PrintTree(BiTree T){
    if (T)
    {
        PrintTree(T->lchild);
        cout<<T->data<<" ";
        cout<<T->message<<" ";
        PrintTree(T->rchild);
    }
    
}
int main(){
    BiTree t;
    CreatTree(t);
    PrintTree(t);
    // cout<<"插入一个新结点"<<endl;
    // int k;
    // cin>>k;
    // InsertTree(t,k);
    // PrintTree(t);
    // cout<<endl;
    // cout<<"搜索结点"<<endl;
    // int a;

    // cin>>a;
    // BiTree s;
    
    // cout<<"值=";
    // cout<<SearchTree(t,s,a)->data;
    // int counting=0;
    cout<<"插入一个元素"<<endl;
    int a;
    cin>>a;
    char messages[10];
    cin>>messages;
    int counting;
    // count=0;
    InsertTrees(t,a,messages,counting);
    cout<<"插入的元素在第"<<counting<<"层"<<endl;
    cout<<"删除一个元素"<<endl;
    int b;
    cin>>b;
    DeleteTree(t,b);
    
    //Delete(t,b);
    
    PrintTree(t);
    
    //6 3 9 1 4 7 10 2 5 8 11
}