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
//	int v;//开始访问的结点位置 
typedef struct ArcNode{
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
	VNode data;
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
	 		pi->adjvex=j;//pi弧指向顶点j 
	 		pi->nextarc=G.vertices[i].firstarc;//头插法创建链表 
	 		G.vertices[i].firstarc=pi;
	 		
	 			if(!(pj=new ArcNode)) exit(OVERFLOW);
	 			pj->adjvex=i;//pj弧指向顶点i 
	 		pj->nextarc=G.vertices[j].firstarc;//头插法创建链表 
	 		G.vertices[j].firstarc=pj;
	 }
	 return OK;
 }
 //深度优先搜索 
 void DFS(ALGraph G,int v){
 	ArcNode *p;
	int w;
		
 	visited[v]=true;
 	
 	//将依次遍历的数据存入数组 
 	allvexdata1[k]=G.vertices[v].data;
 	k++;
 	//循环从第一个邻接点开始，到最后一个结束 
 	for(p=G.vertices[v].firstarc;p;p=p->nextarc){
 		w=p->adjvex;
 		if(!visited[w])
 		//递归遍历 
 		DFS(G,w);
	 }
 }
 
 void DFSTravers(ALGraph G,int v){
 	
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
	 	DFS(G,v-1);
	 	//用于非联通图 
	 	for(int j=0;j<G.vexnum;j++){
	 		if(!visited[j]){
	 			v=j+1;
	 			allvexdata1[k]=-1;//用0来记录非联通图的断点 
 	k++;
	 			break;
			 }
		 }
	 }
 } 
 

 Status DFSPrint(){
 	cout<<"深度优先搜索结点访问序列如下:"<<endl;
 	int i=0;
 	//循环输出数组 
 	while(allvexdata1[i]){
 		if(allvexdata1[i]!=-1){
 			cout<<allvexdata1[i];
 	
		 } 
 			i++;
	 }
	 int j=0; 
	 cout<<endl<<"深度优先搜索生成树的边集如下:"<<endl;
	 while(allvexdata1[j+1]){
	 	if(allvexdata1[j]!=-1&&allvexdata1[j+1]!=-1)
 		cout<<allvexdata1[j]<<"---"<<allvexdata1[j+1]<<", ";
 		j++;
	 }
	 cout<<endl;
	 return OK;
 }
 
 Status BFSPrint(){
 	cout<<"广度优先搜索结点访问序列如下:"<<endl;
 	int i=0;
 		//循环输出数组 
 	while(allvexdata2[i]){
 		if(allvexdata2[i]!=-1)
 		cout<<allvexdata2[i];
 		i++;
	 }
	 int j=0;
	 cout<<endl<<"广度优先搜索生成树的边集如下:"<<endl;
	 while(allvexdata2[j+1]){
	 	if(allvexdata2[j]!=-1&&allvexdata2[j+1]!=-1)
 		cout<<allvexdata2[j]<<"---"<<allvexdata2[j+1]<<", ";
 		j++;
	 }
	 cout<<endl;
	 return OK;
	 
 }
 //广度优先搜索 
 void BFSTraverse(ALGraph G,LinkQueue &Q,int v){
 	ArcNode *p;
 	VNode e;

 	for(int i=0;i<G.vexnum;i++){
 		visited[i]=false;
	 }
	 for(int i=0;i<G.vexnum;i++){
	 	if(!visited[v-1]){
	 		//访问到的结点入栈 
	 		EnQueue(Q,G.vertices[v-1]);visited[v-1]=true; 
	 		//并把访问结点的数据存入数组 
			 allvexdata2[x]=G.vertices[v-1].data;
 				x++;
 			
	 		while(Q.front!=Q.rear){
	 			//结点出栈，并将结点信息赋值给e传出来 
	 			DeQueue(Q,e);
	 					 
	 		//cout<<"出栈元素"<<e.data;
	 		//遍历每个结点的相邻结点 
	 			for(p=e.firstarc;p;p=p->nextarc){
	 			
	 		if(!visited[p->adjvex]){
	 			
	 			EnQueue(Q,G.vertices[p->adjvex]);visited[p->adjvex]=true;
				 allvexdata2[x]=G.vertices[p->adjvex].data;
 				x++;	//cout<<"计数"<<endl;
 				
			 }
			 
		 }
			 }
	 		
		 }
		 //用于遍历非联通图 
		 for(int j=0;j<G.vexnum;j++){
	 		if(!visited[j]){
	 			v=j+1;
	 			 allvexdata2[x]=-1;//用0来记录非联通图的断点 
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
 	cout<<"请输入开始的结点位置v,注意1<=v<="<<G.vexnum<<endl;
 	cin>>v;
 	DFSTravers(G,v);
 	DFSPrint();
 	BFSTraverse(G,q,v);
 	BFSPrint();
 } 
