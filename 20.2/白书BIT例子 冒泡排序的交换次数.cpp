#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 100000+10;
int n,a[maxn],bit[maxn];
int sum(int i) {
	int s = 0;
	while (i>0) {
		s += bit[i];
		i -= i&-i;
	}
	return s;
}
void add(int i,int x) {
	while (i<=n) {
		bit[i] += x;
		i += i&-i;
	}
}
void solve() {
	ll ans = 0;
	for (int j = 0; j<n; j++) {
		ans += j-sum(a[j]);
		add(a[j],1);
	}
	printf("%lld\n",ans);
}
int main() {
	scanf("%d",&n);
	for (int i = 0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	solve();
	return 0;
}