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
	//int v;//开始访问的结点位置 
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

typedef struct CSNode{
	VertexType data;
	struct CSNode *lchild,*nextsibling;
}CSNode,*CSTree;
 
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
	p->data=e; p->next=NULL;//cout<<"入队列元素:"<<e.data;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
	
}

Status DeQueue(LinkQueue &Q,VNode &e){
	
	if(Q.front==Q.rear){
		
		return ERROR;
	}
	QueuePtr p=Q.front->next;
	e=p->data;	//cout<<"出队列元素"<<e.data;
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
 //深度优先搜索生成树 
 void DFS(ALGraph G,int v,CSTree &T){
 	ArcNode *p;
	int w;
	int first=true;
	CSTree q=NULL;	
 	visited[v]=true;
 	
 
 	//循环从第一个邻接点开始，到最后一个结束 
 	for(p=G.vertices[v].firstarc;p;p=p->nextarc){
 		w=p->adjvex;
 		if(!visited[w]){
 			//给新的结点分配内存 
 			CSTree m=new CSNode;
 			m->data=G.vertices[w].data;
 			m->lchild=NULL;
 			m->nextsibling=NULL;
 			//若是第一个相邻结点，则让它成为当前结点的左孩子 
 			if(first){
 				T->lchild=m;
 				first=false;
			 }else{
			 	//若不是第一个相邻结点，则他成为第一个相邻结点的兄弟结点 
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
// 	cout<<"请输入开始的结点位置v,注意1<=v<="<<G.vexnum<<endl;
// 	cin>>v;
 	if(v<1||v>G.vexnum){
 		cout<<"v的位置不合理";
		 exit(OVERFLOW); 
	 }
	 //将每一个结点访问数组设为false 
 	for(int i=0;i<G.vexnum;i++){
 		visited[i]=false;
	 }
	 
	 for(int i=0;i<G.vexnum;i++){
	 	if(!visited[v-1]){
	 		//为二叉树的顶点分配内存 
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
	
	 	//用于非联通图 
	 	for(int j=0;j<G.vexnum;j++){
	 		if(!visited[j]){
	 			v=j+1;
	 			break;
			 }
		 }
	 }
 } 
 


 //广度优先搜索生成树 
 void BFSTree(ALGraph G,LinkQueue &Q,CSTree &T,int v){
 	ArcNode *p;
 	VNode e;
// 	int v;
 	T=NULL;
 	CSTree q=NULL;
	CSTree t =NULL;
// 	cout<<"请输入开始的结点位置v,注意1<=v<="<<G.vexnum<<endl;
// 	cin>>v;
 	for(int i=0;i<G.vexnum;i++){
 		visited[i]=false;
	 }
	 for(int i=0;i<G.vexnum;i++){
	 	q=t;
	 	if(!visited[v-1]){
	 		//访问到的结点入队列 
	 		EnQueue(Q,G.vertices[v-1]);visited[v-1]=true; 
	 		//为二叉树的顶点分配内存 
	 		CSTree m=new CSNode;
 			m->data=G.vertices[v-1].data;
 			m->lchild=NULL;
 			m->nextsibling=NULL;
 			if(!T){
 				
 				T=m;
			 }else{
			 	q->nextsibling=m;
			 }
			 q=m; t=q;//标记 
			 
	 		while(Q.front!=Q.rear){
	 			//结点出队列，并将结点信息赋值给e传出来 
	 			DeQueue(Q,e);
	 					int first=true; 
	 		//cout<<"出队列元素"<<e.data;
	 		//遍历每个结点的相邻结点 
	 			for(p=e.firstarc;p;p=p->nextarc){
	 			
	 		if(!visited[p->adjvex]){
	 			//结点入队列 
	 			EnQueue(Q,G.vertices[p->adjvex]);visited[p->adjvex]=true;
	 			//分配内存 
					CSTree m=new CSNode;
 			m->data=G.vertices[p->adjvex].data;
 			m->lchild=NULL;
 			m->nextsibling=NULL;
 			//若是第一个相邻结点，则让它成为当前结点的左孩子 
 			if(first){
 				q->lchild=m;
 				first=false;
			 }else{
			 		//若不是第一个相邻结点，则他成为第一个相邻结点的兄弟结点 
			 	q->nextsibling=m;
			 }
			 q=m;
 				
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
 //前序遍历输出二叉树 
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
 	cout<<"请输入开始的结点位置v,注意1<=v<="<<G.vexnum<<endl;
 	cin>>v;
 	DFSTree(G,T1,v);
 
 	BFSTree(G,q,T2,v);
 	cout<<"深度优先生成树前序遍历如下:"<<endl;
 	PrintTree(T1);
 	cout<<endl<<"广度优先生成树前序遍历如下:"<<endl;
 		PrintTree(T2);
 } 
