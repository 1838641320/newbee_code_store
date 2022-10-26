#include<stdio.h>
typedef long long ll;
ll reverse(ll a){
	char b[30]={0},i;
	sprintf(b,"%lld",a);
	for(i=29;b[i]==0;i--);
	a=0;
	for(int j=i;j>=0;j--) 
		a=a*10+b[j]-'0';
	return a;
}
int main() {
	ll a;
	while(~scanf("%lld",&a),~a) printf("%lld\n",reverse(a));
}
