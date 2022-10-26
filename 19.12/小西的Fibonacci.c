#include<stdio.h>
typedef long long ll;
ll f[100];
ll Fibonacci(ll a){
	return a<3?1:(f[a]?f[a]:(f[a]=Fibonacci(a-1)+Fibonacci(a-2)));
}
int main(){
	while(~scanf("%lld",f))
	printf("%lld\n",Fibonacci(*f));
}
