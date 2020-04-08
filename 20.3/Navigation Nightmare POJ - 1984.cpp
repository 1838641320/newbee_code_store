#include"stdafx.h"
#include<cstdio>
#include<cstring>
#include<cmath>
#define mem(a,b) memset(a,0,sizeof(a[0])*(b+5))
using namespace std;
const int maxn = 40000+9,maxk = 10000+9;
int par[maxn],X[maxn],Y[maxn],s,e,after,N,M,K,\
F1[maxn],F2[maxn],L[maxn];
char dir[maxn];
int findp(int x) {
	if (par[x]==x) return x;
	int tp = par[x];
	par[x] = findp(tp);
	X[x] += X[tp];
	Y[x] += Y[tp];
	return par[x];
}
void unite(int a,int b,int dx,int dy) {
	int pa = findp(a),pb = findp(b);
	if (pa==pb) return;
	X[pa] += dx+X[b]-X[a];
	Y[pa] += dy+Y[b]-Y[a];
	par[pa] = pb;
}
int main() {
	while (scanf("%d%d",&N,&M)==2) {
		mem(par,N),mem(X,N),mem(Y,N);
		mem(F1,M),mem(F2,M),mem(L,M),mem(dir,M);
		for (int i = 0;i<N+3;i++) par[i] = i;
		for (int i = 0;i<M;i++)
			scanf("%d %d %d %c",&F1[i],&F2[i],&L[i],&dir[i]);
		scanf("%d",&K);
		for (int i = 0,j = 0;i<K;i++) {
			scanf("%d%d%d",&s,&e,&after);
			while (j<after) {
				int xx = 0,yy = 0;
				if (dir[j]=='N') yy = L[j];
				if (dir[j]=='S') yy = -L[j];
				if (dir[j]=='E') xx = L[j];
				if (dir[j]=='W') xx = -L[j];
				unite(F1[j],F2[j],xx,yy);
				j++;
			}
			if (findp(s)!=findp(e)) puts("-1");
			else printf("%d\n",abs(X[s]-X[e])+abs(Y[s]-Y[e]));
		}
		puts("");
	}
}