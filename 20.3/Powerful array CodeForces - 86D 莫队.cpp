#include"stdafx.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int maxn=2e5+9,maxx=1e6+9;
int n,t,block;
ll ans[maxn],cnt[maxx]={},a[maxn]={};
struct qu { int x,y,i; } q[maxn]={};
bool cmp(qu &a,qu &b) {
	int ab=a.x/block,bb=b.x/block;
	return ab^bb?ab<bb:(ab&1?a.y<b.y:a.y>b.y);
}
int main() {
	cin>>n>>t;
	block=ceil(sqrt(n));
	for (int i=1;i<=n;i++) scanf("%lld",a+i);
	for (int i=0;i<t;i++) scanf("%d %d",&q[i].x,&q[i].y),q[i].i=i;
	sort(q,q+t,cmp);
	ll sum=0;
	for (int i=0,s=1,e=0;i<t;i++) {
		int l=q[i].x,r=q[i].y;
		while (s>l) 
			sum+=(2ll*(cnt[a[--s]]++)+1ll)*a[s];
		while (s<l) 
			sum-=(2ll*(--cnt[a[s]])+1ll)*a[s++];
		while (e>r) 
			sum-=(2ll*(--cnt[a[e]])+1ll)*a[e--];
		while (e<r) 
			sum+=(2ll*(cnt[a[++e]]++)+1ll)*a[e];
		ans[q[i].i]=sum;
	}
	for (int i=0;i<t;i++) cout<<ans[i]<<'\n';
}