#include"stdafx.h"
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
inline int read() {
	char c=getchar(); int x=0,f=1;
	while (c<'0'||c > '9') { if (c=='-') f=-1; c=getchar(); }
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
int N,M,dfn[MAXN],rev[MAXN],tot,block,bel[MAXN],siz[MAXN],col[MAXN],tims[MAXN],Ans[MAXN],out[MAXN];
vector<int> v[MAXN];
struct Query {
	int id,l,r,k;
	bool operator < (const Query &rhs) const {
		return bel[l]==bel[rhs.l]?r<rhs.r:bel[l]<bel[rhs.l];
	}
}Q[MAXN];
void dfs(int x,int fa) {
	dfn[x]=++tot; rev[tot]=x; siz[x]=1;
	for (int i=0,to; i<v[x].size(); i++) {
		if ((to=v[x][i])==fa) continue;
		dfs(to,x); siz[x]+=siz[to];
	}
}
void add(int x,int opt) {
	if (opt==1) Ans[++tims[x]]++;
	else Ans[tims[x]--]--;
}
void solve() {
	sort(Q+1,Q+M+1);
	int l=1,r=0;
	for (int i=1; i<=M; i++) {
		while (r>Q[i].r) add(col[rev[r--]],-1);
		while (r<Q[i].r) add(col[rev[++r]],1);
		while (l<Q[i].l) add(col[rev[l++]],-1);
		while (l>Q[i].l) add(col[rev[--l]],1);
		out[Q[i].id]=Ans[Q[i].k];
	}
	for (int i=1; i<=M; i++) printf("%d\n",out[i]);
}
int main() {
	N=read(); M=read(); block=sqrt(N);
	for (int i=1; i<=N; i++) col[i]=read(),bel[i]=(i-1)/block+1;
	for (int i=1; i<=N-1; i++) {
		int x=read(),y=read();
		v[x].push_back(y); v[y].push_back(x);
	}
	dfs(1,0);
	for (int i=1; i<=M; i++) {
		Q[i].id=i; int x=read(); Q[i].k=read();
		Q[i].l=dfn[x];
		Q[i].r=dfn[x]+siz[x]-1;
	}
	solve();
}