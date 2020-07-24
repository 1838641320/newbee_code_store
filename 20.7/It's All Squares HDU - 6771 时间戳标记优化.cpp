#include"s.h"
#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=409;
int a[maxn][maxn],vis[maxn*maxn],n,m,q,lim[maxn][maxn],tag;
char s[maxn*maxn];
void solve(){
	mem(vis,-1);mem(lim,-1);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
	for(;q--;){
		tag=q;
		int x,y;scanf("%d%d%s",&x,&y,s);
		int xl=x,xr=x,yl=y,yr=y;
		for(char *p=s;*p;p++){
			if(*p=='L') xl=min(xl,--x);
			if(*p=='R') xr=max(xr,++x);
			if(*p=='U') lim[x][y]=tag,yr=max(yr,++y);
			if(*p=='D') yl=min(yl,--y),lim[x][y]=tag;
		}
		int ans=0;
		for(int j=yl;j<yr;j++) for(int i=xl,in=0;i<xr;i++) {
			in^=lim[i][j]==tag;
			if(in==0) continue;
			if(vis[a[i][j]]!=tag) vis[a[i][j]]=tag,ans++;
		}
		printf("%d\n",ans);
	}
}
int main(){
	int t;scanf("%d",&t);
	for(;t--;) solve();
}