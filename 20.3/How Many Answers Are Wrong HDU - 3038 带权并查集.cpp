#include"stdafx.h"
#include <bits/stdc++.h>
const int maxn = 200009;
int par[maxn] = {},ans,w[maxn],n,m,a,b,x;
int findp(int x) {
	if (par[x]==x) return x;
	int tp = par[x];
	par[x] = findp(par[x]);
	w[x] += w[tp];
	return par[x];
}
void unite(int a,int b,int u) {
	int pa = findp(a),pb = findp(b);
	if (pa!=pb) {
		par[pa] = pb;
		w[pa] = -w[a]+u+w[b];
	}
	else ans += w[b]+u!=w[a];
}
int main() {
	while (~scanf("%d %d",&n,&m)) {
		ans = 0;
		for (int i = 0;i<=n+2;i++) par[i] = i,w[i] = 0;
		while (m--)
			scanf("%d %d %d",&a,&b,&x),unite(--a,b,x);
		printf("%d\n",ans);
	}
}