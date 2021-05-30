#include<iostream>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const ll mod=1e9+7;
//first few items   a_n=a_{n-1}+5a_{n-2}+a_{n-3}-a_{n-4}
const ll xn[]={1,5,11,36,95,281},an[]={0,1,5,1,mod-1};
const int len=4;//length of the recursion
ll res[len*2]={};
void mul(ll a[],ll b[]){//a*=b
	ll c[len*2]={};
	rep(i,0,len) rep(j,0,len) 
		c[i+j]=(c[i+j]+a[i]*b[j])%mod;
	for(int i=len*2-2;i>=len;i--){
		for(int j=1;j<=len;j++)//use recursion to go back
			c[i-j]=(c[i-j]+c[i]*an[j])%mod;
	}
	rep(i,0,len) a[i]=c[i];
}
void qpow(ll a[],ll n){
	ll c[len*2]={};c[1]=1;
	for(;n;n/=2,mul(c,c)) 
		if(n&1) mul(a,c);
	rep(i,0,len) c[i]=a[i];
}
int main(){
	ll n;
	while(~scanf("%lld",&n)){
		mem(res,0);
		res[0]=1;
		qpow(res,n-1);
		ll ans=0;
		rep(i,0,len) ans=(ans+xn[i]*res[i])%mod;
		printf("%lld\n",ans);
	}
}