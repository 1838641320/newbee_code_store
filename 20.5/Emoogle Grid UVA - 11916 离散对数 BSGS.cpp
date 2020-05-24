#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
const ll mod=1e8+7;
struct P { ll x,y; }blo[509];
ll qpow(ll x,ll n) {
	ll c=1;
	for (x%=mod;n;n/=2,x=(x*x)%mod) if (n&1) c=(c*x)%mod;
	return c;
}
void exgcd(ll a,ll b,ll &x,ll &y) {
	if (!b) { x=1,y=0;return; }
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
ll inv(ll x) {
	ll a,b;
	exgcd(x,mod,a,b);
	return (a+mod)%mod;
}
ll log_mod(ll base,ll in) {
	ll m=sqrt(mod+0.5),p=1;//m=10000
	map<ll,ll> fun;
	fun[1]=0;
	for (ll i=1;i<=m;i++) {
		p=p*base%mod;
		if (!fun.count(p)) fun[p]=i;
	}
	ll pm=inv(qpow(base,m));
	for (ll i=0;i<=m;i++) {
		if (fun.count(in))
			return i*m+fun[in];
		else in=in*pm%mod;
	}
}
bool cmp(P &a,P &b) { return a.y==b.y?a.x<b.x:a.y<b.y; }
ll solve() {
	int n,k,b;
	ll res=1,r,minm=1;
	scanf("%d %d %d %lld",&n,&k,&b,&r);
	memset(blo,0,sizeof blo);
	rep(i,0,b) {
		ll x,y;
		scanf("%lld %lld",&x,&y);
		blo[i]={x,y};
		minm=max(minm,x);
	}
	sort(blo,blo+b,cmp);
	ll k1=n;
	rep(i,0,b) {
		if (blo[i].x==1) k1--;
		if (blo[i].x!=minm) {
			if (blo[i].y!=blo[i+1].y) k1++;
			else if (blo[i].x+1!=blo[i+1].x) k1++;
		}
	}
	res=res*qpow(k,k1)%mod*qpow(k-1ll,n*minm-k1-b)%mod;
	if (res==r) return minm;
	k1=0;
	rep(i,0,b)
		if (blo[i].x==minm) k1++;
	res=res*qpow(k,k1)%mod*qpow(k-1ll,n-k1);
	if (res==r) return minm+1;
	r=r*inv(res)%mod;
	return minm+1ll+log_mod(qpow(k-1ll,n),r);
}
int main() {
	int t;cin>>t;
	rep(i,1,t+1) printf("Case %d: %lld\n",i,solve());
}