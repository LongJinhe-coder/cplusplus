#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//������ų��� 
#define LIST_INIT_SIZE 50
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2

//����Ԫ������
typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode  *next;
}LNode,*LinkList;
//β�ӷ�����ѭ������ 
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
		//����βָ�� 
		r=p;
		}
		//���һ���ڵ� 
		else if(i==n-1){
			//���һ���ڵ�ָ��ָ���һ���ڵ� 
			p->next=L;
			p->data=n;
			r->next=p;
		}
		
		
	}
}
//����ڵ�ı�� 
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
	//������ passwardlist���洢ÿһ���ڵ������ 
	for(i=1;i<=n;i++){
				printf("�������ӦԪ�ص�����\n");
		scanf("%d",&x);
		passwardlist[i]=x;
	}
		printf("ÿһ��Ԫ�ض�Ӧ������Ϊ\n");
	for(i=1;i<=n;i++){
				printf("%d ",passwardlist[i]);
		
	}
		printf("\n");
				printf("������m�ĳ�ֵ=");
		scanf("%d",&m);
		//��ͷ��㣡������ 
		for(a=1;a<=m-2;a++){
		p=p->next;
	}
		printf("Ԫ�ر�����������˳��Ϊ��\n");
	q=p->next;r=q->data; p->next=q->next; 
	printf("%d ",r);
 
	free(q);
	for(j=1;j<n;j++){
	//��ǰpָ���������ǰһλ���൱��ͷָ�룩������ѭ��������ǰ�治ͬ 
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
		printf("�������ʼԪ�ظ���n=");
	scanf("%d",&n);
	 	printf("\n");
	 LNode *pl = (LNode *)malloc(sizeof(LNode));  
	 CreateList(pl,n);
	 	printf("ÿһ��Ԫ�صı��Ϊ\n");
	PrintList(pl,n);
		printf("\n");
	Run(pl,n);
}
