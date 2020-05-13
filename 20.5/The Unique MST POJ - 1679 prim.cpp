#include<vector>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef pair<int,int> pii;
const int maxn=100+9;
int n,m,G[maxn][maxn]={},cnt[maxn];
int prim() {
	char vis[maxn]={};
	int sum=0,dist[maxn];
	memset(dist,0x40,sizeof dist);dist[1]=0;
	while (1) {
		int v=-1;
		rep(i,1,n+1) 
			if (vis[i]==0&&(v==-1||dist[i]<dist[v])) v=i;
		if (v==-1) break;
		vis[v]=1;
		sum+=dist[v];
		rep(i,1,n+1) {
			if (i==v) continue;
			if (dist[i]==G[v][i]) cnt[i]++;
			if (dist[i]>G[v][i]) dist[i]=G[v][i],cnt[i]=1;
		}
	}
	return sum;
}
int main() {
	int t;cin>>t;
	while (t--) {
		memset(G,0x3f,sizeof G);
		cin>>n>>m;
		rep(i,0,m) {
			int x,y,v;scanf("%d %d %d",&x,&y,&v);
			G[x][y]=G[y][x]=v;
		}
		int ans=prim();
		rep(i,1,n+1) if (cnt[i]>1) ans=-1;
		if (ans==-1) puts("Not Unique!");
		else printf("%d\n",ans);
	}
}