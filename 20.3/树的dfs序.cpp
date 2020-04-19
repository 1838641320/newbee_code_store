#include"stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll scan() {
	char c=getchar();ll a=0,f=1;
	while (c<'0'||c>'9') { if (c=='-') f=-1;c=getchar(); }
	while (c>='0'&&c<='9') a=a*10+c-'0',c=getchar();
	return a*f;
}
const int maxn=1e2+9;
int n;
vector<int> G[maxn]={},dfn(maxn),rev,sub_tree_size(maxn);
void dfs(int u,int f) {
	rev.push_back(u),dfn[u]=rev.size(),sub_tree_size[u]=1;
	for (int i:G[u]) {
		if (i==f) continue;
		dfs(i,u);sub_tree_size[u]+=sub_tree_size[i];
	}
}
int main() {
	cin>>n;
	for (int i=1; i<n; i++) {
		int u=scan(),v=scan();
		G[v].push_back(u),G[u].push_back(v);
	}
	dfs(1,1);
	for (int i=0;i<n;i++)
		printf("%d %d %d\n",dfn[i+1],rev[i],sub_tree_size[i+1]);
}