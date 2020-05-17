#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=2e5+9,log_maxn=20;
vector<int> G[maxn];
int root,par[log_maxn][maxn],depth[maxn];
void dfs(int v,int p) {
	par[0][v]=p;
	depth[v]=depth[p]+1;
	for (int i=0;(1<<i)<=depth[v];i++) par[i+1][v]=par[i][par[i][v]];
	for (int i:G[v]) if (i!=p) dfs(i,v);
}
int lca(int a,int b) {
	if (depth[a]>depth[b]) swap(a,b);
	for (int i=0;i<log_maxn;i++)
		if ((depth[b]-depth[a])&(1>>i)) b=par[i][b];
	if (a==b) return a;
	for (int i=0;i<log_maxn;i++)
		if (par[i][a]!=par[i][b]) a=par[i][a],b=par[i][b];
	return par[0][a];
}
int main() {
	int n,m,u,v;
	cin>>n>>m;
	rep(i,1,n) {
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
	}
	root=1;
	dfs(root,-1);
	while (m--) {
		scanf("%d %d",&u,&v);
		int llca=lca(u,v);
		puts(depth[u]-depth[llca]>3&&depth[v]-depth[llca]>3?"YES":"NO");
	}
}