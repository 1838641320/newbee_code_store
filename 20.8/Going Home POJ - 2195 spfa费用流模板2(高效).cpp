#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define mem(a,b) memset(a,b,sizeof a)
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=209,inf=0x3f3f3f3f;
struct edge{int t,nex,cap,cost;} g[maxn*maxn];
int sz,head[maxn],dis[maxn],maxflow,mincost;
bool inq[maxn];
void addedge(int f,int t,int cap,int cost){
	g[sz]={t,head[f],cap,cost};
	head[f]=sz++;
	g[sz]={f,head[t],0,-cost};
	head[t]=sz++;
}
int spfa(int s,int t){
	mem(dis,0x3f);
	queue<int> q;mem(inq,0);
	dis[s]=0,inq[s]=1;q.push(s);
	while(q.size()){
		int u=q.front();q.pop();inq[u]=0;
		for(int i=head[u];~i;i=g[i].nex){
			int v=g[i].t;
			if(g[i].cap&&dis[v]>dis[u]+g[i].cost){
				dis[v]=dis[u]+g[i].cost;
				if(inq[v]==0) q.push(v),inq[v]=1;
			}
		}
	}
	return dis[t]!=inf;
}
int dfs(int s,int t,int cap,int flow=0){
	if(s==t) return cap;
	inq[s]=1;
	for(int i=head[s];~i;i=g[i].nex){
		edge &e=g[i];
		if(!inq[e.t]&&e.cap&&dis[e.t]==dis[s]+e.cost){
			int di=dfs(e.t,t,min(e.cap,cap-flow));
			if(di) mincost+=di*e.cost,
				e.cap-=di,g[i^1].cap+=di,flow+=di;
			if(flow==cap) break;
		}
	}
	return flow;
}
void MCMF(int s,int t){
	for(maxflow=mincost=0;spfa(s,t);)
		mem(inq,0),maxflow+=dfs(s,t,inf);
}
int main(){
	int n,m;
	char s[maxn];
	while(scanf("%d%d",&n,&m),n|m){
		int szm=0,szh=0;
		mem(head,-1),sz=0;
		struct{int x,y;} man[maxn],hou[maxn];
		rep(i,0,n) {
			scanf("%s",s);
			for(int j=0;j<m;j++) {
				if(s[j]=='m') man[szm++]={i,j};
				if(s[j]=='H') hou[szh++]={i,j};
			}
		}
		int s=201,t=202;
		rep(i,0,szm){
			addedge(s,i,1,0);
			addedge(100+i,t,1,0);
			rep(j,0,szm){
				int dx=abs(man[i].x-hou[j].x),dy=abs(man[i].y-hou[j].y);
				addedge(i,100+j,1,dx+dy);
			}
		}
		MCMF(s,t);
		printf("%d\n",mincost);
	}
}