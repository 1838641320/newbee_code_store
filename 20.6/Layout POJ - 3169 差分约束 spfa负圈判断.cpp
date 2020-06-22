#include"s.h"
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef pair<int,int> pii;
const int maxn=1e3+9,maxm=1e4+9;
vector<pii> G[maxn]={};
int dis[maxn];
int n,md,ml,a,b,d;
int spfa(){
	memset(dis,0x3f,sizeof dis);dis[1]=0;
	bool inq[maxn]={};inq[1]=1;
	queue<int>q;q.push(1);
	int cnt[maxn]={};
	while(!q.empty()){
		int v=q.front();q.pop();
		inq[v]=0;
		rep(i,0,G[v].size()){
			int u=G[v][i].first,c=G[v][i].second;
			if(dis[u]>dis[v]+c){
				dis[u]=dis[v]+c;
				if(++cnt[u]>n) return -1;
				if(inq[u]==0) 
					q.push(u),inq[u]=1;
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&ml,&md);
	rep(i,0,ml){
		scanf("%d%d%d",&a,&b,&d);
		G[a].push_back(pii(b,d));
	}
	rep(i,0,md){
		scanf("%d%d%d",&a,&b,&d);
		G[b].push_back(pii(a,-d));
	}
	rep(i,2,n+1){
		G[i].push_back(pii(i-1,0));
	}
	int res=spfa();
	int ans=dis[n];
	if(res==-1) return puts("-1"),0;
	if(ans==0x3f3f3f3f) return puts("-2"),0;
	printf("%d\n",ans);
}