#include<stdio.h>
#define mod 1000000007
typedef long long ll;
ll qpow(ll a,ll n){
	ll t=1;
	a=a%mod;
	while(n){
		if(n&1) t=t*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return t;
}
int main(){
	ll a,n;
	while(~scanf("%lld%lld",&a,&n)) printf("%lld\n",qpow(a,n));
}
