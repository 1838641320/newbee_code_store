#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#include<queue>
#include<unordered_map>
#include<bitset>
typedef long long ll;
vector<vector<int>> g;
vector<int> sz;
ll ans;
template<int len=1>
ll sub_set_sum(int n,const vector<int> &se){//倍增写出log(N)个不同的函数
	if(n>=len) return sub_set_sum<min(len*2,1<<20)>(n,se);
	bitset<len> dp;
	dp[0]=1;
	ll val=0;
	for(auto i:se) dp|=dp<<i;
	for(int i=0;i<n;i++)
		if(dp.test(i))
			val=max(val,ll(i)*ll(n-i-1));
	return val;
}
void dfs(int x){
	sz[x]=1;
	if(g[x].empty()) return;
	vector<int> tsz;
	for(auto u:g[x]){
		dfs(u);
		tsz.push_back(sz[u]);
		sz[x]+=sz[u];
	}
	if(auto masz=*max_element(tsz.begin(),tsz.end());masz*2>=sz[x]){
		ans+=ll(masz)*(sz[x]-1-masz);
		return;
	}
	{//optimize dp, when Σa_i==m, sqrt(m) different Objects.
		sort(tsz.begin(),tsz.end());
		tsz.push_back(-1);
		vector<int> tmp;
		for(int i=0,pi=0;i<(int)tsz.size();i++){
			if(tsz[i]!=tsz[i-1]){
				ll cnt=i-pi;
				for(int j=1;j<cnt;j*=2){
					tmp.push_back(j*tsz[i-1]);
					cnt-=j;
				}
				tmp.push_back(cnt*tsz[i-1]);
				pi=i;
			}
		}
		tsz=tmp;
	}
	ans+=sub_set_sum(sz[x],tsz);//O( sqrt(m)*m/w )
}
void solve(){
	int n;
	cin>>n;
	g.clear();
	g.resize(n+1);
	sz.resize(n+1);
	ans=0;
	for(int i=2;i<=n;i++){
		int p;
		cin>>p;
		g[p].push_back(i);
	}
	dfs(1);
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=1;
	// cin>>t;
	while(t--) solve();
}
