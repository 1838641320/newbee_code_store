#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a)
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=1e5+9,inf=0x3f3f3f3f;
struct {int t,nex,cap;}g[maxn*2];
int sz,head[maxn];
void addedge(int f,int t,int cap){
	g[sz]={t,head[f],cap};
	head[f]=sz++;
	g[sz]={f,head[t],cap};
	head[t]=sz++;
}
int Q[maxn],dis[maxn],gap[maxn],S,T;
void bfs(int t){
	mem(dis,-1),mem(gap,0);
	dis[t]=0;gap[0]=1;
	int l=0,r=0;Q[r++]=t;
	while(l<r) 
		for(int u=Q[l++],i=head[u];~i;i=g[i].nex){
			int v=g[i].t;
			if(dis[v]==-1) Q[r++]=v,
				dis[v]=dis[u]+1,gap[dis[v]]++;
		}
}
int dfs(int u,int cap,int flow=0){
	if(u==T) return cap;
	for(int i=head[u];~i;i=g[i].nex){
		auto &e=g[i];
		if(e.cap&&dis[e.t]+1==dis[u]){
			int di=dfs(e.t,min(e.cap,cap-flow));
			if(di) flow+=di,
				e.cap-=di,g[i^1].cap+=di;
			if(cap==flow) return flow;
		}
	}
	if(--gap[dis[u]]==0) dis[S]=maxn-2;
	++gap[++dis[u]];
	return flow;
}
int isap(int s,int t){
	int res=0;
	S=s,T=t;
	for(bfs(t);dis[s]<maxn-2;) 
		res+=dfs(s,inf);
	return res;
}
int n,m;
void solve(){
	scanf("%d%d",&n,&m);
	int Max=-inf,Min=inf,s,t;
	mem(head,-1);sz=0;
	for(int i=0;i<n;i++){
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
	printf("%d\n",isap(s,t));
}
int main(){
	int t;scanf("%d",&t);
	while(t--) solve();
}
