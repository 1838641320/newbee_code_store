#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=409;
int w[maxn][maxn]={},n,lx[maxn],ly[maxn],link[maxn];
void bfs(int k) {
	int slack[maxn],pre[maxn]={},x,y=0,yy=0,d;
	char visy[maxn]={};
	mem(slack,0x3f);link[y]=k;
	while (link[y]) {
		x=link[y],d=0x3f3f3f3f,visy[y]=1;
		rep(i,1,n+1) {
			if (visy[i]) continue;
			int gap=lx[x]+ly[i]-w[x][i];
			if (slack[i]>gap)
				slack[i]=gap,pre[i]=y;
			if (d>slack[i])
				d=slack[i],yy=i;
		}
		rep(i,0,n+1) {
			if (visy[i]) lx[link[i]]-=d,ly[i]+=d;
			else slack[i]-=d;
		}
		y=yy;
	}
	while (y) link[y]=link[pre[y]],y=pre[y];
}
int KM() {
	mem(link,0),mem(lx,0),mem(ly,0);
	rep(i,1,n+1) bfs(i);
	int ans=0;
	rep(i,1,n+1) if(link[i]) 
		ans+=w[link[i]][i];
	return ans;
}
int main() {
	while (cin>>n) {
		rep(i,1,n+1) rep(j,1,n+1) scanf("%d",&w[i][j]);
		printf("%d\n",KM());
	}
}