#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a)
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=109,maxm=209,inf=0x3f3f3f3f;
int par[maxn],n,m,maxe[maxn][maxn];
int findp(int x){ return par[x]==x?x:(par[x]=findp(par[x])); }
struct edge{
	int f,t,c;
	bool operator < (edge &a){ return c<a.c; }
}E[maxm];
vector<int> G[maxn];
bool vis[maxm];
int kruskal(){
	mem(vis,0),mem(maxe,0);
	sort(E,E+m);
	rep(i,0,n+2) par[i]=i;
	rep(i,0,n+2) G[i].clear(),G[i].push_back(i);
	int ans=0,cnt=0;
	rep(i,0,m){
		if(cnt==n-1) break;
		int fx=findp(E[i].f),fy=findp(E[i].t);
		if(fx==fy) continue;
		cnt++;par[fx]=fy;
		ans+=E[i].c;
		vis[i]=1;
		for(int j:G[fx]) for(int k:G[fy])
			maxe[j][k]=maxe[k][j]=E[i].c;
		for(int j:G[fx])
			G[fy].push_back(j);
	}
	return cnt==n-1?ans:inf;
}
void solve(){
	scanf("%d%d",&n,&m);
	rep(i,0,m)
		scanf("%d%d%d",&E[i].f,&E[i].t,&E[i].c);
	int res=kruskal();
	if(res==inf) return (void)puts("No way");
	int ans=inf;
	rep(i,0,m)
		if(!vis[i])
			ans=min(ans,res+E[i].c-maxe[E[i].f][E[i].t]);
	if(ans==inf) return (void)puts("No second way");
	printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	for(int i=1;i<=t;i++) printf("Case #%d : ",i),solve();
}
