#include"stdafx.h"
#include <bits/stdc++.h>
const int maxn = 200009;
struct disjoint_set {
	int p,w;
}du[maxn] = {};
int ans,n,m,a,b,x;
int findp(int x) {
	if (du[x].p==x) return x;
	int tp = du[x].p;
	du[x].p = findp(du[x].p);
	du[x].w += du[tp].w;
	return du[x].p;
}
void unite(int a,int b,int u) {
	int pa = findp(a),pb = findp(b);
	if (pa!=pb) {
		du[pa].p = pb;
		du[pa].w = -du[a].w+u+du[b].w;
	}
	else if (du[b].w+u!=du[a].w) ans++;
}
int main() {
	while (~scanf("%d %d",&n,&m)) {
		ans = 0;
		for (int i = 0;i<=n+2;i++) du[i].p = i,du[i].w = 0;
		while (m--)
			scanf("%d %d %d",&a,&b,&x),unite(--a,b,x);
		printf("%d\n",ans);
	}
}