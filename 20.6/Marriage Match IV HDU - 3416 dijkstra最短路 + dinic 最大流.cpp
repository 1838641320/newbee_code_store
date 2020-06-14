#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=1e3+9,maxm=1e5+9;
typedef pair<int,int> pii;
struct Edge{
	int f,t,cap,nex;
}g[4*maxm],G[4*maxm];
int deep[maxn],iter[maxn],headw[maxn],szw;
int head[maxn],sz;
int n,m,s,t,dist[maxn];
void addedge(int f,int t){
	g[szw]={f,t,1,headw[f]};
	headw[f]=szw++;
	g[szw]={t,f,0,headw[t]};
	headw[t]=szw++;
}
void dijkstra(){
	mem(dist,0x3f);dist[s]=0;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push({0,s});
	while(!q.empty()){
		int v=q.top().second,wv=q.top().first;q.pop();
		if(dist[v]<wv) continue;
		for(int i=head[v];~i;i=G[i].nex){
			Edge &e=G[i];
			int u=e.t,w=e.cap;
			if(dist[u]>dist[v]+w){
				dist[u]=dist[v]+w;
				q.push({dist[u],u});
			}
		}
	}
}
int bfs(){
	mem(deep,-1);deep[s]=0;
	queue<int> q;q.push(s);
	while(!q.empty()){
		int v=q.front();q.pop();
		for(int i=headw[v];~i;i=g[i].nex){
			Edge &e=g[i];
			if(e.cap&&deep[e.t]<0){
				deep[e.t]=deep[v]+1;
				if(t==e.t) return 1;
				q.push(e.t);
			}
		}
	}
	return 0;
}
int dfs(int s){
	if(s==t) return 1;
	for(int &i=iter[s];~i;i=g[i].nex){
		Edge &e=g[i];
		if(e.cap&&deep[e.t]>deep[s]){
			if(dfs(e.t)==0) continue;
			e.cap=0;
			g[i^1].cap=1;
			return 1;
		}
	}
	return 0;
}
int max_flow(){
	int ans=0;
	for(;bfs();){
		memcpy(iter,headw,sizeof headw);
		for(int f;f=dfs(s);) ans+=f;
	}
	return ans;
}
int main(){
	int ___;scanf("%d",&___);
	while(___--) {
		mem(head,-1);sz=0;
		mem(headw,-1);szw=0;
		scanf("%d%d",&n,&m);
		rep(i,0,m){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(a==b) continue;
			G[sz]={a,b,c,head[a]};
			head[a]=sz++;
		}
		scanf("%d%d",&s,&t);
		dijkstra();
		for(int i=0;i<sz;i++){
			int v=G[i].t,u=G[i].f;
			if(dist[v]==dist[u]+G[i].cap)
				addedge(u,v);
		}
		printf("%d\n",max_flow());
	}
}