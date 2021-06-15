#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
template<class A>void read(A&a){
	a=0;int c=getchar(),f=0;
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
typedef vector<ll> poly;
const ll mod=998244353,g=3;
const int maxn=1e5+9;
ll qpow(ll x,ll n){
	ll c=1;
	for(;n;n/=2,x=x*x%mod)if(n&1) c=c*x%mod;
	return c;
}
void ntt(poly&a,int ty){
	int n=a.size();
	for(int i=0,j=0;i<n;i++){
		if(i>j) swap(a[i],a[j]);
		for(int l=n/2;(j^=l)<l;l/=2);
	}
	for(int i=1;i*2<=n;i*=2){
		ll wi=qpow(g,(mod-1)/2/i);
		if(ty==-1) wi=qpow(wi,mod-2);
		for(int j=0;j<n;j+=2*i){
			ll w=1;
			for(int k=j;k<j+i;k++){
				ll u=a[k],v=w*a[k+i]%mod;
				a[k]=(u+v)%mod;
				a[k+i]=(u-v+mod)%mod;
				w=wi*w%mod;
			}
		}
	}
	if(ty==-1){
		ll t=qpow(n,mod-2);
		for(int i=0;i<n;i++) a[i]=a[i]*t%mod;
	}
}
int lg2(int x){return 1<<(int)ceil(log2(x));}
ll fact[maxn],ai[maxn];
ll pa[maxn*4],pb[maxn*4];
poly calc(int l,int r){
	if(l==r) return {1,ai[l]};
	int mid=(l+r)>>1;
	auto a=calc(l,mid),b=calc(mid+1,r);
	int t=lg2(r-l+2);
	a.resize(t),b.resize(t);
	ntt(a,1),ntt(b,1);
	rep(i,0,t) a[i]=a[i]*b[i]%mod;
	ntt(a,-1);
	return a;
}
void solve(){
	int n;read(n);
	for(int i=1;i<=n;i++) read(ai[i]);
	auto res=calc(1,n);
	ll ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans+fact[i]*fact[n-i]%mod*res[i])%mod;
	ans=(ans*qpow(fact[n],mod-2))%mod;
	printf("%lld\n",ans);
}
int main(){
	fact[0]=1;
	for(int i=1;i<maxn;i++) fact[i]=fact[i-1]*i%mod;
	int t;scanf("%d",&t);
	while(t--) solve();
}