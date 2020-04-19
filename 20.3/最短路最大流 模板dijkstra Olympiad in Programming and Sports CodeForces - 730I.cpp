#include"stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll maxn=3e3+9,maxv=3e3+9;
struct Edge { int to,cap,cost,nex; };
vector<Edge> G;
int head[maxn],pre[maxn],h[maxn]={},maxflow=0,mincost=0;
void addedge(int f,int t,int cap,int cost) {
	G.push_back({t,cap,cost,head[f]});
	head[f]=G.size()-1;
	G.push_back({f,0,-cost,head[t]});
	head[t]=G.size()-1;
}
int dijkstra(int s,int t) {
	priority_queue<P,vector<P>,greater<P> > pq;
	static int dis[maxn];
	memset(dis,0x3f,sizeof(dis));
	memset(pre,0xff,sizeof(pre));
	dis[s]=0;pq.push({0,s});
	while (!pq.empty()) {
		P now=pq.top();pq.pop();
		if (dis[now.second]<now.first) continue;
		int u=now.second;
		for (int i=head[u];i!=-1;i=G[i].nex) {
			Edge e=G[i];int v=e.to;
			if (e.cap&&dis[v]>dis[u]+e.cost+h[u]-h[v]) {
				dis[v]=dis[u]+e.cost+h[u]-h[v];
				pre[v]=i;
				pq.push({dis[v],v});
			}
		}
	}
	for (int i=0;i<maxn;i++) h[i]+=dis[i];
	return pre[t]!=-1;
}
void MCMF(int s,int t) {
	while (dijkstra(s,t)) {
		int f=INT_MAX;
		for (int i=pre[t];i!=-1;i=pre[G[i^1].to])
			f=min(f,G[i].cap);
		maxflow+=f;
		for (int i=pre[t];i!=-1;i=pre[G[i^1].to]) {
			G[i].cap-=f;
			G[i^1].cap+=f;
			mincost+=f*G[i].cost;
		}
	}
}
int main() {
	memset(head,0xff,sizeof(head));
	int n,a,b;
	cin>>n>>a>>b;
	const int s=0,t=n+3,pr=n+1,sp=n+2;
	for (int i=1,c;i<=n;i++) {
		scanf("%d",&c);
		addedge(pr,i,1,-c);
	}
	for (int i=1,c;i<=n;i++) {
		scanf("%d",&c);
		addedge(sp,i,1,-c);
	}
	for (int i=0;i<=n;i++) addedge(i,t,1,0);
	addedge(s,pr,a,0);
	addedge(s,sp,b,0);
	MCMF(s,t);
	cout<<-mincost<<'\n';
	for (int i=head[pr];i!=-1;i=G[i].nex)
		if (G[i].cap==0) printf("%d ",G[i].to);
	puts("");
	for (int i=head[sp];i!=-1;i=G[i].nex)
		if (G[i].cap==0) printf("%d ",G[i].to);
}