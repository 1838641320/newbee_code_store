#include"pch.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll n,k,fact[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
ll qpow(ll x,ll n) { ll c=1;for (x%=mod;n;n/=2,x=(x*x)%mod) if (n&1) c=(c*x)%mod;return c; }
ll C(ll n,ll m) { return (fact[n]*qpow(fact[m]*fact[n-m],mod-2))%mod; }
ll co[12]={};
ll a(ll n,ll k) {
	if (co[k]) return co[k];
	ll res=(qpow(2,n)-qpow(n+1,k)+co[0]+mod)%mod;
	for (ll i=1;i<k;i++)
		res=(res+C(k,i)*a(n,i))%mod;
	co[k]=res;
	return co[k];
}
int main() {
	while (cin>>n>>k) {
		memset(co,0,sizeof(co));
		if (n==1) { puts("1");continue; }
		co[0]=qpow(2,n-1)-1;
		cout<<(qpow(n,k)+a(n-1,k))%mod<<'\n';
	}
}