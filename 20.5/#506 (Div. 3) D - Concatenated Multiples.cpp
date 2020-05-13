//#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=2e5+9,logn=12;
ll n,k,pw[logn]={},ar[maxn]={},len[maxn]={},ans=0;
vector<ll> rems[logn];
int main() {
	cin>>n>>k;
	rep(i,0,n) scanf("%lld",ar+i);
	pw[0]=1;
	rep(i,1,11) pw[i]=pw[i-1]*10%k;
	rep(i,0,n) {
		ll j=ar[i];
		while (j) { j/=10;len[i]++; }
		rems[len[i]].push_back(ar[i]%k);
	}
	rep(i,0,11) sort(rems[i].begin(),rems[i].end());
	rep(i,0,n) {
		rep(j,1,11) {
			ll res=(ar[i]*pw[j])%k,sres=(k-res)%k;
			auto l=lower_bound(rems[j].begin(),rems[j].end(),sres);
			auto r=upper_bound(rems[j].begin(),rems[j].end(),sres);
			//printf("%d\n",r-l);
			ans+=(r-l);
			if (j==len[i]&&(res+ar[i])%k==0) ans--;
		}
	}
	cout<<ans;
}