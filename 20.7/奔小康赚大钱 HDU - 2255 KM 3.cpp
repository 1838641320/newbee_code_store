#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=409;
int g[maxn][maxn]={},n,expex[maxn],expey[maxn],linky[maxn];
void bfs(int k) {
	int slack[maxn],pre[maxn]={},x,y=0,nexy=0,d;
	char visy[maxn]={};
	mem(slack,0x3f);linky[y]=k;
	while(linky[y]) {
		x=linky[y],d=0x3f3f3f3f,visy[y]=1;
		rep(yi,1,n+1) {
			if(visy[yi]) continue;
			int gap=expex[x]+expey[yi]-g[x][yi];
			if(slack[yi]>gap)
				slack[yi]=gap,pre[yi]=y;
			if(d>slack[yi])
				d=slack[yi],nexy=yi;
		}
		rep(yi,0,n+1) {
			if(visy[yi]) expex[linky[yi]]-=d,expey[yi]+=d;
			else slack[yi]-=d;
		}
		y=nexy;
	}
	while(y) linky[y]=linky[pre[y]],y=pre[y];
}
int KM() {
	mem(linky,0),mem(expex,0),mem(expey,0);
	rep(x,1,n+1) bfs(x);
	int ans=0;
	rep(y,1,n+1) if(linky[y])
		ans+=g[linky[y]][y];
	return ans;
}
int main() {
	while(cin>>n) {
		rep(i,1,n+1) rep(j,1,n+1) scanf("%d",&g[i][j]);
		printf("%d\n",KM());
	}
}