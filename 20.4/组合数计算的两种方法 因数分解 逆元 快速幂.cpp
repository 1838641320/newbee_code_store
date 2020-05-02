#include"pch.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll C[1000][1000]={},fact[1000000]={};
map<int,int> mp;
void factorize(int n) {
	for (int i=2;i*i<=n;i++) {
		while (n%i==0) mp[i]++,n/=i;
	}
	if (n>1) mp[n]++;
}
void combinational(int n) {
	for (int i=0;i<n;i++)
		for (int j=0,ej=min(i+1,n);j<ej;j++) {
			if (j==0||j==i) C[i][j]=1;
			else C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
}
ll qpow(ll x,ll n) { ll c=1;for (x%=mod;n;n/=2,x=(x*x)%mod) if (n&1) c=(x*c)%mod; return c; }
inline ll mdiv(ll a,ll b) { return a*qpow(b,mod-2); }
void Fact(ll n) { fact[0]=1;for (ll i=1;i<n;i++) fact[i]=(fact[i-1]*i)%mod; }
ll C_(ll n,ll m) { return (fact[n]*qpow(fact[m]*fact[n-m],mod-2))%mod; }
int main() {
	ll a,b;
	combinational(1000);
	Fact(1000000);
	while (cin>>a>>b) {
		printf("%lld",C_(a,b));
		if (a<=1000&&b<=1000) printf(" %lld\n",C[a][b]);
		else puts("");
	}
}