#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义符号常量 
#define LIST_INIT_SIZE 50
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2

//定义元素类型
typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode  *next;
}LNode,*LinkList;
//尾接法创建循环链表 
void CreateList(LinkList &L,int n){
	int i;
	LinkList r,p; 
		L=(LinkList)malloc(sizeof(LNode));
		r=L;
		L->data=1;
	for(i=1;i<n;i++){
		p=(LinkList)malloc(sizeof(LNode));
		if(i<n-1){
			p->next=NULL;
			p->data=i+1;
		r->next=p;
		//更换尾指针 
		r=p;
		}
		//最后一个节点 
		else if(i==n-1){
			//最后一个节点指针指向第一个节点 
			p->next=L;
			p->data=n;
			r->next=p;
		}
		
		
	}
}
//输出节点的编号 
void PrintList(LinkList &L,int n)
{
LinkList p;p=L;
int i;
for(i=1;i<=n;i++){
	printf("%d ",p->data);
	p=p->next;
}
}

void Run(LinkList &L,int n){
	LinkList p,q;p=L;
	int i,j,m,k,r,x,a,passwardlist[n]; 
	//用数组 passwardlist来存储每一个节点的密码 
	for(i=1;i<=n;i++){
				printf("请输入对应元素的密码\n");
		scanf("%d",&x);
		passwardlist[i]=x;
	}
		printf("每一个元素对应的密码为\n");
	for(i=1;i<=n;i++){
				printf("%d ",passwardlist[i]);
		
	}
		printf("\n");
				printf("请输入m的初值=");
		scanf("%d",&m);
		//无头结点！！！！ 
		for(a=1;a<=m-2;a++){
		p=p->next;
	}
		printf("元素编号输出的最终顺序为：\n");
	q=p->next;r=q->data; p->next=q->next; 
	printf("%d ",r);
 
	free(q);
	for(j=1;j<n;j++){
	//当前p指向出列数的前一位（相当于头指针），所以循环次数和前面不同 
	for(k=1;k<=passwardlist[r]-1;k++){
		p=p->next;
	}
	q=p->next; p->next=q->next; r=q->data;
	printf("%d ",r);
	free(q);
}
}

int main(){
	int n;
		printf("请输入初始元素个数n=");
	scanf("%d",&n);
	 	printf("\n");
	 LNode *pl = (LNode *)malloc(sizeof(LNode));  
	 CreateList(pl,n);
	 	printf("每一个元素的编号为\n");
	PrintList(pl,n);
		printf("\n");
	Run(pl,n);
}
