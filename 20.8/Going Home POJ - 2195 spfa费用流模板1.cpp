#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define mem(a,b) memset(a,b,sizeof a)
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=209;
struct {int t,nex,cap,cost;} g[maxn*maxn];
int sz,head[maxn],pre[maxn],maxflow,mincost;
void addedge(int f,int t,int cap,int cost){
	g[sz]={t,head[f],cap,cost};
	head[f]=sz++;
	g[sz]={f,head[t],0,-cost};
	head[t]=sz++;
}
int spfa(int s,int t){
	int dis[maxn];mem(dis,0x3f);
	bool inq[maxn]={};
	mem(pre,-1);
	queue<int> q;
	dis[s]=0,inq[s]=1;q.push(s);
	while(q.size()){
		int u=q.front();q.pop();inq[u]=0;
		for(int i=head[u];~i;i=g[i].nex){
			int v=g[i].t;
			if(g[i].cap&&dis[v]>dis[u]+g[i].cost){
				dis[v]=dis[u]+g[i].cost;
				pre[v]=i;
				if(inq[v]==0) q.push(v),inq[v]=1;
			}
		}
	}
	return pre[t]!=-1;
}
void MCMF(int s,int t){
	maxflow=mincost=0;
	while(spfa(s,t)){
		int f=0x3f3f3f3f;
		for(int i=pre[t];~i;i=pre[g[i^1].t])
			f=min(f,g[i].cap);
		maxflow+=f;
		for(int i=pre[t];~i;i=pre[g[i^1].t]){
			g[i].cap-=f;
			g[i^1].cap+=f;
			mincost+=f*g[i].cost;
		}
	}
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