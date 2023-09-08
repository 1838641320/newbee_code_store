#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#include<queue>
#include<unordered_map>
typedef long long ll;
namespace wlm{
struct bitset{
	typedef unsigned long long ull;
	vector<ull> ar;
	void resize(int x){ar.resize(x/64+1);}
	void reset(){ar.clear();}
	void set(int a,int v=1){ar[a>>6]|=ull(v)<<(a&63);}
	int test(int a){return ar[a>>6]>>(a&63)&1;}
	void operator|=(const bitset& rop){
		size_t n=min(rop.ar.size(),ar.size());
		for(size_t i=0;i<n;i++)
			ar[i]|=rop.ar[i];
	}
	void operator&=(const bitset& rop){
		size_t n=min(rop.ar.size(),ar.size());
		for(size_t i=0;i<n;i++)
			ar[i]&=rop.ar[i];
	}
	void operator^=(const bitset& rop){
		size_t n=min(rop.ar.size(),ar.size());
		for(size_t i=0;i<n;i++)
			ar[i]^=rop.ar[i];
	}
	bitset operator<<(size_t x){
		if(x==0||x>=ar.size()*64) return *this;
		auto br=ar;
		const size_t w=x/64;
		const size_t of=x%64;
		if (of==0)
			for (size_t i=ar.size()-1;i>= w;--i)
				br[i]=ar[i-w];
		else{
			const size_t sub=(64-of);
			for (size_t i=ar.size()-1;i>w;--i)
				br[i]=((ar[i-w]<<of) | (ar[i-w-1]>>sub));
			br[w]=ar[0]<<of;
		}
		std::fill(br.begin(), br.begin()+w,0);
		return {br};
	}
	bitset operator>>(size_t x){
		if(x==0||x>=ar.size()*64) return *this;
		auto br=ar;
		const size_t w=x/64;
		const size_t of=x%64;
		const size_t limit=ar.size()-w-1;
		if (of==0)
			for (size_t i=0;i<=limit;++i)
				br[i]=ar[i+w];
		else{
			const size_t sub=(64-of);
			for (size_t i=0;i<limit;++i)
				br[i]=((ar[i+w]>>of) | (ar[i+w+1]<<sub));
			br[limit]=ar[ar.size()-1]>>of;
		}
		std::fill(br.begin()+limit+1,br.end(),0);
		return {br};
	}
};
}
vector<vector<int>> g;
vector<int> sz;
ll ans;
void dfs(int x){
	sz[x]=1;
	if(g[x].empty()) return;
	vector<int> tsz;
	for(auto u:g[x]){
		dfs(u);
		tsz.push_back(sz[u]);
		sz[x]+=sz[u];
	}
	if(auto masz=*max_element(tsz.begin(),tsz.end());
		masz*2>=sz[x]){
		ans+=ll(masz)*(sz[x]-1-masz);
		return;
	}
	{//optimize dp, when Σa_i==m, sqrt(m) different Objects.
		unordered_map<int,int> mp;
		for(auto i:tsz) mp[i]++;
		for(int i=1;i<sz[x];i++){
			while(mp.count(i)&&mp[i]>=3)
				mp[i]-=2,mp[i*2]+=1;
		}
		tsz.clear();
		for(auto [k,v]:mp) 
			for(int i=0;i<v;i++) tsz.push_back(k);
	}
	wlm::bitset dp;//O( sqrt(m)*m/w )
	dp.resize(sz[x]);
	dp.set(0,1);
	ll val=0;
	for(auto i:tsz) dp|=dp<<i;
	for(int i=0;i<sz[x];i++)
		if(dp.test(i))
			val=max(val,ll(i)*ll(sz[x]-i-1));
	ans+=val;
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
