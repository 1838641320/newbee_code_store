#include"s.h"
#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a);
using namespace std;
const int maxn=1e5+9,inf=0x3f3f3f3f;
int n,m,head[maxn],deep[maxn],iter[maxn],sz;
struct edge { int t,cap,nex; }g[maxn*2];
void addedge(int f,int t,int cap){
	g[sz]={t,cap,head[f]};
	head[f]=sz++;
	g[sz]={f,cap,head[t]};
	head[t]=sz++;
}
int bfs(int s,int t){
	queue<int> q;q.push(s);
	mem(deep,0);deep[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u]; ~i;i=g[i].nex){
			int v=g[i].t;
			if(g[i].cap&&deep[v]==0){
				deep[v]=deep[u]+1;
				if(v==t) return 1;
				q.push(v);
			}
		}
	}
	return 0;
}
int dfs(int s,int t,int f){
	if(s==t) return f;
	for(int &i=iter[s];~i;i=g[i].nex){
		edge &e=g[i];
		if(deep[s]+1==deep[e.t]&&e.cap){
			int di=dfs(e.t,t,min(e.cap,f));
			if(di==0) continue;
			e.cap-=di,g[i^1].cap+=di;
			return di;
		}
	}
	return 0;
}
int dinic(int s,int t){
	int ans=0,tmp;
	while(bfs(s,t)){
		memcpy(iter,head,4*n+16);
		while(tmp=dfs(s,t,inf)) ans+=tmp;
	}
	return ans;
}
void solve(){
	scanf("%d%d",&n,&m);
	int Max=-inf,Min=inf,s,t;
	mem(head,-1);sz=0;
	for(int i=0; i<n; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(Max<x) Max=x,t=i+1;
		if(Min>x) Min=x,s=i+1;
	}
	for(int i=0; i<m; i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
	printf("%d\n",dinic(s,t));
}
int main(){
	int t;scanf("%d",&t);
	while(t--) solve();
}