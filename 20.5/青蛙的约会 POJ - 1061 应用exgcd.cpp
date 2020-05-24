#include"p.h"
#include<cmath>
#include<cstdio>
#include<iostream>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y) {
	if (!b) { x=1,y=0;return a; }
	ll d=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return d;
}
int main() {
	ll a,b,c,d,L;
	while (~scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&L)) {
		ll x,y,dist=a-b,pro=d-c,gcd=exgcd(pro,L,x,y);
		if (dist%gcd) { puts("Impossible");continue; }
		x*=dist/gcd;
		L=L/gcd;if (L<0) L=-L;
		printf("%lld\n",(x%L+L)%L);
	}
}