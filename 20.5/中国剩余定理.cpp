#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll&x,ll&y) {
	if (!b) { x=1,y=0;return a; }
	ll d=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return d;
}
ll qpow(ll x,ll n,ll mod) {
	ll c=1;
	for (x%=mod;n;n/=2,x=(x*x)%mod) if (n&1) c=(c*x)%mod;
	return c;
}
inline ll modinv(ll x,ll mod) { return qpow(x,mod-2,mod); }
//prime only
ll crt(int n,ll *a,ll *m) {
	ll pro=1,res=0,y,t;
	rep(i,0,n) pro*=m[i];
	rep(i,0,n) {
		ll w=pro/m[i];
		ll d=modinv(w,m[i]);
		res=(res+w*d*a[i])%pro;
	}
	return res;
}
//universal
ll crt2(int n,ll *a,ll *m) {
	ll pro=1,res=0,y,t;
	rep(i,0,n) pro*=m[i];
	rep(i,0,n) {
		ll w=pro/m[i],d;
		exgcd(m[i],w,t,d);
		res=(res+w*d*a[i])%pro;
	}
	return (res+pro)%pro;
}
int main() {
	ll a[15],m[15],n;
	cin>>n;
	rep(i,0,n)
		scanf("%lld %lld",m+i,a+i);
	printf("%lld\n",crt(n,a,m));
}