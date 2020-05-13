#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
const int maxn=1e6+9;
bool pvis[maxn]={};
vector<int> prime;
void euler_shai(int n) {
	rep(i,2,n) {
		if (pvis[i]==0) prime.push_back(i);
		for (int j=0;j<prime.size()&&i*prime[j]<=n;j++) {
			pvis[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
}
ll get_factor(ll a) {
	ll tans=1;
	for (ll i:prime) {
		if (i*i>a) break;
		if (a%i) continue;
		ll cnt=1;
		while (a%i==0) cnt++,a/=i;
		tans*=cnt;
	}
	if (a>1ll) tans*=2;
	return tans;
}
int solve() {
	ll a,b,ans;scanf("%lld %lld",&a,&b);
	if (b*b>a||b>100000000) return 0;
	ans=get_factor(a)/2;
	rep(i,1,b) if (a%i==0) ans--;
	return ans;
}
int main() {
	euler_shai(maxn-5);
	int kase=0;cin>>kase;
	rep(i,1,kase+1) printf("Case %d: %d\n",i,solve());
}