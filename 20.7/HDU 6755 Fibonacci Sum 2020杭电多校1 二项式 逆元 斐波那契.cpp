#include"s.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+9,d=276601605,a=691504013,b=308495997,aa=691504012;
const int maxk=1e5+9;
ll F[maxk],F_[maxk];
void add(ll &x,ll y){
	x+=y;
	if(x>mod) x-=mod;
}
ll qpow(ll x,ll n){
	ll c=1;
	for(x%=mod;n;n/=2,x=x*x%mod) if(n&1) c=c*x%mod;
	return c;
}
void solve(){
	ll n,c,k;scanf("%lld%lld%lld",&n,&c,&k);
	ll ans=0;
	ll q=qpow(a,c%(mod-1)*k),Dq=qpow(aa,c)*qpow(b,c)%mod;
	ll n1=(n+1)%mod,n2=(n+1)%(mod-1);
	ll Q=qpow(q,n2),DQ=qpow(Dq,n2);
	for(ll i=0;i<=k;i++){
		ll C=F[k]*F_[i]%mod*F_[k-i]%mod;
		if(i&1) C=mod-C;
		if(q==1)
			add(ans,C*n1%mod);
		else
			add(ans,C*(Q+mod-1)%mod*qpow(q-1,mod-2)%mod);
		q=q*Dq%mod;
		Q=Q*DQ%mod;
	}
	printf("%lld\n",ans*qpow(d,k)%mod);
}
int main(){
	ll y;
	F[0]=F_[0]=F[1]=F_[1]=1;
	for(int i=2;i<maxk;i++){
		F[i]=F[i-1]*i%mod;
		F_[i]=qpow(F[i],mod-2);
	}
	int t;scanf("%d",&t);
	while(t--) solve();
}