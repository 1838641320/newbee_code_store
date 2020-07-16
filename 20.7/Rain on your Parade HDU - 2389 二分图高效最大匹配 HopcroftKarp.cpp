#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=3009;
struct guest{ int x,y,s; } gue[maxn];
struct umbrella{ int x,y; }umb[maxn];
bitset<maxn> vis;
vector<int> g[maxn];
int n,m,linkx[maxn],linky[maxn],disx[maxn],disy[maxn],dis;
int bfs(){
	dis=0x3f3f3f3f;
	mem(disx,-1),mem(disy,-1);
	queue<int> q;
	rep(x,0,n) if(linkx[x]==-1) 
		q.push(x),disx[x]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		if(disx[x]>dis) break;
		for(int y:g[x]){
			if(disy[y]!=-1) continue;
			disy[y]=disx[x]+1;
			if(linky[y]==-1) dis=disy[y];
			else disx[linky[y]]=disy[y]+1,q.push(linky[y]);
		}
	}
	return dis!=0x3f3f3f3f;
}
int dfs(int x){
	for(int y:g[x]){
		if(vis[y]||disy[y]!=disx[x]+1) continue;
		vis[y]=1;
		if(linky[y]!=-1&&disy[y]>=dis) continue;
		if(linky[y]==-1||dfs(linky[y]))
			return linky[y]=x,linkx[x]=y,1;
	}
	return 0;
}
int HopcroftKarp(){
	int ans=0;
	mem(linkx,-1);mem(linky,-1);
	for(;bfs();){
		vis.reset();
		rep(i,0,n) 
			if(linkx[i]==-1&&dfs(i)) ans++;
	}
	return ans;
}
void solve(){
	double t;scanf("%lf",&t);
	scanf("%d",&m);
	rep(i,0,m) scanf("%d%d%d",&gue[i].x,&gue[i].y,&gue[i].s);
	scanf("%d",&n);
	rep(i,0,n) scanf("%d%d",&umb[i].x,&umb[i].y);
	rep(i,0,n) g[i].clear();
	rep(i,0,n) rep(j,0,m)
		if(hypot(umb[i].x-gue[j].x,umb[i].y-gue[j].y)<=t*gue[j].s)
			g[i].push_back(j);
	printf("%d\n\n",HopcroftKarp());
}
int main(){
	int t;scanf("%d",&t);
	for(int i=1;i<=t;i++) printf("Scenario #%d:\n",i),solve();
}