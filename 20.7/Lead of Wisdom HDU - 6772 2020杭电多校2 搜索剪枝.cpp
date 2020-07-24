#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
using namespace std;
typedef long long ll;
const int maxn=59;
struct gear{ 
	ll a,b,c,d;
	bool operator < (const gear &A)const{
		return a+b+c+d>A.a+A.b+A.c+A.d;
	}
};
vector<gear> g[maxn];
gear maxv[maxn];
int n,k;
ll ans;
void dfs(ll ki,ll a,ll b,ll c,ll d){
	if((a+maxv[ki].a)*(b+maxv[ki].b)*(c+maxv[ki].c)*(d+maxv[ki].d)<ans) return;
	if(ki==k+1) return void(ans=max(ans,a*b*c*d));
	if(g[ki].size()==0) return dfs(ki+1,a,b,c,d);
	for(auto i:g[ki]){
		dfs(ki+1,a+i.a,b+i.b,c+i.c,d+i.d);
	}
}
void solve(){
	memset(maxv,0,sizeof maxv);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=0;i<n;i++) {
		ll t,a,b,c,d;
		scanf("%lld%lld%lld%lld%lld",&t,&a,&b,&c,&d);
		g[t].push_back({a,b,c,d});
	}
	for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
	for(int i=k;i;i--){
		ll a=0,b=0,c=0,d=0;
		for(auto j:g[i]){
			a=max(a,j.a);
			b=max(b,j.b);
			c=max(c,j.c);
			d=max(d,j.d);
		}
		maxv[i]={maxv[i+1].a+a,maxv[i+1].b+b,maxv[i+1].c+c,maxv[i+1].d+d};
	}
	ans=0;
	dfs(1,100,100,100,100);
	printf("%lld\n",ans);
}
int main() {
	int t;scanf("%d",&t);
	while(t--) solve();
}