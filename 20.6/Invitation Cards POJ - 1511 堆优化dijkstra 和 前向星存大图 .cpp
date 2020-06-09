#include"s.h"
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
const int maxn=1e6+9;
typedef pair<int,int> pii;
struct edge{ 
	int t,w,nex;
	edge(){};
	edge(int t,int w,int nex):t(t),w(w),nex(nex){}
};
edge g1[maxn]={},g2[maxn]={};
int head1[maxn],head2[maxn],sz1,sz2;
int n,m;
ll dijkstra(edge g[maxn],int head[maxn]){
	int d[maxn];memset(d,0x3f,sizeof d);
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push(pii(0,1));d[1]=0;
	while(!q.empty()){
		int v=q.top().second,di=q.top().first;q.pop();
		if(d[v]<di) continue;
		for(int i=head[v];~i;i=g[i].nex){
			int u=g[i].t,w=g[i].w;
			if(d[u]<=d[v]+w) continue;
			d[u]=d[v]+w;
			q.push(pii(d[u],u));
		}
	}
	ll res=0;
	for(int i=2;i<=n;i++) res+=d[i];
	return res;
}
void solve(){
	scanf("%d%d",&n,&m);
	memset(head1,-1,4*n+24);memset(head2,-1,4*n+24);
	sz1=sz2=0;
	for(int i=0,u,v,w;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		g1[sz1++]=edge(v,w,head1[u]);
		head1[u]=sz1-1;
		g2[sz2++]=edge(u,w,head2[v]);
		head2[v]=sz2-1;
	}
	ll ans=dijkstra(g1,head1)+dijkstra(g2,head2);
	printf("%lld\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	while(t--) solve();
}