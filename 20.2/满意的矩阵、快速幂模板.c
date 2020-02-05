#include<stdio.h>
#include<string.h>
#define mod 1000000007
#define all(i,x) for(int i=0;i<x;i++)
typedef long long ll;
ll n;
void mat_mul(ll a[n][n],ll b[n][n]) {
	ll c[n][n];
	memset(c,0,sizeof(c));
	all(i,n) all(k,n) if(a[i][k]==0) continue;
	else all(j,n) c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
	memcpy(a,c,sizeof(c));
}
void mat_mul2(ll a[n][n],ll b[n][n]) {
	ll c[n][n];
	memset(c,0,sizeof(c));
	all(i,n) all(k,n) all(j,n) 
		c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
	memcpy(a,c,sizeof(c));
}
ll PowerMod(ll a,int n){ll c=1;for(;n;n>>=1,a=a*a%mod) if(n&1) c=c*a%mod;return c;}//calculate a^n
void qpow(ll a[n][n],int k){
	ll c[n][n];memset(c,0,sizeof(c));all(i,n) c[i][i]=1;//initialize c
	for(; k; k>>=1,mat_mul(a,a)) if(k&1) mat_mul(c,a);//calculate a^k
	memcpy(a,c,sizeof(c));//return a
}
int main(void) {
	//scanf("%d",&n);
	n=2;
	ll a[2][2]={{1,1},{1,0}};
	//mat_mul(a,a);mat_mul(a,a);mat_mul(a,a);mat_mul(a,a);
	qpow(a,5060001);
	printf("%lld",a[0][0]);
}
