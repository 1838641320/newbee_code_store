#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll maxn=400;
struct Edge { int to,cap,cost,nex; };
vector<Edge> G;
int head[maxn],pre[maxn],maxflow=0,mincost=0;
void addedge(int f,int t,int cap,int cost) {
	G.push_back({t,cap,cost,head[f]});
	head[f]=G.size()-1;
	G.push_back({f,0,-cost,head[t]});
	head[t]=G.size()-1;
}
int spfa(int s,int t) {
	queue<int> q;
	static int dis[maxn];
	static bool used[maxn]={};
	memset(dis,0x3f,sizeof(dis));
	memset(pre,0xff,sizeof(pre));
	dis[s]=0;used[s]=1;q.push(s);
	while (!q.empty()) {
		int u=q.front();q.pop();used[u]=0;
		for (int i=head[u];i!=-1;i=G[i].nex) {
			int v=G[i].to;
			if (G[i].cap&&dis[v]>dis[u]+G[i].cost) {
				dis[v]=dis[u]+G[i].cost;
				pre[v]=i;
				if (used[v]==0) q.push(v),used[v]=1;
			}
		}
	}
	return pre[t]!=-1;
}
void MCMF(int s,int t) {
	while (spfa(s,t)) {
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
int times,n;
int main() {
	cin>>times;
	while (times--) {
		memset(head,-1,sizeof(head));
		maxflow=0,mincost=0;
		cin>>n;
		int s=0,t=2*n+1;
		for (int i=1;i<=n;i++) {
			for (int j=1,a;j<=n;j++) {
				scanf("%d",&a);
				addedge(i,j+n,1,-a);
			}
		}
		for (int i=1;i<=n;i++) {
			addedge(s,i,1,0);
			addedge(i+n,t,1,0);
		}
		MCMF(s,t);
		cout<<-mincost<<'\n';
	}
}