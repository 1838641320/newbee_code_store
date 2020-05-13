#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int inf=0x3f3f3f3f,N=409;
int w[N][N],n;
int lx[N],ly[N],slack[N],pre[N],link[N];
char visy[N];
void bfs(int k) {
	int x,y=0,yy=0,delta;
	mem(pre,0);mem(slack,0x3f);mem(visy,0);
	link[y]=k;
	while (link[y]) {
		x=link[y],delta=inf,visy[y]=1;
		rep(i,1,n+1) {
			if (visy[i]) continue;
			int gap=lx[x]+ly[i]-w[x][i];
			if (slack[i]>gap) 
				slack[i]=gap,pre[i]=y;
			if (slack[i]<delta) 
				delta=slack[i],yy=i;
		}
		rep(i,0,n+1) {
			if (visy[i]) lx[link[i]]-=delta,ly[i]+=delta;
			else slack[i]-=delta;
		}
		y=yy;
	}
	while (y) link[y]=link[pre[y]],y=pre[y];
}
int KM() {
	mem(link,0);
	rep(i,1,n+1) bfs(i);
	int res=0;
	rep(i,1,n+1) if (link[i])
		res+=w[link[i]][i];
	return res;
}
int main() {
	while (cin>>n) {
		rep(i,1,n+1) rep(j,1,n+1) scanf("%d",&w[i][j]);
		printf("%d\n",KM());
	}
}