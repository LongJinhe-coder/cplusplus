#include<iostream>
#include<stdio.h>
#include<stdlib.h>
//#include<iomanip>
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

int k=0,x=0;
//	int index;
//	int v;//��ʼ���ʵĽ��λ�� 
typedef struct ArcNode{
	int firstvex;//�û������Ķ���λ�� 
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
	VNode data;//����ջ���洢���㣬���ڹ���������� 
	ArcNode arc;//����ջ���洢�������ڼ�¼�������߼� 
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
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
	p->data=e; p->next=NULL;//cout<<"��ջԪ��:"<<e.data;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
	
}
Status EnQueue2(LinkQueue &Q,ArcNode e){
	QueuePtr p=new QNode;
	//QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)exit(OVERFLOW);
	p->arc=e; p->next=NULL;//cout<<"��ջԪ��:"<<e.data;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
	
}

Status DeQueue(LinkQueue &Q,VNode &e){
	
	if(Q.front==Q.rear){
		
		return ERROR;
	}
	QueuePtr p=Q.front->next;
	e=p->data;	//cout<<"��ջԪ��"<<e.data;
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
	 		pi->firstvex=i;//pi�������Ķ���iλ�� 
	 		pi->adjvex=j;//pi��ָ�򶥵�j 
	 		pi->nextarc=G.vertices[i].firstarc;//ͷ�巨�������� 
	 		G.vertices[i].firstarc=pi;
	 		
	 			if(!(pj=new ArcNode)) exit(OVERFLOW);
	 			pj->firstvex=j;//pj�������Ķ���jλ�� 
	 			pj->adjvex=i;//pj��ָ�򶥵�i 
	 		pj->nextarc=G.vertices[j].firstarc;//ͷ�巨�������� 
	 		G.vertices[j].firstarc=pj;
	 }
	 return OK;
 }
 //����������� 
 void DFS(ALGraph G,int v,LinkQueue &Q){
 	ArcNode *p;
	int w;
		
 	visited[v]=true;
 	cout<<G.vertices[v].data<<" ";
 
 	//ѭ���ӵ�һ���ڽӵ㿪ʼ�������һ������ 
 	for(p=G.vertices[v].firstarc;p;p=p->nextarc){
 		
 		w=p->adjvex;
 		if(!visited[w]){
 			EnQueue2(Q,*p);//��ǰ�������� 
 			//�ݹ���� 
 		DFS(G,w,Q);
		 }
 		
	 }
 }
 
 void DFSTravers(ALGraph G,int v,LinkQueue &Q){
 	
 	if(v<1||v>G.vexnum){
 		cout<<"v��λ�ò�����";
		 exit(OVERFLOW); 
	 }
	 //��ÿһ��������������Ϊfalse 
 	for(int i=0;i<G.vexnum;i++){
 		visited[i]=false;
	 }
	 
	 for(int i=0;i<G.vexnum;i++){
	 	if(!visited[v-1])
	 	DFS(G,v-1,Q);
	 	//���ڷ���ͨͼ 
	 	for(int j=0;j<G.vexnum;j++){
	 		if(!visited[j]){
	 			v=j+1;
	 			break;
			 }
		 }
	 }
 } 

 //����������� 
 void BFSTraverse(ALGraph G,LinkQueue &Q,LinkQueue &Q2,int v){
 	ArcNode *p;
 	VNode e;

 	for(int i=0;i<G.vexnum;i++){
 		visited[i]=false;
	 }
	 for(int i=0;i<G.vexnum;i++){
	 	if(!visited[v-1]){
	 		//���ʵ��Ľ������� 
	 		EnQueue(Q,G.vertices[v-1]);visited[v-1]=true; 
	 		cout<<G.vertices[v-1].data<<" ";
 			
	 		while(Q.front!=Q.rear){
	 			//�������У����������Ϣ��ֵ��e������ 
	 			DeQueue(Q,e);
	 					 
	 		//cout<<"������Ԫ��"<<e.data;
	 		//����ÿ���������ڽ�� 
	 			for(p=e.firstarc;p;p=p->nextarc){
	 			
	 		if(!visited[p->adjvex]){
	 			EnQueue2(Q2,*p);//��ǰ�������� 
	 			EnQueue(Q,G.vertices[p->adjvex]);visited[p->adjvex]=true;
	 			cout<<G.vertices[p->adjvex].data<<" ";
 				
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
 //��ӡ�������߼� 
 void PrintArc(ALGraph G,LinkQueue Q){
 	while(Q.front!=	Q.rear){
 		cout<<G.vertices[Q.front->next->arc.firstvex].data<<"--"
		 <<G.vertices[Q.front->next->arc.adjvex].data<<" ";
		 Q.front=Q.front->next;
	 }
 }

 int main(){
 	ALGraph G;
 	
 	LinkQueue q;
 	InitQueue(q);
 	LinkQueue q1;
 	InitQueue(q1);
 	LinkQueue q2;
 	InitQueue(q2);
 	CreateList(G);
 
 int v;
 	cout<<"�����뿪ʼ�Ľ��λ��v,ע��1<=v<="<<G.vexnum<<endl;
 	cin>>v;
 	cout<<"�����������˳��";
 	DFSTravers(G,v,q1);
 	cout<<endl<<"������������������߼���";
 	PrintArc(G,q1);
 	//DFSPrint();
 	cout<<endl<<"�����������˳��";
 	BFSTraverse(G,q,q2,v);
 	cout<<endl<<"������������������߼���";
 	PrintArc(G,q2);
 	//BFSPrint();
 } 
