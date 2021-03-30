#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn=5e2+9;
struct {int nex,t,cap;}g[maxn*2];
int head[maxn],sz=0;
struct {int f,t,w;}g2[maxn];
int n,m;
bool vis[maxn];
void addedge(int f,int t,int cap){
	g[sz]={head[f],t,cap};
	head[f]=sz++;
	g[sz]={head[t],f,cap};
	head[t]=sz++;
}
int dfs(int f,int t,int cap){
	if(f==t) return cap;
	vis[f]=1;
	for(int i=head[f];~i;i=g[i].nex){
		int v=g[i].t;
		if(!vis[v]&&g[i].cap>0){
			int d=dfs(v,t,min(cap,g[i].cap));
			g[i].cap-=d;
			g[i^1].cap+=d;
			if(d) return d;
		}
	}
	return 0;
}
int get_res(int u,int v,int w){
	mem(head,-1),sz=0;
	rep(i,0,m) {
		if(g2[i].w>=w) break;
		addedge(g2[i].f,g2[i].t,1);
	}
	int res=0,d;
	while(1){
		mem(vis,0);
		if((d=dfs(u,v,9999))==0) break;
		res+=d;
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,0,m) scanf("%d%d%d",&g2[i].f,&g2[i].t,&g2[i].w);
	sort(g2,g2+m,[](auto&a,auto&b){return a.w<b.w;});
	int ans=0;
	rep(i,0,m) ans+=get_res(g2[i].f,g2[i].t,g2[i].w);
	printf("%d\n",ans);
}