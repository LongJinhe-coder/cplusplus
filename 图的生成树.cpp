#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
 
#define true 1
#define false 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define max 30

typedef int Status;
typedef int VertexType;

int visited[max];
VertexType allvexdata1[max],allvexdata2[max];
int k=0,x=0;
	//int v;//��ʼ���ʵĽ��λ�� 
typedef struct ArcNode{
	int adjvex;//�û�ָ��Ķ���λ��
	struct ArcNode *nextarc;//ָ����һ������ָ�� 
}ArcNode;

typedef struct VNode{
	VertexType data;//������Ϣ
	ArcNode *firstarc;//��һ�������ڸö���Ļ� 
}VNode,AdjList[max];

typedef struct ALGraph{
	AdjList vertices;
	int vexnum,arcnum;//ͼ�Ķ������ͱ��� 
}ALGraph;


typedef struct QNode{
	VNode data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

typedef struct CSNode{
	VertexType data;
	struct CSNode *lchild,*nextsibling;
}CSNode,*CSTree;
 
//�����ն��� 
Status InitQueue(LinkQueue &Q){
	Q.front=Q.rear=new QNode;
	//Q=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)exit(OVERFLOW); 
//	Q.rear->next=NULL;	
	Q.front->next=NULL;
	return OK;
}
Status EnQueue(LinkQueue &Q,VNode e){
	QueuePtr p=new QNode;
	//QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)exit(OVERFLOW);
	p->data=e; p->next=NULL;//cout<<"�����Ԫ��:"<<e.data;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
	
}

Status DeQueue(LinkQueue &Q,VNode &e){
	
	if(Q.front==Q.rear){
		
		return ERROR;
	}
	QueuePtr p=Q.front->next;
	e=p->data;	//cout<<"������Ԫ��"<<e.data;
	Q.front->next=p->next;
	if(Q.rear==p)Q.rear=Q.front;
	free(p);
	return OK;
}
//����ǰ���㶨λ 
 int LocateVex(ALGraph G,VertexType v){
 	for(int i=0;i<G.vexnum;i++){
 		if(v==G.vertices[i].data)
 		return i;
	 }
	 return OK;
 }
 
 //�����ڽӱ�洢�ṹ 
 Status CreateList(ALGraph &G){
 	int i,j;
 	ArcNode *pi,*pj;
 	VertexType v1,v2;
 	
 	cout<<"������ͼ�Ķ�����"<<endl;
 	cin>>G.vexnum;
 	if(G.vexnum>max){
 		cout<<"���㳬�꣡����";
		 exit(OVERFLOW); 
	 }
	 cout<<"������ͼ�ı���"<<endl;
 	cin>>G.arcnum;
 	//��ÿһ����㸳ֵ 
 	for(int i=0;i<G.vexnum;i++){
 		cout<<"�����붥��"<<i+1<<"��data"<<endl;
 		cin>>G.vertices[i].data;
 		G.vertices[i].firstarc=NULL;
	 }
	 //ͨ���������������ڽӱ� 
	 for(int k=0;k<G.arcnum;k++){
	 		cout<<"�������"<<k+1<<"���ߵ���������"<<endl;
	 		cin>>v1>>v2;
	 		//�ҵ������ӵ�������λ�� 
	 		i=LocateVex(G,v1);
	 		j=LocateVex(G,v2);
	 		if(!(pi=new ArcNode)) exit(OVERFLOW);
	 		pi->adjvex=j;//pi��ָ�򶥵�j 
	 		pi->nextarc=G.vertices[i].firstarc;//ͷ�巨�������� 
	 		G.vertices[i].firstarc=pi;
	 		
	 			if(!(pj=new ArcNode)) exit(OVERFLOW);
	 			pj->adjvex=i;//pj��ָ�򶥵�i 
	 		pj->nextarc=G.vertices[j].firstarc;//ͷ�巨�������� 
	 		G.vertices[j].firstarc=pj;
	 }
	 return OK;
 }
 //����������������� 
 void DFS(ALGraph G,int v,CSTree &T){
 	ArcNode *p;
	int w;
	int first=true;
	CSTree q=NULL;	
 	visited[v]=true;
 	
 
 	//ѭ���ӵ�һ���ڽӵ㿪ʼ�������һ������ 
 	for(p=G.vertices[v].firstarc;p;p=p->nextarc){
 		w=p->adjvex;
 		if(!visited[w]){
 			//���µĽ������ڴ� 
 			CSTree m=new CSNode;
 			m->data=G.vertices[w].data;
 			m->lchild=NULL;
 			m->nextsibling=NULL;
 			//���ǵ�һ�����ڽ�㣬��������Ϊ��ǰ�������� 
 			if(first){
 				T->lchild=m;
 				first=false;
			 }else{
			 	//�����ǵ�һ�����ڽ�㣬������Ϊ��һ�����ڽ����ֵܽ�� 
			 	 q->nextsibling=m;
			 }
			
			 q=m;
 				DFS(G,w,q);
		 }

 	
	 }
 }
 
 void DFSTree (ALGraph G,CSTree &T,int v){
 	//char visited[G.vexnum-1];
 	T=NULL;
 	CSTree q=NULL;
// 	int v;
// 	cout<<"�����뿪ʼ�Ľ��λ��v,ע��1<=v<="<<G.vexnum<<endl;
// 	cin>>v;
 	if(v<1||v>G.vexnum){
 		cout<<"v��λ�ò�����";
		 exit(OVERFLOW); 
	 }
	 //��ÿһ��������������Ϊfalse 
 	for(int i=0;i<G.vexnum;i++){
 		visited[i]=false;
	 }
	 
	 for(int i=0;i<G.vexnum;i++){
	 	if(!visited[v-1]){
	 		//Ϊ�������Ķ�������ڴ� 
	 		CSTree p=new CSNode;
	 		p->data=G.vertices[v-1].data;
	 		p->lchild=NULL;
	 		p->nextsibling=NULL;
	 		if(!T){
	 			T=p;
			 }else{
			 	 q->nextsibling=p;
			 }
			
	 		q=p;
	 		 	DFS(G,v-1,q);
		 }
	
	 	//���ڷ���ͨͼ 
	 	for(int j=0;j<G.vexnum;j++){
	 		if(!visited[j]){
	 			v=j+1;
	 			break;
			 }
		 }
	 }
 } 
 


 //����������������� 
 void BFSTree(ALGraph G,LinkQueue &Q,CSTree &T,int v){
 	ArcNode *p;
 	VNode e;
// 	int v;
 	T=NULL;
 	CSTree q=NULL;
	CSTree t =NULL;
// 	cout<<"�����뿪ʼ�Ľ��λ��v,ע��1<=v<="<<G.vexnum<<endl;
// 	cin>>v;
 	for(int i=0;i<G.vexnum;i++){
 		visited[i]=false;
	 }
	 for(int i=0;i<G.vexnum;i++){
	 	q=t;
	 	if(!visited[v-1]){
	 		//���ʵ��Ľ������� 
	 		EnQueue(Q,G.vertices[v-1]);visited[v-1]=true; 
	 		//Ϊ�������Ķ�������ڴ� 
	 		CSTree m=new CSNode;
 			m->data=G.vertices[v-1].data;
 			m->lchild=NULL;
 			m->nextsibling=NULL;
 			if(!T){
 				
 				T=m;
			 }else{
			 	q->nextsibling=m;
			 }
			 q=m; t=q;//��� 
			 
	 		while(Q.front!=Q.rear){
	 			//�������У����������Ϣ��ֵ��e������ 
	 			DeQueue(Q,e);
	 					int first=true; 
	 		//cout<<"������Ԫ��"<<e.data;
	 		//����ÿ���������ڽ�� 
	 			for(p=e.firstarc;p;p=p->nextarc){
	 			
	 		if(!visited[p->adjvex]){
	 			//�������� 
	 			EnQueue(Q,G.vertices[p->adjvex]);visited[p->adjvex]=true;
	 			//�����ڴ� 
					CSTree m=new CSNode;
 			m->data=G.vertices[p->adjvex].data;
 			m->lchild=NULL;
 			m->nextsibling=NULL;
 			//���ǵ�һ�����ڽ�㣬��������Ϊ��ǰ�������� 
 			if(first){
 				q->lchild=m;
 				first=false;
			 }else{
			 		//�����ǵ�һ�����ڽ�㣬������Ϊ��һ�����ڽ����ֵܽ�� 
			 	q->nextsibling=m;
			 }
			 q=m;
 				
			 }
			 
		 }
			 }
	 		
		 }
		 //���ڱ�������ͨͼ 
		 for(int j=0;j<G.vexnum;j++){
	 		if(!visited[j]){
	 			v=j+1;
	 			break;
			 }
		 }
	 	
	 } 

	 
 }
 //ǰ�������������� 
void PrintTree(CSTree T){
	if(T){
		cout<<T->data<<" ";
		PrintTree(T->lchild);
		 	PrintTree(T->nextsibling);
	}
}
 int main(){
 	ALGraph G;
 	CSTree T1,T2;
 	LinkQueue q;
 	InitQueue(q);
 	
 	CreateList(G);
 	//int visited[G.vexnum-1];
 //	Test(G,q);
 	int v;
 	cout<<"�����뿪ʼ�Ľ��λ��v,ע��1<=v<="<<G.vexnum<<endl;
 	cin>>v;
 	DFSTree(G,T1,v);
 
 	BFSTree(G,q,T2,v);
 	cout<<"�������������ǰ���������:"<<endl;
 	PrintTree(T1);
 	cout<<endl<<"�������������ǰ���������:"<<endl;
 		PrintTree(T2);
 } 
