#include"pch.h"
#include<bits/stdc++.h>
using namespace std;
const int maxn=1009;
class dinic {
public:
	struct edge { int to,cap,nex; };
	vector<edge> G;
	int head[maxn]={},iter[maxn]={},deep[maxn]={};
	void init() {
		memset(head,-1,sizeof(head));
		G.resize(maxn);
	}
	void addedge(int f,int t,int cap) {
		G.push_back({t,cap,head[f]});
		head[f]=G.size()-1;
		G.push_back({f,0,head[t]});
		head[t]=G.size()-1;
	}
	void bfs(int s) {
		memset(deep,0,sizeof(deep));deep[s]=1;
		queue<int> qu;qu.push(s);
		while (!qu.empty()) {
			int u=qu.front();qu.pop();
			for (int i=head[u];i!=-1;i=G[i].nex) {
				edge e=G[i];
				if (e.cap&&deep[e.to]==0) {
					deep[e.to]=deep[u]+1;
					qu.push(e.to);
				}
			}
		}
	}
	int dfs(int s,int t,int f) {
		if (s==t||f==0) return f;
		for (int &i=iter[s];i!=-1;i=G[i].nex) {
			edge e=G[i];
			if (e.cap&&deep[e.to]>deep[s]) {
				int d=dfs(e.to,t,min(f,e.cap));
				if (d<=0) continue;
				G[i].cap-=d;
				G[i^1].cap+=d;
				return d;
			}
		}
		return 0;
	}
	int maxflow(int s,int t) {
		int ans=0;
		for (;;) {
			bfs(s);
			if (deep[t]==0) return ans;
			memcpy(iter,head,sizeof(iter));
			for (int f;f=dfs(s,t,INT_MAX);) ans+=f;
		}
	}
};
dinic tu;
int n,m;
int main() {
	tu.init();
	cin>>n>>m;
	const int t=n+1,s=0;
	for (int i=1;i<=m;i++) tu.addedge(s,i,1);
	for (int i=m+1;i<=n;i++) tu.addedge(i,t,1);
	for (int u,v;~scanf("%d%d",&u,&v);) 
		tu.addedge(u,v,1);
	printf("%d",tu.maxflow(s,t));
}