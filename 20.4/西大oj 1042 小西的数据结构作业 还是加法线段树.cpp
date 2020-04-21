#include"pch.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class SegmentTree {
public:
	vector<ll> tr,lz;
	void init(int n) {
		tr.clear(),lz.clear();
		tr.resize(4*n+90);
		lz.resize(4*n+90);
	}
	void build(ll in,ll l,ll r) {
		if (l==r) { scanf("%lld",&tr[in]);return; }
		ll mid=(l+r)/2;
		build(in*2,l,mid);build(in*2+1,mid+1,r);
		tr[in]=tr[in*2]+tr[in*2+1];
	}
	void pushdown(ll in,ll l,ll r) {
		if (lz[in]==0) return;
		ll mid=(l+r)/2,la=lz[in];
		lz[in]=0;
		lz[in*2+1]+=la,lz[in*2]+=la;
		tr[in*2]+=la*(mid-l+1),tr[in*2+1]+=la*(r-mid);
	}
	void add(ll in,ll l,ll r,ll L,ll R,ll val) {
		if (L>r||R<l) return;
		if (L<=l&&R>=r) {
			tr[in]+=(r-l+1ll)*val;
			lz[in]+=val;
			return;
		}
		pushdown(in,l,r);
		ll mid=(l+r)/2;
		add(in*2,l,mid,L,R,val);add(in*2+1,mid+1,r,L,R,val);
		tr[in]=tr[in*2+1]+tr[in*2];
	}
	ll qurry(ll in,ll l,ll r,ll L,ll R) {
		if (L>r||R<l) return 0;
		if (L<=l&&R>=r) return tr[in];
		pushdown(in,l,r);
		ll mid=(l+r)/2;
		return qurry(in*2,l,mid,L,R)+qurry(in*2+1,mid+1ll,r,L,R);
	}
};
SegmentTree tree;
int n,m;
int main() {
	while (~scanf("%d%d",&n,&m)) {
		tree.init(n);
		tree.build(1,1,n);
		while (m--) {
			int l,r,o;
			ll v;
			scanf("%d%d%d",&o,&l,&r);
			if (o==1) printf("%lld\n",tree.qurry(1,1,n,l,r));
			else scanf("%lld",&v),tree.add(1,1,n,l,r,v);
		}
	}
}