#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int main(){
	ll n,k,ans;
	scanf("%lld%lld",&n,&k);
	ans=n%mod;
	for(ll l=2,r=l;l<=k;l=r+1){
		if(n/l) r=min(n/(n/l),k);
		else r=k;
		ans=(ans+(n/l*2+1)%mod*(r-l+1))%mod;
		if(n%r==0) ans=(ans+mod-1)%mod;
	}
	printf("%lld\n",ans%mod);
}