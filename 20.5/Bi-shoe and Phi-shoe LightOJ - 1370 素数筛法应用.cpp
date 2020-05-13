#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
typedef long long ll;
const int maxn=1e6+9;
ll T,p[maxn]={},mp[maxn],in,n;
void shai(ll n) {
	p[0]=p[1]=1;
	rep(i,2,n) if (p[i]==0) 
		for (ll j=i*i;j<n;j+=i) p[j]=1;
	ll t=2,last=0;
	rep(i,2,n) 
		if (p[i]==0) {
			rep(j,last,i) mp[j]=i;
			last=i;
		}
}
int main() {
	shai(maxn-5);
	cin>>T;
	for (ll TT=1;TT<=T;TT++) {
		cin>>n;ll ans=0;
		rep(i,0,n) {
			scanf("%lld",&in);
			ans+=mp[in];
		}
		printf("Case %lld: %lld Xukha\n",TT,ans);
	}
}