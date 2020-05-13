#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll qpow(ll x,ll n) {
	x%=mod;
	if (n==1) return x;
	return (qpow(x*x,n/2)*(n&1?x:1));
}
int main() {
	ll x,n;
	while (cin>>x>>n) cout<<qpow(x,n)<<endl;
}