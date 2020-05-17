#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
ll n,T;
ll solve() {
	scanf("%lld",&n);
	ll ans=0,qn=sqrt(n);
	rep(i,1,qn+1)
		ans+=n/i;
	return ans*2-qn*qn;
}
int main() {
	std::cin>>T;
	rep(i,1,T+1) printf("Case %d: %lld\n",i,solve());
}