#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
int n,g[309][309];
int main(){
	while(~scanf("%d",&n)){
		rep(i,0,n) rep(j,0,n) scanf("%d",&g[i][j]);
		rep(i,0,n) g[i][i]=0x3f3f3f3f;
		rep(k,0,n) rep(i,0,n) rep(j,0,n)
			g[i][j]=std::min(g[i][j],g[i][k]+g[k][j]);
		printf("%d\n",std::min(g[0][n-1],g[0][0]+g[n-1][n-1]));
	}
}