#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
using namespace std;
typedef long long ll;
const int maxn=8e5+9;
int par[maxn]={};
int findp(int x){ return par[x]==x?x:(par[x]=findp(par[x])); }
list<int> g[maxn];
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,n) par[i]=i,g[i].clear();
	rep(i,0,m){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int q;scanf("%d",&q);
	while(q--){
		int o;scanf("%d",&o);
		int po=findp(o);
		if(po!=o) continue;
		list<int> l;
		for(int i:g[po]){
			int pi=findp(i);
			if(po==pi) continue;
			l.splice(l.end(),g[pi]);
			par[pi]=po;
		}
		l.swap(g[po]);
	}
	rep(i,0,n) printf("%d ",findp(i));
	puts("");
}
int main(){
	int t;scanf("%d",&t);
	while(t--) solve();
}