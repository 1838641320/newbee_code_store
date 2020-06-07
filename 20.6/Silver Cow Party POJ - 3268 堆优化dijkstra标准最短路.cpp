#include"s.h"
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e3+9;
vector<pii> g1[maxn],g2[maxn];
int n,m,x,d1[maxn],d2[maxn];
void dijkstra(vector<pii> g[maxn],int d[maxn]){
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push(pii(0,x));
	d[x]=0;
	while(!q.empty()){
		pii t=q.top();q.pop();
		int v=t.second,w=t.first;
		if(w>d[v]) continue;
		for(int i=0;i<g[v].size();i++){
			int u=g[v][i].second,c=g[v][i].first;
			if(d[u]<d[v]+c) continue;
			d[u]=d[v]+c;
			q.push(pii(d[u],u));
		}
	}
}
int main(){
	mem(d1,0x3f);mem(d2,0x3f);
	scanf("%d%d%d",&n,&m,&x);
	for(int i=0;i<m;i++){
		int a,b,t;
		scanf("%d%d%d",&a,&b,&t);
		g1[a].push_back(pii(t,b));
		g2[b].push_back(pii(t,a));
	}
	dijkstra(g1,d1);dijkstra(g2,d2);
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,d1[i]+d2[i]);
	printf("%d\n",ans);
}