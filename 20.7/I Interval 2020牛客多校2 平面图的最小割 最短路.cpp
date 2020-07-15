#include"s.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int maxn=500+9,maxv=maxn*maxn;
int id[maxn][maxn],s,t,n,m;
ll dist[maxv];
vector<pii> g[maxv];
ll dijkstra(int s,int t){
	memset(dist,0x3f,sizeof dist);dist[s]=0;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0ll,s});
	while(!pq.empty()){
		ll u=pq.top().second,c=pq.top().first;pq.pop();
		if(dist[u]<c) continue;
		for(auto i:g[u]){
			ll v=i.second,co=i.first;
			if(dist[v]>dist[u]+co){
				dist[v]=dist[u]+co;
				pq.push({dist[v],v});
			}
		}
	}
	return dist[t];
}
void addedge(int f,int t,int cost){
	g[f].push_back({cost,t});
	g[t].push_back({cost,f});
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0,ids=0;i<n+3;i++) for(int j=0;j<n+3;j++)
		id[i][j]=ids++;
	s=id[0][0];
	t=id[n+1][n+1];
	for(int i=0;i<m;i++) {
		int l,r,c;
		char cm[8]={};
		scanf("%d%d%s%d",&l,&r,cm,&c);
		if(cm[0]=='L') addedge(id[l][r],id[l][r+1],c);
		else addedge(id[l][r],id[l-1][r],c);
	}
	for(int i=1;i<=n;i++)
		addedge(id[0][0],id[0][i],0),addedge(id[i][n+1],id[n+1][n+1],0);
	ll ans=dijkstra(s,t);
	printf("%lld\n",ans==0x3f3f3f3f3f3f3f3f?-1:ans);
}