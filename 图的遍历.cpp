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
//	int v;//开始访问的结点位置 
typedef struct ArcNode{
	int firstvex;//该弧依附的顶点位置 
	int adjvex;//该弧指向的顶点位置
	struct ArcNode *nextarc;//指向下一条弧的指针 
}ArcNode;

typedef struct VNode{
	VertexType data;//顶点信息
	ArcNode *firstarc;//第一条依附于该顶点的弧 
}VNode,AdjList[max];

typedef struct ALGraph{
	AdjList vertices;
	int vexnum,arcnum;//图的顶点数和边数 
}ALGraph;


typedef struct QNode{
	VNode data;//借助栈来存储顶点，用于广度优先搜索 
	ArcNode arc;//借助栈来存储弧，用于记录生成树边集 
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
//创建空队列 
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
	p->data=e; p->next=NULL;//cout<<"入栈元素:"<<e.data;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
	
}
Status EnQueue2(LinkQueue &Q,ArcNode e){
	QueuePtr p=new QNode;
	//QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)exit(OVERFLOW);
	p->arc=e; p->next=NULL;//cout<<"入栈元素:"<<e.data;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
	
}

Status DeQueue(LinkQueue &Q,VNode &e){
	
	if(Q.front==Q.rear){
		
		return ERROR;
	}
	QueuePtr p=Q.front->next;
	e=p->data;	//cout<<"出栈元素"<<e.data;
	Q.front->next=p->next;
	if(Q.rear==p)Q.rear=Q.front;
	free(p);
	return OK;
}
//给当前顶点定位 
 int LocateVex(ALGraph G,VertexType v){
 	for(int i=0;i<G.vexnum;i++){
 		if(v==G.vertices[i].data)
 		return i;
	 }
	 return OK;
 }
 
 //创建邻接表存储结构 
 Status CreateList(ALGraph &G){
 	int i,j;
 	ArcNode *pi,*pj;
 	VertexType v1,v2;
 	
 	cout<<"请输入图的顶点数"<<endl;
 	cin>>G.vexnum;
 	if(G.vexnum>max){
 		cout<<"顶点超标！！！";
		 exit(OVERFLOW); 
	 }
	 cout<<"请输入图的边数"<<endl;
 	cin>>G.arcnum;
 	//给每一个结点赋值 
 	for(int i=0;i<G.vexnum;i++){
 		cout<<"请输入顶点"<<i+1<<"的data"<<endl;
 		cin>>G.vertices[i].data;
 		G.vertices[i].firstarc=NULL;
	 }
	 //通过遍历边来建立邻接表 
	 for(int k=0;k<G.arcnum;k++){
	 		cout<<"请输入第"<<k+1<<"条边的两个顶点"<<endl;
	 		cin>>v1>>v2;
	 		//找到与边相接的两顶点位置 
	 		i=LocateVex(G,v1);
	 		j=LocateVex(G,v2);
	 		if(!(pi=new ArcNode)) exit(OVERFLOW);
	 		pi->firstvex=i;//pi弧依附的顶点i位置 
	 		pi->adjvex=j;//pi弧指向顶点j 
	 		pi->nextarc=G.vertices[i].firstarc;//头插法创建链表 
	 		G.vertices[i].firstarc=pi;
	 		
	 			if(!(pj=new ArcNode)) exit(OVERFLOW);
	 			pj->firstvex=j;//pj弧依附的顶点j位置 
	 			pj->adjvex=i;//pj弧指向顶点i 
	 		pj->nextarc=G.vertices[j].firstarc;//头插法创建链表 
	 		G.vertices[j].firstarc=pj;
	 }
	 return OK;
 }
 //深度优先搜索 
 void DFS(ALGraph G,int v,LinkQueue &Q){
 	ArcNode *p;
	int w;
		
 	visited[v]=true;
 	cout<<G.vertices[v].data<<" ";
 
 	//循环从第一个邻接点开始，到最后一个结束 
 	for(p=G.vertices[v].firstarc;p;p=p->nextarc){
 		
 		w=p->adjvex;
 		if(!visited[w]){
 			EnQueue2(Q,*p);//当前弧进队列 
 			//递归遍历 
 		DFS(G,w,Q);
		 }
 		
	 }
 }
 
 void DFSTravers(ALGraph G,int v,LinkQueue &Q){
 	
 	if(v<1||v>G.vexnum){
 		cout<<"v的位置不合理";
		 exit(OVERFLOW); 
	 }
	 //将每一个结点访问数组设为false 
 	for(int i=0;i<G.vexnum;i++){
 		visited[i]=false;
	 }
	 
	 for(int i=0;i<G.vexnum;i++){
	 	if(!visited[v-1])
	 	DFS(G,v-1,Q);
	 	//用于非联通图 
	 	for(int j=0;j<G.vexnum;j++){
	 		if(!visited[j]){
	 			v=j+1;
	 			break;
			 }
		 }
	 }
 } 

 //广度优先搜索 
 void BFSTraverse(ALGraph G,LinkQueue &Q,LinkQueue &Q2,int v){
 	ArcNode *p;
 	VNode e;

 	for(int i=0;i<G.vexnum;i++){
 		visited[i]=false;
	 }
	 for(int i=0;i<G.vexnum;i++){
	 	if(!visited[v-1]){
	 		//访问到的结点入队列 
	 		EnQueue(Q,G.vertices[v-1]);visited[v-1]=true; 
	 		cout<<G.vertices[v-1].data<<" ";
 			
	 		while(Q.front!=Q.rear){
	 			//结点出队列，并将结点信息赋值给e传出来 
	 			DeQueue(Q,e);
	 					 
	 		//cout<<"出队列元素"<<e.data;
	 		//遍历每个结点的相邻结点 
	 			for(p=e.firstarc;p;p=p->nextarc){
	 			
	 		if(!visited[p->adjvex]){
	 			EnQueue2(Q2,*p);//当前弧进队列 
	 			EnQueue(Q,G.vertices[p->adjvex]);visited[p->adjvex]=true;
	 			cout<<G.vertices[p->adjvex].data<<" ";
 				
			 }
			 
		 }
			 }
	 		
		 }
		 //用于遍历非联通图 
		 for(int j=0;j<G.vexnum;j++){
	 		if(!visited[j]){
	 			v=j+1;
	 			break;
			 }
		 }
	 	
	 } 

	 
 }
 //打印生成树边集 
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
 	cout<<"请输入开始的结点位置v,注意1<=v<="<<G.vexnum<<endl;
 	cin>>v;
 	cout<<"深度优先搜索顺序：";
 	DFSTravers(G,v,q1);
 	cout<<endl<<"深度优先搜索生成树边集：";
 	PrintArc(G,q1);
 	//DFSPrint();
 	cout<<endl<<"广度优先搜索顺序：";
 	BFSTraverse(G,q,q2,v);
 	cout<<endl<<"广度优先搜索生成树边集：";
 	PrintArc(G,q2);
 	//BFSPrint();
 } 
