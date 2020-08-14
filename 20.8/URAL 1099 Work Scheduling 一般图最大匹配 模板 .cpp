#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a)
const int maxn=230;
int par[maxn],pre[maxn],link[maxn],n,ans;
std::deque<int> q;
std::vector<int> g[maxn]={};
char ty[maxn];
int findp(int x){return x==par[x]?x:par[x]=findp(par[x]);}
int Ti=0,times[maxn]={};
int lca(int x,int y){
	for(Ti++;times[x]!=Ti;x^=y^=x^=y) 
		if(x) times[x]=Ti,x=findp(pre[link[x]]);
	return x;
}
void blossom(int x,int y,int p){
	while(findp(x)!=p){
		pre[x]=y;
		y=link[x];
		par[x]=par[y]=p;
		if(ty[y]==1) ty[y]=2,q.push_back(y);
		x=pre[y];
	}
}
bool Match(int x){
	for(int i=0;i<=n;i++) ty[i]=0,par[i]=i;
	q.clear();
	ty[x]=2,q.push_back(x);
	while(q.size()){
		x=q.front(),q.pop_front();
		for(int u:g[x])
			if(ty[u]==0){
				ty[u]=1;
				pre[u]=x;
				if(link[u]) q.push_back(link[u]),ty[link[u]]=2;
				else {
					for(;x;u=x){
						x=link[pre[u]];
						link[u]=pre[u];
						link[link[u]]=u;
					}
					return 1;
				}
			}
			else if(ty[u]==2&&findp(u)!=findp(x)){
				int p=lca(x,u);
				blossom(x,u,p),blossom(u,x,p);
			}
	}
	return 0;
}
int main(){
	mem(link,0);mem(pre,0);
	ans=0;
	scanf("%d",&n);
	for(int f,t;~scanf("%d%d",&f,&t);){
		g[f].push_back(t);
		g[t].push_back(f);
	}
	for(int i=1;i<=n;i++) 
		if(!link[i]&&Match(i)) ans++;
	printf("%d\n",ans*2);
	for(int i=1;i<=n;i++) if(i<link[i]) 
		printf("%d %d\n",i,link[i]);
}