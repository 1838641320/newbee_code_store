#include"stdafx.h"
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 609;
struct disjoint_set { int p,w; }ds[maxn];
typedef struct { int a,b,c; }P;
int n,p,q;
int findp(int x) {
	if (ds[x].p==x) return x;
	int tp = ds[x].p;
	ds[x].p = findp(tp);
	ds[x].w += ds[tp].w;
	return ds[x].p;
}
void unite(int a,int b,int u) {
	int pa = findp(a),pb = findp(b);
	if (pa!=pb) {
		ds[pa].p = pb;
		ds[pa].w = ds[b].w+u-ds[a].w;
	}
}
int main() {
	for (;scanf("%d%d%d",&n,&p,&q),n|p|q;) {
		if (p==q) { puts("no");continue; }
		int num = p+q+1;
		for (int i = 0;i<maxn;i++) ds[i].p = i,ds[i].w = 0;
		while (n--) {
			char s[6] = {};
			int a,b;
			scanf("%d %d %s",&a,&b,s);
			unite(a,b,s[0]=='n');
		}
		for (int i = 0;i<num;i++) findp(i);
		vector<int> group[maxn][2] = {};
		for (int i = 1;i<num;i++)
			group[findp(i)][ds[i].w].push_back(i);
		vector<P> g;
		for (int i = 1;i<num;i++) {
			int s1 = group[i][0].size(),s2 = group[i][1].size();
			if (s1||s2) g.push_back({i,s1,s2});
		}

	}
}
