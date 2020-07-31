#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=1e5+9;
vector<int> g[maxn];
int n,lx[maxn],ly[maxn],dx[maxn],dy[maxn],dis;
int x,y,lsz,rsz;
bitset<maxn> vis;
int bfs(){
	mem(dx,-1),mem(dy,-1);
	int q[maxn*2]={},l=0,r=0;
	dis=0x3f3f3f3f;
	rep(x,0,lsz) if(lx[x]==-1)
		q[r++]=x,dx[x]=0;
	while(l<r){
		int x=q[l++];
		if(dx[x]>dis) break;
		for(int y:g[x]){
			if(dy[y]!=-1) continue;
			dy[y]=dx[x]+1;
			if(ly[y]==-1) dis=dy[y];
			else dx[ly[y]]=dy[y]+1,q[r++]=ly[y];
		}
	}
	return dis!=0x3f3f3f3f;
}
int dfs(int x){
	for(int y:g[x]){
		if(vis[y]||dy[y]!=dx[x]+1) continue;
		vis[y]=1;
		if(ly[y]!=-1&&dy[y]>dis) break;
		if(ly[y]==-1||dfs(ly[y]))
			return ly[y]=x,lx[x]=y,1;
	}
	return 0;
}
int HopcroftKarp(){
	int ans=0;
	mem(lx,-1),mem(ly,-1);
	for(;bfs();){
		vis.reset();
		rep(x,0,lsz) 
			if(lx[x]==-1&&dfs(x)) ans++;
	}
	return ans;
}
void solve(){
	__gnu_pbds::gp_hash_table<int,int> ll,rr;
	scanf("%d",&n);
	lsz=0,rsz=0;
	rep(i,0,n){
		scanf("%d%d",&x,&y);
		if(ll.find(x+y)==ll.end()) ll[x+y]=lsz++;
		if(rr.find(x-y)==rr.end()) rr[x-y]=rsz++;
		g[ll[x+y]].push_back(rr[x-y]);
	}
	printf("%d\n",HopcroftKarp());
	rep(x,0,lsz) g[x].clear();
}
int main(){
	int t;scanf("%d",&t);
	while(t--) solve();
}