#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=1e5+9;
int lx[maxn*2],ly[maxn*2],dx[maxn*2],dy[maxn*2],dis,ky;
bitset<maxn*2> vis;
struct edge{int t,nex;} g[maxn*8];
int head[maxn*2],sz;
int q[maxn*4]={},l,r,n,a,b;;
template<typename T>
inline void read(T &X){
	X=0;int c=getchar(),w=0;
	while(!isdigit(c)) w|=c=='-',c=getchar();
	while(isdigit(c)) X=X*10+(c^'0'),c=getchar();
	if(w) X=-X;
}
void addedge(int f,int t){
	g[sz]={t,head[f]};
	head[f]=sz++;
}
int bfs(){
	mem(dx,-1),mem(dy,-1);
	dis=0x3f3f3f3f;
	l=0,r=0;
	rep(x,0,n) if(lx[x]==-1)
		q[r++]=x,dx[x]=0;
	while(l<r){
		int x=q[l++];
		if(dx[x]>dis) break;
		for(int i=head[x];~i;i=g[i].nex){
			int y=g[i].t;
			if(dy[y]!=-1) continue;
			dy[y]=dx[x]+1;
			if(ly[y]==-1) dis=dy[y];
			else dx[ly[y]]=dy[y]+1,q[r++]=ly[y];
		}
	}
	return dis!=0x3f3f3f3f;
}
int dfs(int x){
	for(int i=head[x];~i;i=g[i].nex){
		int y=g[i].t;
		if(vis[y]||dy[y]!=dx[x]+1) continue;
		vis[y]=1;
		if(ly[y]!=-1&&dy[y]>dis) break;
		if(ly[y]==-1||dfs(ly[y]))
			return ly[y]=x,lx[x]=y,1;
	}
	return 0;
}
int HK(){
	int ans=0;
	mem(lx,-1),mem(ly,-1);
	for(;bfs();){
		vis.reset();
		rep(x,0,n) if(lx[x]==-1&&dfs(x)) ans++;
	}
	return ans;
}
void solve(){
	__gnu_pbds::gp_hash_table<int,int> mp;   
	mem(head,-1),sz=0;
	ky=0;
	read(n);
	rep(i,0,n) {
		read(a),read(b);
		if(mp.find(a)==mp.end()) mp[a]=ky++;
		if(mp.find(b)==mp.end()) mp[b]=ky++;
		addedge(i,mp[a]);addedge(i,mp[b]);
	}
	printf("%d\n",HK());
}
int main(){
	int t;scanf("%d",&t);
	for(int i=1;i<=t;i++) printf("Case #%d: ",i),solve();
}