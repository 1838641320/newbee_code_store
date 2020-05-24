#include"p.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y) {
	if (!b) { x=1,y=0;return a; }
	ll gcd=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return gcd;
}
int main() {
	ll a,b,c,x1,x2,y1,y2,t1,t2;
	scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&x1,&x2,&y1,&y2);
	if (a==0&&b==0) {
		if (c) return puts("0");
		return printf("%lld\n",(y2-y1+1)*(x2-x1+1)),0;
	}
	if (a==0) {
		int y=c/b;
		if (c%b||y>y2||y<y1) return puts("0"),0;
		return printf("%lld\n",x2-x1+1),0;
	}
	if (b==0) {
		int x=c/a;
		if (c%a||x>x2||x<x1) return puts("0"),0;
		return printf("%lld\n",y2-y1+1),0;
	}
	if (a<0) { a=-a;ll t=x1;x1=-x2;x2=-t; }
	if (b<0) { b=-b;ll t=y1;y1=-y2;y2=-t; }
	ll gcd=exgcd(a,b,t1,t2);
	if (c%gcd) return puts("0"),0;
	a/=gcd,b/=gcd,c/=-gcd;
	ll x=c*t1,y=c*t2;
	x1-=x,x2-=x,y1-=y,y2-=y;
	ll r=floor((double)x2/b),l=ceil((double)x1/b);
	ll u=floor((double)y1/-a),d=ceil((double)y2/-a);
	printf("%lld\n",max(0ll,min(r,u)-max(l,d)+1));
}