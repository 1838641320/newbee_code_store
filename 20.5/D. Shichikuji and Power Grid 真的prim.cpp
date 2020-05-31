#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
const int maxn=2e3+9;
ll g[maxn][maxn]={},dist[maxn]={},n,x[maxn]={},y[maxn]={},k[maxn]={},ans=0;
int link[maxn]={};
void prim(){
	while (1){
		int v=-1;
		rep(i,1,n+1)
			if (dist[i]&&(v==-1||dist[v]>dist[i])) v=i;
		if (v==-1) break;
		ans+=dist[v];
		dist[v]=0;
		rep(i,1,n+1)
			if (dist[i]>g[v][i])
				dist[i]=g[v][i],link[i]=v;
	}
}
int main(){
	cin>>n;
	rep(i,1,n+1) scanf("%lld %lld",x+i,y+i);
	rep(i,1,n+1) scanf("%lld",dist+i);
	rep(i,1,n+1) scanf("%lld",k+i);
	rep(i,1,n+1) rep(j,1,n+1)
		g[i][j]=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
	prim();
	printf("%lld\n",ans);
	vector<int> poo;
	rep(i,1,n+1) if (link[i]==0) poo.push_back(i);
	printf("%d\n",poo.size());
	for (int i:poo) printf("%d ",i);
	printf("\n%d\n",n-poo.size());
	rep(i,1,n+1) if (link[i]) printf("%d %d\n",i,link[i]);
}