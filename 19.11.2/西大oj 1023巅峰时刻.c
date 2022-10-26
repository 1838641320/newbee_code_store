#include<stdio.h>
#define ll long long
ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
}
int main(){
	ll i,e,a,q1,q2,q3,n,k=1;
	while(~scanf("%lld%lld%lld%lld%lld%lld%lld",&i,&e,&a,&q1,&q2,&q3,&n)){
		if(i==-1&&e==-1&&a==-1&&q1==-1&&q2==-1&&q3==-1&&n==-1) return 0;
		ll sec=i+q1,lmc=q1*q2/gcd(q1,q2),product=q3*q2/gcd(q2,q3),result,s2=e%q2,s3=a%q3;
		product*=q1/gcd(product,q1);
		for(;sec%q2!=s2;sec+=q1);
		for(;sec%q3!=s3;sec+=lmc);
		sec-=n;
		while(sec<0||sec+n<=e||sec+n<=a) sec+=product;
		printf("Case %d : %lld seconds .\n",k++,sec);
	}
}
