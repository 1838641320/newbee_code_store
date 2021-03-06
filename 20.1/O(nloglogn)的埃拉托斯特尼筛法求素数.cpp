﻿#include<cstdio>
#include<cmath>
#include<cstring>
#define wiki
#define maxn 20000086
using namespace std;
typedef long long ll;
#ifdef book
ll sieve(ll n) {
	static char isp[maxn];
	static ll prime[maxn] = { 0 };
	ll p = 0;
	for (ll i = 0; i <= n; i++) isp[i] = 1;
	isp[0] = isp[1] = 0;
	for (ll i = 2; i <= n; i++) {
		if (isp[i]) {
			prime[p++] = i;
			for (ll j = 2 * i; j <= n; j += i) isp[j] = 0;
		}
	}
	return p;
}
#endif
#ifdef self
ll sieve(ll n) {
	static char np[maxn] = { 0 };
	static ll prime[maxn] = { 0 };
	ll p = 0;
	np[0] = np[1] = 1;//for odd
	if (n > 1) np[2] = 0, prime[p++] = 2;
	for (ll i = 4; i <= n; i += 2) np[i] = 1;
	for (ll i = 3; i <= n; i++) {
		if (!np[i]) {
			prime[p++] = i;
			for (ll j = i * i; j <= n; j += 2 * i) np[j] = 1;
		}
	}
	return p;
}
#endif
#ifdef wiki
ll sieve(ll n) {
	static char composit[maxn] = { 0 };
	static ll prime[maxn] = { 0 };
	ll p = 0;
	composit[0] = composit[1] = 1;
	for (ll i = 2; i <= n; i++) {
		if (!composit[i]) {
			prime[p++] = i;
			for (ll j = i * i; j <= n; j += i) composit[j] = 1;
		}
	}
	return p;
}
#endif
int main() {
	ll in;
	while (~scanf("%lld", &in)) printf("%lld\n", sieve(in));
}
