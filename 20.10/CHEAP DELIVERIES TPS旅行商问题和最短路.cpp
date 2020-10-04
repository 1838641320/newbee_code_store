#include<bits/stdc++.h>
// #include<cstdio>
// #include<cstring>
// #include<cstdlib>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
ll gcd(ll x,ll y){while(y^=x^=y^=x%=y);return x;}
using namespace std;
//-----------------
using pli=pair<ll,int>;
const int maxn=1e4+9,maxk=18;
const ll inf=0x3f3f3f3f3f3f3f3fll;
ll dp[1<<maxk][maxk],dis[maxn],g[maxk][maxk];
int f,t,n,m,k,w,st[maxk],ed[maxk];
vector<pli> G[maxn];
void dijkstra(int s){
	mem(dis,0x3f);dis[s]=0;
	priority_queue<pli> pq;pq.push({0,s});
	while(pq.size()){
		int v=pq.top().second;
		ll w=pq.top().first;
		pq.pop();
		if(-w>dis[v]) continue;
		for(auto i:G[v])
			if(dis[i.second]>dis[v]+i.first){
				dis[i.second]=dis[v]+i.first;
				pq.push({-dis[i.second],i.second});
			}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,0,m){
		scanf("%d%d%d",&f,&t,&w);
		G[f].push_back({w,t});
		G[t].push_back({w,f});
	}
	mem(g,0x3f);mem(dp,0x3f);
	rep(i,0,k) {
		scanf("%d%d",&f,&t);
		st[i]=f,ed[i]=t;
	}
	ll ans1=0,ans2=inf;
	rep(i,0,k){
		dijkstra(ed[i]);
		rep(j,0,k) g[i][j]=dis[st[j]];
		ans1+=g[i][i];
	}
	rep(i,0,k) dp[1<<i][i]=0;
	rep(i,0,1<<k) rep(u,0,k) 
		if(dp[i][u]!=inf){
			rep(v,0,k) if(~i&1<<v){
				dp[i|1<<v][v]=min(dp[i|1<<v][v],dp[i][u]+g[u][v]);
			}
		}
	rep(i,0,k) ans2=min(ans2,dp[(1<<k)-1][i]);
	if(ans2>=inf||ans1>=inf) puts("-1");
	else printf("%lld\n",ans1+ans2);
}