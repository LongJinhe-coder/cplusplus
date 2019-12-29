#include<iostream>
#include<queue>
using namespace std;

#define OK 1
#define ERROR 0

typedef int status;
typedef char elemtype;

typedef struct BiTNode{
    elemtype data;
    struct BiTNode *lchild,*rchild;
}*BiTree;


status creattree(BiTree &T){
    elemtype ch;
    // cout<<"输入数据"<<endl;
    cin>>ch;
    if (ch!='#')
    {
        T = new BiTNode;
        T->data=ch;
        creattree(T->lchild);
        creattree(T->rchild);
    }
    return OK;
}

status order(BiTree T){
    queue<BiTree> q;
    q.push(T);
    while (!q.empty())
    {
        BiTree p=q.front();
        cout<<p->data;
        if(p->lchild)
        q.push(p->lchild);
        if(p->rchild)
        q.push(p->rchild);
        q.pop();

    }
    
}

status orders(BiTree T,status &truth){
    status booling;
    queue<BiTree> q;
    q.push(T);
    while (!q.empty())
    {   
        // if (!(p->lchild&&p->rchild))
        // {
        //     booling=0;
        // }
        BiTree p=q.front();
        cout<<p->data;
        if(p->lchild&&booling){
            q.push(p->lchild);
        }else if (p->lchild&&!booling)
        {
            truth=0;
            break;
        }
        else
        {
            booling=0;
        }
        
        if(p->rchild&&booling){
            q.push(p->rchild);
        }else if (p->rchild&&!booling)
        {
            truth=0;
            break;
        }
        else
        {
            booling=0;
        }
        
        
        q.pop();

    }
    
}

int main(){
    BiTree t;
    cout<<"按前序初始化二叉树"<<endl;
    creattree(t);
    cout<<"层序遍历结果："<<endl;
    order(t);
    cout<<endl;
    status truth =1;
    orders(t,truth);
    if(truth)
    cout<<"是完全二叉树";
    else
    {
        cout<<"不是完全二叉树";
    }
    

}
