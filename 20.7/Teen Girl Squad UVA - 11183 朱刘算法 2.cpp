#include"s.h"
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=1e3+9,maxm=4e4+9;
struct Edge{ int f,t,c; }G[maxm];
int zhuliue(int root,int n,int m){
	int f,t,cnt,vis[maxn],pre[maxn]={},id[maxn];
	int res=0,in[maxn];
	for(;;){
		mem(in,0x3f);
		rep(i,0,m){
			f=G[i].f,t=G[i].t;
			if(G[i].c<in[t]&&t!=f)
				pre[t]=f,
				in[t]=G[i].c;
		}
		cnt=0,in[root]=0;
		rep(i,0,n) if(in[i]==0x3f3f3f3f)
			return -1;
		mem(vis,-1),mem(id,-1);
		rep(i,0,n){
			res+=in[i];
			for(t=i;vis[t]!=i&&id[t]==-1&&t!=root;t=pre[t])
				vis[t]=i;
			if(t!=root&&id[t]==-1){
				for(f=pre[t];f!=t;f=pre[f])
					id[f]=cnt;
				id[t]=cnt++;
			}
		}
		if(!cnt) break;
		rep(i,0,n) if(id[i]==-1) id[i]=cnt++;
		rep(i,0,m){
			f=G[i].f,t=G[i].t;
			G[i].f=id[f];
			G[i].t=id[t];
			if(id[t]!=id[f]) G[i].c-=in[t];
		}
		n=cnt,root=id[root];
	}
	return res;
}
void solve(){
	int n,m,ans,f,t,c;
	scanf("%d%d",&n,&m);
	rep(i,0,m) 
		scanf("%d%d%d",&f,&t,&c),
		G[i]={f,t,c};
	ans=zhuliue(0,n,m);
	if(ans==-1) puts("Possums!");
	else printf("%d\n",ans);
}
int main(){
	int t;scanf("%d",&t);
	for(int i=1;i<=t;i++) printf("Case #%d: ",i),solve();
}