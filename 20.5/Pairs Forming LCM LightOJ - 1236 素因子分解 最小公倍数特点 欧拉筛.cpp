#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
typedef long long ll;
const int maxn=1e7+9;
int T;ll n;
vector<ll> prime;
bool pvis[maxn]={};
void eulershai() {
	const int n=maxn-5;
	rep(i,2,n) {
		if (pvis[i]==0) prime.push_back(i);
		for (ll j:prime) {
			if (i*j>n) break;
			pvis[i*j]=1;
			if (i%j==0) break;
		}
	}
}
map<ll,ll> get_factor(ll n) {
	map<ll,ll> res;
	for (ll i:prime) {
		if (i*i>n) break;
		if(n%i==0) 
			while (n%i==0) {
				n/=i;res[i]++;
			}
	}
	if (n>1) res[n]++;
	return res;
}
ll solve() {
	scanf("%lld",&n);
	ll ans=1;
	auto factors=get_factor(n);
	for (auto i:factors) ans*=i.second*2+1;
	return (ans+1)/2;
}
int main() {
	eulershai();
	cin>>T;
	rep(i,1,T+1) 
		printf("Case %lld: %lld\n",i,solve());
}