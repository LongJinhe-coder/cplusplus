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
VertexType allvexdata1[max],allvexdata2[max];
int k=0,x=0;
//	int index;
//	int v;//��ʼ���ʵĽ��λ�� 
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
 //����������� 
 void DFS(ALGraph G,int v){
 	ArcNode *p;
	int w;
		
 	visited[v]=true;
 	
 	//�����α��������ݴ������� 
 	allvexdata1[k]=G.vertices[v].data;
 	k++;
 	//ѭ���ӵ�һ���ڽӵ㿪ʼ�������һ������ 
 	for(p=G.vertices[v].firstarc;p;p=p->nextarc){
 		w=p->adjvex;
 		if(!visited[w])
 		//�ݹ���� 
 		DFS(G,w);
	 }
 }
 
 void DFSTravers(ALGraph G,int v){
 	
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
	 	DFS(G,v-1);
	 	//���ڷ���ͨͼ 
	 	for(int j=0;j<G.vexnum;j++){
	 		if(!visited[j]){
	 			v=j+1;
	 			allvexdata1[k]=-1;//��0����¼����ͨͼ�Ķϵ� 
 	k++;
	 			break;
			 }
		 }
	 }
 } 
 

 Status DFSPrint(){
 	cout<<"�������������������������:"<<endl;
 	int i=0;
 	//ѭ��������� 
 	while(allvexdata1[i]){
 		if(allvexdata1[i]!=-1){
 			cout<<allvexdata1[i];
 	
		 } 
 			i++;
	 }
	 int j=0; 
	 cout<<endl<<"������������������ı߼�����:"<<endl;
	 while(allvexdata1[j+1]){
	 	if(allvexdata1[j]!=-1&&allvexdata1[j+1]!=-1)
 		cout<<allvexdata1[j]<<"---"<<allvexdata1[j+1]<<", ";
 		j++;
	 }
	 cout<<endl;
	 return OK;
 }
 
 Status BFSPrint(){
 	cout<<"�������������������������:"<<endl;
 	int i=0;
 		//ѭ��������� 
 	while(allvexdata2[i]){
 		if(allvexdata2[i]!=-1)
 		cout<<allvexdata2[i];
 		i++;
	 }
	 int j=0;
	 cout<<endl<<"������������������ı߼�����:"<<endl;
	 while(allvexdata2[j+1]){
	 	if(allvexdata2[j]!=-1&&allvexdata2[j+1]!=-1)
 		cout<<allvexdata2[j]<<"---"<<allvexdata2[j+1]<<", ";
 		j++;
	 }
	 cout<<endl;
	 return OK;
	 
 }
 //����������� 
 void BFSTraverse(ALGraph G,LinkQueue &Q,int v){
 	ArcNode *p;
 	VNode e;

 	for(int i=0;i<G.vexnum;i++){
 		visited[i]=false;
	 }
	 for(int i=0;i<G.vexnum;i++){
	 	if(!visited[v-1]){
	 		//���ʵ��Ľ����ջ 
	 		EnQueue(Q,G.vertices[v-1]);visited[v-1]=true; 
	 		//���ѷ��ʽ������ݴ������� 
			 allvexdata2[x]=G.vertices[v-1].data;
 				x++;
 			
	 		while(Q.front!=Q.rear){
	 			//����ջ�����������Ϣ��ֵ��e������ 
	 			DeQueue(Q,e);
	 					 
	 		//cout<<"��ջԪ��"<<e.data;
	 		//����ÿ���������ڽ�� 
	 			for(p=e.firstarc;p;p=p->nextarc){
	 			
	 		if(!visited[p->adjvex]){
	 			
	 			EnQueue(Q,G.vertices[p->adjvex]);visited[p->adjvex]=true;
				 allvexdata2[x]=G.vertices[p->adjvex].data;
 				x++;	//cout<<"����"<<endl;
 				
			 }
			 
		 }
			 }
	 		
		 }
		 //���ڱ�������ͨͼ 
		 for(int j=0;j<G.vexnum;j++){
	 		if(!visited[j]){
	 			v=j+1;
	 			 allvexdata2[x]=-1;//��0����¼����ͨͼ�Ķϵ� 
 				x++;
	 			break;
			 }
		 }
	 	
	 } 

	 
 }
 
// void Test(ALGraph G,LinkQueue &Q){
// 		VNode e;
// 	for(int i=0;i<G.vexnum;i++){
// 		EnQueue(Q,G.vertices[i]);
//	 }
//	 for(int i=0;i<G.vexnum;i++){
// 		DeQueue(Q,e);
//	 }
// }
 int main(){
 	ALGraph G;
 	
 	LinkQueue q;
 	InitQueue(q);
 	
 	CreateList(G);
 	//int visited[G.vexnum-1];
 //	Test(G,q);
 int v;
 	cout<<"�����뿪ʼ�Ľ��λ��v,ע��1<=v<="<<G.vexnum<<endl;
 	cin>>v;
 	DFSTravers(G,v);
 	DFSPrint();
 	BFSTraverse(G,q,v);
 	BFSPrint();
 } 
