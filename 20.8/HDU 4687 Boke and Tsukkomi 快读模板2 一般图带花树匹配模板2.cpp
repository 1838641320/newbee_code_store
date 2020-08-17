#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
template<class T> void read(T&a){
	a=0;int f=0,c=getchar();
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^'0');
	if(f) a=-a;
}
template<class A,class...B> void read(A&x,B&...y){read(x),read(y...);}
const int maxn=49;
int n,m,par[maxn],pre[maxn],link[maxn];
char ty[maxn];
deque<int> q;
vector<int> g[maxn];
int findp(int x){return par[x]==x?x:par[x]=findp(par[x]);}
int Ti=0,times[maxn]={};
int lca(int x,int y){
	for(Ti++;times[x]!=Ti;x^=y^=x^=y)
		if(x) times[x]=Ti,x=findp(pre[link[x]]);
	return x;
}
void blossom(int x,int y,int p){
	for(;findp(x)!=p;x=pre[y]){
		pre[x]=y;
		y=link[x];
		par[x]=par[y]=p;
		if(ty[y]==1) ty[y]=2,q.push_back(y);
	}
}
bool match(int x){
	for(int i=0;i<=n;i++) par[i]=i;
	mem(ty,0);q.clear();
	ty[x]=2,q.push_back(x);
	while(q.size()){
		x=q.front(),q.pop_front();
		for(int u:g[x])
			if(ty[u]==0){
				ty[u]=1;pre[u]=x;
				if(!link[u]){
					for(;x;u=x){
						x=link[pre[u]];
						link[u]=pre[u];
						link[link[u]]=u;
					}
					return 1;
				} 
				else q.push_back(link[u]),ty[link[u]]=2;
			}
			else if(ty[u]==2&&findp(u)!=findp(x)){
				int p=lca(x,u);
				blossom(x,u,p),blossom(u,x,p);
			}
	}
	return 0;
}
int maxmatch(int n){
	int res=0;
	for(int j=1;j<=n;j++) res+=!link[j]&&match(j);
	return res;
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		mem(link,0),mem(pre,0);
		for(int i=0;i<=n;i++) g[i].clear();
		struct {int x,y;} E[maxn*4]={};
		for(int i=1,f,t;i<=m;i++){
			read(f,t);
			E[i]={f,t};
			g[f].push_back(t),g[t].push_back(f);
		}
		int Maxmatch=maxmatch(n);
		vector<int> ans;
		for(int i=1,f,t;i<=m;i++){
			f=E[i].x,t=E[i].y;
			mem(link,0),mem(pre,0);
			for(int j=0;j<=n;j++) g[j].clear();
			for(int j=1;j<=m;j++) 
				if(E[j].x!=f&&E[j].y!=f&&E[j].x!=t&&E[j].y!=t)
					g[E[j].x].push_back(E[j].y),
					g[E[j].y].push_back(E[j].x);
			int res=maxmatch(n);
			if(res<Maxmatch-1) ans.push_back(i); 
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf(" %d"+!i,ans[i]);
		puts("");
	}
}