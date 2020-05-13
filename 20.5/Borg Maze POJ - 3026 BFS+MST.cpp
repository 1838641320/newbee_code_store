#include"p.h"
#include<vector>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef pair<int,int> pii;
const int maxn=50+9,dx[]={0,0,-1,1},dy[]={1,-1,0,0};
int x,y,dist[maxn*maxn][maxn*maxn];
char maze[maxn][maxn]={};
map<pii,int> mp;
int prim() {
	int ans=0,cost[maxn*maxn],n=mp.size();
	memset(cost,0x3f,sizeof cost);
	char used[maxn*maxn]={};
	cost[0]=0;
	while (1) {
		int v=-1;
		rep(i,0,n) if (used[i]==0&&(v==-1||cost[i]<cost[v])) v=i;
		if (v==-1) return ans;
		used[v]=1;ans+=cost[v];
		rep(i,0,n) cost[i]=min(cost[i],dist[v][i]);
	}
}
void bfs(pii P) {
	queue<pii> q;queue<int> d;char vis[maxn][maxn]={};
	d.push(0);q.push(P);vis[P.first][P.second]=1;
	int s=mp[P];
	while (q.empty()==0) {
		pii PP=q.front();int id=d.front(),ix=PP.first,iy=PP.second;
		q.pop();d.pop();
		if (maze[ix][iy]=='A'||maze[ix][iy]=='S') dist[s][mp[PP]]=id;
		rep(i,0,4) {
			int cx=ix+dx[i],cy=iy+dy[i];
			if (cx<0||cy<0||cx>=x||cy>=y||vis[cx][cy]||maze[cx][cy]=='#') continue;
			q.push(make_pair(cx,cy));d.push(id+1);vis[cx][cy]=1;
		}
	}
}
int main() {
	int t;cin>>t;
	while (t--) {
		mp.clear();
		cin>>x>>y;fgets(maze[0],9999,stdin);
		memset(maze,0,sizeof maze);
		rep(i,0,y) fgets(maze[i],9999,stdin);
		rep(i,0,y) rep(j,0,x) if (maze[i][j]=='S'||maze[i][j]=='A') 
			mp[make_pair(i,j)]=mp.size();
		for (map<pii,int>::iterator it=mp.begin();it!=mp.end();it++) 
			bfs(it->first);
		printf("%d\n",prim());
	}
}