#include<stdio.h>
typedef long long ll;
ll extgcd(ll a,ll b,ll *x,ll *y){
	ll d=a;
	if(b){
		d=extgcd(b,a%b,y,x);
		*y-=a/b**x;
	}
	else *x=1,*y=0;
	return d;
}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
	ll a=4,b=11,x,y,t=extgcd(a,b,&x,&y);
	printf("%lld %lld %lld %lld\n",gcd(a,b),t,x,y);
}
