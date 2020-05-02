#include"pch.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e4+7;
vector<int> g[mod],g2[mod],s;
int sccCnt,n,vis[mod],color[mod];
void dfs1(int u) {
	vis[u]=true;
	for (int v:g[u])
		if (!vis[v]) dfs1(v);
	s.push_back(u);
}
void dfs2(int u) {
	color[u]=sccCnt;
	for (int v:g2[u])
		if (!color[v]) dfs2(v);
}
void kosaraju() {
	sccCnt=0;
	for (int i=1; i<=n; ++i)
		if (!vis[i]) dfs1(i);
	for (int i=s.size()-1;i>=0;i--)
		if (!color[s[i]]) {
			++sccCnt;
			dfs2(s[i]);
		}
}
int main() {}