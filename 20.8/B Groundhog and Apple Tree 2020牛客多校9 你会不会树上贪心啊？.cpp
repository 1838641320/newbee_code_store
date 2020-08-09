#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct pll {ll x,y;};
const int maxn=1e5+9;
int n,a[maxn];
vector<pll> g[maxn];
bool cmp(pll &a,pll &b){
	if(a.x>=0){
		if(b.x<0) return 1;
		return a.y>b.y;
	}
	else {
		if(b.x>=0) return 0;
		return a.x+b.y>b.x+a.y;
	}
}
pll dfs(int x,int p){
	vector<pll> sub;
	for(auto &i:g[x]) if(i.x!=p) {
		pll t=dfs(i.x,x);
		t.x-=i.y*2;
		t.y-=i.y;
		t.y=min(t.y,t.x);
		sub.push_back(t);
	}
	sort(sub.begin(),sub.end(),cmp);
	pll res={a[x],0};
	for(auto &i:sub){
		res.y=min(res.y,res.x+i.y);
		res.x+=i.x;
	}
	return res;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			ll f,t,w;scanf("%lld%lld%lld",&f,&t,&w);
			g[t].push_back({f,w});
			g[f].push_back({t,w});
		}
		printf("%lld\n",-dfs(1,1).y);
	}
}