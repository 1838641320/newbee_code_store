#include"s.h"
#include<cstdio>
#include<iostream>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=1e3+9;
int g1[maxn][maxn],g2[maxn][maxn];
int n,m,x,d1[maxn],d2[maxn];
void dijkstra(int g[maxn][maxn],int d[maxn]){
	d[x]=0;bool vis[maxn]={};
	while(1){
		int v=-1;
		for(int i=1;i<=n;i++)
			if(!vis[i]&&(v==-1||d[v]>d[i])) v=i;
		if(v==-1) break;
		vis[v]=1;
		for(int i=1;i<=n;i++)
			d[i]=min(d[i],d[v]+g[v][i]);
	}
}
int main(){
	mem(g1,0x3f);mem(g2,0x3f);mem(d1,0x3f);mem(d2,0x3f);
	scanf("%d%d%d",&n,&m,&x);
	for(int i=0;i<m;i++){
		int a,b,t;
		scanf("%d%d%d",&a,&b,&t);
		g1[a][b]=t;
		g2[b][a]=t;
	}
	dijkstra(g1,d1);dijkstra(g2,d2);
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,d1[i]+d2[i]);
	printf("%d\n",ans);
}