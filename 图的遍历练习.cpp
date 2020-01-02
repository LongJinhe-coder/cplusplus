#include<iostream>
#include<queue>
using namespace std;

#define max 30
 int visited[max];
typedef char ElemType;

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode,*ArcList;

typedef struct{
    ElemType  data;
    ArcList firstarc;
}VNode;

typedef struct{
    VNode vertices[max];
    int vexnum;
    int arcnum;
}Graph;

int Located(Graph G,ElemType e){
    for(int i=1;i<=G.vexnum;i++){
        if(e==G.vertices[i].data)
        return i;
    }
    // return NULL;
}

void CreatGraph(Graph &G){
    int i,j;
    ElemType a,b;
    cout<<"分别输入图的顶多数和边数"<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"输入"<<G.vexnum<<"个顶点的data"<<endl;
    for(int i=1;i<=G.vexnum;i++){
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=NULL;
    }
   
    for(int k=1;k<=G.arcnum;k++){
        cout<<"输入边"<<k<<"两个顶点的data"<<endl;
        cin>>a>>b;
        i=Located(G,a);
        j=Located(G,b);
        ArcList pi=new ArcNode;
        pi->adjvex=j;
        pi->nextarc=G.vertices[i].firstarc;
        G.vertices[i].firstarc=pi;
        ArcList pj=new ArcNode;
        pj->adjvex=i;
        pj->nextarc=G.vertices[j].firstarc;
        G.vertices[j].firstarc=pj;
    }
    }

void DFS(Graph G,int v){
    visited[v]=true;
    cout<<G.vertices[v].data<<" ";
    for(ArcList vi=G.vertices[v].firstarc;vi;vi=vi->nextarc){
        if(!visited[vi->adjvex])
        DFS(G,vi->adjvex);
    }
}

void DFSTravers(Graph G,int v){
    
    // char visited[G.vexnum+1];
    for(int i=1;i<=G.vexnum;i++){
        visited[i]=false;
    }

    for(int i=1;i<=G.vexnum;i++){
        if(!visited[v])
        DFS(G,v);
    }
}



void BFSTravers(Graph G,int v){
    queue<VNode> q;
    VNode p;
    char visited[G.vexnum+1];
    for(int i=1;i<=G.vexnum;i++){
        visited[i]=false;
    }

    for(int i=1;i<=G.vexnum;i++){
        if(!visited[v]){
            visited[v]=true;
            q.push(G.vertices[v]);
            while(!q.empty()){
                p=q.front();
                cout<<p.data<<" ";
                q.pop();
                for(ArcList vi=p.firstarc;vi;vi=vi->nextarc){
                if(!visited[vi->adjvex]){
                    visited[vi->adjvex]=true;
                    q.push(G.vertices[vi->adjvex]);
                }
                    
                }
            }
        }
    }
}

int main(){
    Graph g;
    CreatGraph(g);
    ElemType e;
    cout<<"输入起点的data"<<endl;
    cin>>e;
    int v=Located(g,e);
    cout<<"深度遍历"<<endl;
    DFSTravers(g,v);
    cout<<"广度遍历"<<endl;
    BFSTravers(g,v);
}