#include<vector>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef pair<int,int> pii;
const int maxn=100+9;
struct Edge {
	int x,y,v;
	bool operator < (const Edge &a) { return v<a.v; }
};
vector<Edge> G;
int n,m,par[maxn]={};
int findp(int x) { return par[x]==x?x:(par[x]=findp(par[x])); }
void unite(int a,int b) {
	a=findp(a),b=findp(b);
	par[a]=b;
}
int kruskal() {
	rep(i,0,n+5) par[i]=i;
	sort(G.begin(),G.end());
	int sum=0,edge=1,i,j;
	for (i=0;i<G.size();) {
		int choice=0;
		for (j=i;j<G.size()&&G[j].v==G[i].v;j++);
		rep(k,i,j)
			if (findp(G[k].x)!=findp(G[k].y)) choice++;
		rep(k,i,j) {
			int u=G[k].x,v=G[k].y;
			if (findp(u)!=findp(v)) {
				choice--;
				unite(u,v);
				sum+=G[k].v;
			}
		}
		i=j;if (choice) return -1;
	}
	return sum;
}
int main() {
	int t;cin>>t;
	while (t--) {
		G.clear();
		cin>>n>>m;
		rep(i,0,m) {
			Edge e;int a,b,v;
			scanf("%d %d %d",&a,&b,&v);
			e.x=a,e.y=b,e.v=v;
			G.push_back(e);
		}
		int ans=kruskal();
		if (ans==-1) puts("Not Unique!");
		else printf("%d\n",ans);
	}
}