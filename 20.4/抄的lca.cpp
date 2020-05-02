#include"pch.h"
#include<bits/stdc++.h>
using namespace std;
const int maxn=500+9,log_maxn=10;
vector<int> G[maxn];
//
int root,par[log_maxn][maxn],depth[maxn];
void dfs(int v,int p) {
	par[0][v]=p;
	depth[v]=depth[p]+1;
	for (int i=0;(1<<i)<=depth[v];i++) par[i+1][v]=par[i][par[i][v]];
	for (int i:G[v]) if(i!=v) dfs(i,v); 
}
int lca(int a,int b) {
	dfs(root,-1);
	if (depth[a]>depth[b]) swap(a,b);
	for (int i=0;i<log_maxn;i++)
		if ((depth[b]-depth[a])&i) b=par[i][b];
	if (a==b) return a;
	for (int i=0;i<log_maxn;i++)
		if (par[i][a]!=par[i][b]) a=par[i][a],b=par[i][b];
	return par[0][a];
}
int main() {

}