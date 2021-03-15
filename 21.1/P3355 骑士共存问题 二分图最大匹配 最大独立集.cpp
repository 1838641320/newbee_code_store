#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;~c&&!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class A,class ...B>void read(A&a,B&...b){read(a);read(b...);}
//---------------------------------------------------------------------
using namespace std;
#include<queue>
#include<bitset>
const int maxn=4e4+9,inf=0x3f3f3f3f;
vector<int> g[maxn];//index from 0
int lx[maxn],ly[maxn],dx[maxn],dy[maxn],dis;
int lsz,rsz;
int q[maxn*2]={};
int bfs(){
	mem(dx,-1),mem(dy,-1);
	int l=0,r=0;
	dis=inf;
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
	return dis!=inf;
}
bitset<maxn> vis;
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
		rep(x,0,lsz) if(lx[x]==-1&&dfs(x)) ans++;
	}
	return ans;
}
int n,m;
bool fob[209][209];
int dd[][2]={-2,-1,-2,1,-1,-2,-1,2,1,-2,1,2,2,-1,2,1};
void addedge(int x,int y){
	for(auto e:dd){
		int dx=x+e[0],dy=y+e[1];
		if(dx<0||dy<0||dx>=n||dy>=n||fob[dx][dy]) continue;
		g[(x*n+y)/2].push_back((dx*n+dy)/2);
	}
}
int main(){
	read(n,m);
	rep(i,0,m){
		int x,y;read(x,y);
		fob[x-1][y-1]=1;
	}
	for(int i=0;i<n;i++) for(int j=0;j<n;j++)
		if(!fob[i][j]&&(i+j)%2)
			addedge(i,j);
	lsz=n*n/2;
	printf("%d\n",n*n-m-HopcroftKarp());
}