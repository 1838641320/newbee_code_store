#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=409,inf=1e9;
int n,m,k;
int head[maxn],sz,deep[maxn];
struct edge{int t,nex,cap;}g[maxn*maxn];
void addedge(int f,int t,int cap){
	g[sz]={t,head[f],cap};
	head[f]=sz++;
	g[sz]={f,head[t],0};
	head[t]=sz++;
}
int Q[maxn];
int bfs(int s,int t){
	int l=0,r=0;Q[r++]=s;
	mem(deep,0);deep[s]=1;
	while(l<r)
		for(int u=Q[l++],i=head[u];~i;i=g[i].nex){
			int v=g[i].t;
			if(g[i].cap&&!deep[v]){
				deep[v]=deep[u]+1;
				if(v==t) return 1;
				Q[r++]=v;
			}
		}
	return 0;
}
int dfs(int s,int t,int cap,int flow=0){
	if(s==t) return cap;
	for(int i=head[s];~i;i=g[i].nex){
		edge &e=g[i];
		if(deep[s]+1==deep[e.t]&&e.cap){
			int di=dfs(e.t,t,min(e.cap,cap-flow));
			if(di) flow+=di,
				e.cap-=di,g[i^1].cap+=di;
			if(flow==cap) break;
		}
	}
	if(!flow) deep[s]=-99;
	return flow;
}
int dinic(int s,int t){
	int ans=0;
	for(;bfs(s,t);) ans+=dfs(s,t,inf);
	return ans;
}
int main(){
	mem(head,-1),sz=0;
	ios::sync_with_stdio(false);
	map<string,int> re;
	string a,b;
	int s=0,t=401,i;
	for(cin>>n,i=1;i<=n;i++){
		cin>>a;re[a]=i;
		addedge(i,t,1);
	}
	for(cin>>m,i=1;i<=m;i++){
		cin>>a>>b;
		if(!re[a]) re[a]=re.size();
		if(!re[b]) re[b]=re.size();
		addedge(s,re[a],1);
		addedge(re[a],re[b],1);
	}
	for(cin>>k,i=1;i<=k;i++){
		cin>>a>>b;
		if(!re[a]) re[a]=re.size();
		if(!re[b]) re[b]=re.size();
		addedge(re[a],re[b],inf);
	}
	printf("%d\n",m-dinic(s,t));
}