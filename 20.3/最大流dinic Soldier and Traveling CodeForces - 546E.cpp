#include"stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll maxn=3e2+9;
struct Edge { int to,cap,flow,nex; };
vector<Edge> G;
int head[maxn],deep[maxn],iter[maxn]={},maxflow=0;
void addedge(int f,int t,int cap) {
	G.push_back({t,cap,0,head[f]});
	head[f]=G.size()-1;
	G.push_back({f,cap,cap,head[t]});
	head[t]=G.size()-1;
}
void bfs(int s) {
	memset(deep,-1,sizeof(deep));deep[s]=0;
	queue<int> qu;qu.push(s);
	while (!qu.empty()) {
		int v=qu.front();qu.pop();
		for (int i=head[v];i!=-1;i=G[i].nex) {
			Edge &e=G[i];
			if (e.cap>e.flow&&deep[e.to]<0) {
				deep[e.to]=deep[v]+1;
				qu.push(e.to);
			}
		}
	}
}
int dfs(int v,int t,int f) {
	if (v==t||f==0) return f;
	for (int &i=iter[v];i!=-1;i=G[i].nex) {
		Edge &e=G[i];
		if (e.cap>e.flow&&deep[v]<deep[e.to]) {
			int d=dfs(e.to,t,min(f,e.cap-e.flow));
			if (d<=0) continue;
			e.flow+=d;
			G[i^1].flow-=d;
			return d;
		}
	}
	return 0;
}
void max_flow(int s,int t) {
	for (;;) {
		bfs(s);
		if (deep[t]<0) return;
		memcpy(iter,head,sizeof(head));
		for (int f;f=dfs(s,t,INT_MAX);) maxflow+=f;
	}
}
int n,m,suma,sumb,ans[maxn][maxn]={},a[maxn]={},b[maxn]={};
int main() {
	memset(head,-1,sizeof(head));
	cin>>n>>m;
	const int s=0,t=2*n+1;
	for (int i=1;i<=n;i++) scanf("%d",a+i),suma+=a[i];
	for (int i=1;i<=n;i++) scanf("%d",b+i),sumb+=b[i];
	for (int i=1;i<=n;i++)
		addedge(s,i,a[i]),addedge(i,i+n,b[i]),addedge(i+n,t,b[i]);
	for (int i=1,u,v;i<=m;i++) {
		scanf("%d%d",&u,&v);
		addedge(u,v+n,b[v]),addedge(v,u+n,b[u]);
	}
	if (suma!=sumb) { puts("NO");return 0; }
	max_flow(s,t);
	if (maxflow!=suma) { puts("NO");return 0; }
	puts("YES");
	for (int i=1;i<=n;puts(""),i++) {
		for (int j=head[i];j!=-1;j=G[j].nex) {
			ans[i][G[j].to-n]=G[j].flow;
		}
		for (int j=1;j<=n;j++) printf("%d ",ans[i][j]);
	}
}