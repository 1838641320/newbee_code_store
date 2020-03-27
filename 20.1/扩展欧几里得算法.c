#include<stdio.h>
typedef long long ll;
ll extgcd(ll a,ll b,ll* x,ll* y){
	ll d=a;
	if(b){
		d=extgcd(b,a%b,y,x);
		*y-=a/b**x;
	}
	else *x=1,*y=0;
	return d;
}
void exgcd(ll a,ll b,ll &x,ll &y,ll &d){
	if(!b) {d = a;x = 1;y=0;}
	else{
		exgcd(b,a%b,y,x,d);
		y-=x*(a/b);
	}
}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
	ll a,b,x,y;
	while(~scanf("%lld%lld",&a,&b)){
		ll t=extgcd(a,b,&x,&y);
		printf("gcd:%lld\nsolve\"a*x+b*y=gcd(a,b)\"\nx:%lld y:%lld\n\n",t,x,y);
	}
}
