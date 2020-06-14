#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=209;
int n,m,q,p,g[maxn][maxn];
void solve(){
	scanf("%d",&n);
	int b[maxn]={};
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=n;i++) scanf("%d",b+i);
	scanf("%d",&m);
	rep(i,0,m){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u][v]=pow(b[v]-b[u],3);
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(int i=1;i<=n;i++) if(g[i][i]<0) {
		for(int j=1;j<=n;j++) if(g[i][j]<9999999)
			g[1][j]=-1;
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d",&p);
		int ans=g[1][p];
		if(ans<3||ans>9999999) puts("?");
		else printf("%d\n",g[1][p]);
	}
}
int main(){
	int t;scanf("%d",&t);
	for(int i=1;i<=t;i++) 
		printf("Case %d:\n",i),solve();
}