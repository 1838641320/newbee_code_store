#include<bits/stdc++.h>
// #include<cstdio>
// #include<cstring>
// #include<cstdlib>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
ll gcd(ll x,ll y){while(y^=x^=y^=x%=y);return x;}
using namespace std;
//-----------------
const int maxn=1e5+9;
using pii=pair<int,int>;
vector<pii> g[2][maxn]={};
pii E[maxn]={};
bool vis[maxn]={},visn[maxn];
void dfs(int x,int ty){
	visn[x]=1;
	for(auto i:g[ty][x]) if(!visn[i.first]){
		vis[i.second]=1;dfs(i.first,ty);
	}
}
void solve(){
	int n,m;scanf("%d%d",&n,&m);
	rep(i,0,m) {
		vis[i]=0,g[0][i].clear(),g[1][i].clear();
		scanf("%d%d",&E[i].first,&E[i].second);
	}
	rep(i,0,m){
		int f=E[i].first,t=E[i].second;
		g[0][f].push_back({t,i});
		g[1][t].push_back({f,i});
	}
	rep(i,0,n+1) visn[i]=0;dfs(1,0);
	rep(i,0,n+1) visn[i]=0;dfs(1,1);
	int cnt=0;
	rep(i,0,m) if(vis[i]) cnt++;
	cnt=2*n-cnt;
	rep(i,0,m) if(!vis[i]&&cnt) vis[i]=1,cnt--;
	rep(i,0,m) if(!vis[i]) printf("%d %d\n",E[i].first,E[i].second);
}
int main(){
	int t;scanf("%d",&t);
	while(t--) solve();
}