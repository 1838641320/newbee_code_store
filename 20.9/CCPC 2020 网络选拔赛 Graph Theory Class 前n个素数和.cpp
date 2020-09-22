#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
using ll=long long;
const int maxn=2e5+9;//sqrt(n)*2
ll s[maxn],v[maxn];
ll ppt(ll a,ll b,ll c,ll d) { return a>=c?(b/a-1):(d-a); }
ll preprimesum(ll n) {
    ll r=sqrt(n),ndr=n/r,nv=r+ndr-1;
    rep(i,0,r) v[i]=n/(i+1);
    rep(i,r,nv) v[i]=v[i-1]-1;
    rep(i,0,nv) s[i]=v[i]*(v[i]+1)/2-1;
    for(ll p=2; p<=r; p++) {
        if(s[nv-p]>s[nv-p+1]) {
        	ll sp=s[nv-p+1],p2=p*p;
			rep(i,0,nv) {
				if(v[i]<p2) break;
				s[i]-=p*(s[ppt(v[i]/p,n,ndr,nv)]-sp);
			}
		}
	}
	return s[0];
}
void solve(){
	ll n,k;scanf("%lld%lld",&n,&k);
	ll ans=(((__int128_t)n+4)*(n-1)/2)%k;
	ans+=preprimesum(n+1);
	ll ans1=(ans-2+k)%k;
	cout<<ans1<<endl;
}
int main() {
	int t;scanf("%lld",&t);
	while(t--) solve();
}
