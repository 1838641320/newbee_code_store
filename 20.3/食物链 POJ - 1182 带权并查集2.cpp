#include"stdafx.h"
#include <cstdio>
const int maxn = 50009;
struct disjoint_set {
	int p,w;
}ds[maxn] = {};
int ans,n,m,a,b,x;
int findp(int x) {
	if (ds[x].p==x) return x;
	int tp = ds[x].p;
	ds[x].p = findp(ds[x].p);
	ds[x].w += ds[tp].w;
	return ds[x].p;
}
void unite(int a,int b,int u) {
	int pa = findp(a),pb = findp(b);
	if (pa!=pb) {
		ds[pa].p = pb;
		ds[pa].w = ds[b].w-ds[a].w+u;
	}
	else if ((ds[a].w-ds[b].w-u)%3) ans++;
}
int main() {
	scanf("%d %d",&n,&m);
	ans = 0;
	for (int i = 0;i<=n+2;i++) ds[i].p = i,ds[i].w = 0;
	while (m--) {
		scanf("%d %d %d",&x,&a,&b);
		if (a>n||b>n) { ans++;continue; }
		unite(a,b,x-1);
	}
	printf("%d",ans);
}