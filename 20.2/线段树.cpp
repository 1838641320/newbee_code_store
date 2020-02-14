#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
template<typename T>
struct SegmentTree {
	vector<T> tree;
	void init(ll _n) {
		ll n = 1;
		for (;n<_n;n <<= 1);
		tree.resize(2*n);
	}
	void update(ll n,T k) {
		n += (tree.size()>>1)-1;
		tree[n] = k;
		while (n>0) {
			n = (n-1)>>1;
			tree[n] = (tree[2*n+1]+tree[2*n+2])%mod;
		}
	}
	T query(ll a,ll b,ll n = 0,ll l = 0,ll r = 0) {
		if (!r) r = tree.size()>>1;
		if (b<=l||a>=r) return 0;
		if (a<=l&&b>=r) return tree[n];
		T chl = query(a,b,2*n+1,l,(r+l)>>1);
		T chr = query(a,b,2*n+2,(r+l)>>1,r);
		return (chl+chr)%mod;
	}
};
SegmentTree<ll> sum;
int main() {
	ll l,r,n,i;
	scanf("%lld",&n);
	sum.init(n);
	for (i = 0;i<n;i++) sum.update(i,i*i);
	while (~scanf("%lld%lld",&l,&r))
		printf("%lld\n",sum.query(l,r));
}