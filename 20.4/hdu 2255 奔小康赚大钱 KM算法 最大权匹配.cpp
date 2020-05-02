#include"pch.h"
#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a)
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=310;
int G[maxn][maxn],nx,ny,linker[maxn],lx[maxn],ly[maxn],slack[maxn];
char visx[maxn],visy[maxn];
bool dfs(int x) {
	visx[x]=1;
	rep(y,0,ny) {
		if (visy[y]) continue;
		int gap=lx[x]+ly[y]-G[x][y];
		if (gap==0) {
			visy[y]=1;
			if (linker[y]==-1||dfs(linker[y]))
				return linker[y]=x,1;
		}
		else slack[y]=min(gap,slack[y]);
	}
	return 0;
}
int KM() {
	mem(linker,-1);mem(ly,0);mem(lx,0);
	rep(x,0,nx) rep(y,0,ny) lx[x]=max(lx[x],G[x][y]);
	rep(x,0,nx) {
		mem(slack,0x3f);
		while (1) {
			mem(visx,0);mem(visy,0);
			if (dfs(x)) break;
			int d=INT_MAX;
			rep(y,0,ny) if (!visy[y]) d=min(d,slack[y]);
			rep(x,0,nx) if (visx[x]) lx[x]-=d;
			rep(y,0,ny) if (visy[y]) ly[y]+=d;
		}
	}
	int res=0;
	rep(y,0,ny) if (linker[y]!=-1)
		res+=G[linker[y]][y];
	return res;
}
int main() {
	int N;
	while (~scanf("%d",&N)) {
		ny=nx=N;
		rep(i,0,nx) rep(j,0,ny) scanf("%d",&G[i][j]);
		printf("%d\n",KM());
	}
}