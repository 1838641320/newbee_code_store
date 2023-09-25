#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
#include<vector>
struct Round_square{
	int n,dfc,tp;
	vector<vector<int>> g,&G;
	vector<int> st,dfn,low;
	Round_square(vector<vector<int>> &in):G(in){//1 indexed
		n=G.size()-1;
		g.resize(n*2+1);
		st=dfn=low=vector<int>(n+1);
		tp=dfc=0;
	}
	void tarjan(int u){
		low[u]=dfn[u]=++dfc;
		st[tp++]=u;
		for(auto v:G[u]){
			if(!dfn[v]){
				tarjan(v);
				low[u]=min(low[u],low[v]);
				if(low[v]==dfn[u]){
					n++;
					for(int x=0;x!=v;tp--){
						x=st[tp-1];
						g[n].push_back(x);
						g[x].push_back(n);
					}
					g[n].push_back(u);
					g[u].push_back(n);
				}
			}
			else low[u]=min(low[u],dfn[v]);
		}
	}
	vector<vector<int>> build(){
		for(int i=1,tn=n;i<=tn;i++) 
			if(!dfn[i]) tarjan(i),tp--;
		g.resize(n+1);
		return g;
	}
};
vector<vector<int>> g;
vector<ll> siz;
int n,m;
ll ans;
void dfs1(int u,int p){
	siz[u]=0;
	if(u<=n) siz[u]=1;
	for(auto v:g[u])if(v!=p){
		dfs1(v,u);
		siz[u]+=siz[v];
	}
}
void dfs(int u,int p,int sz){
	ll val=g[u].size(),pre=0;
	if(u<=n) val=-1;
	for(auto v:g[u])if(v!=p){
		dfs(v,u,sz);
		if(u>n) ans+=val*pre*siz[v];
		else ans+=val*max(0ll,pre*siz[v]);
		pre+=siz[v];
	}
	pre=sz-siz[u];
	if(u>n) ans+=val*siz[u]*pre;
	else ans+=val*max(0ll,siz[u]*(pre+1)-1);
}
void solve(){
	cin>>n>>m;
	g.resize(n+1);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	Round_square rs(g);
	g=rs.build();
	siz.resize(g.size(),-1);
	ans=0;
	for(int i=1;i<=n;i++)if(siz[i]==-1){
		dfs1(i,i);
		dfs(i,i,siz[i]);
	}
	cout<<ans*2<<"\n";
}
int main() {
	ios::sync_with_stdio(0);
	int t=1;
	// cin>>t;
	while(t--)
		solve();
}
