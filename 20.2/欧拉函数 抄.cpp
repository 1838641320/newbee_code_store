#include<cstdio>
typedef long long ll;
const int maxn = 666666;
ll euler_phi(ll n) {
	ll res = n;
	for (ll i = 2;i * i <= n;i++) {
		if (n % i == 0) {
			res = res / i * (i - 1);
			for (;n % i == 0;n /= i);
		}
	}
	if (n != 1) res = res / n * (n - 1);
	return res;
}
ll euler[maxn] = {0};
void euler_phi2(ll n) {
	for (ll i = 0;i < n;i++) euler[i] = i;
	for (ll i = 2;i < n;i++) if (euler[i] == i) for (ll j = i;j < n;j += i)
		euler[j] = euler[j] / i * (i - 1);
}
int main() {
	ll n;
	scanf("%lld",&n);
	printf("%lld",euler_phi(n));
}