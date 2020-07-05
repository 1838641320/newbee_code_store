#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=309;
int n,m,par[maxn]={},S1,S2,maxe[maxn][maxn];
vector<int> G[maxn];
struct edge{
	int f,t,c;
	bool operator < (const edge &a) const { return c<a.c; }
}E[maxn*maxn];
bool vis[maxn*maxn];
int findp(int x){ return par[x]==x?x:(par[x]=findp(par[x])); }
int kruskal(){
	memset(vis,0,sizeof vis);
	memset(maxe,0,sizeof maxe);
	int ans=0,cnt=0;
	sort(E,E+m);
	rep(i,0,n+2) par[i]=i;
	rep(i,0,n+2) G[i].clear(),G[i].push_back(i);
	rep(i,0,m){
		int fx=findp(E[i].f),fy=findp(E[i].t);
		if(fx==fy) continue;
		par[fx]=fy;
		ans+=E[i].c;
		vis[i]=1;
		for(int j:G[fx]) for(int k:G[fy])
			maxe[j][k]=maxe[k][j]=E[i].c;
		for(int j:G[fx]) G[fy].push_back(j);
	}
	return ans;
}
void solve(){
	scanf("%d%d",&n,&m);
	rep(i,0,m) scanf("%d%d%d",&E[i].f,&E[i].t,&E[i].c);
	S1=kruskal();
	S2=0x3f3f3f3f;
	rep(i,0,m)
		if(!vis[i]) 
			S2=min(S2,S1+E[i].c-maxe[E[i].t][E[i].f]);
	printf("%d %d\n",S1,S2);
}
int main(){
	int t;scanf("%d",&t);
	while(t--) solve();
}
