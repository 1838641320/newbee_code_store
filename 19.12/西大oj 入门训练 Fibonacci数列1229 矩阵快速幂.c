#include<stdio.h>
#include<string.h>
#define matrx_mul2
typedef long long ll;
const ll mod=10007;
ll N;
//------------------a times b,result in a
#ifdef matrx_mul2
void matrx_mul(ll a[N][N],ll b[N][N]){
	ll c[N][N];
	memset(c,0,8*N*N);
	for(ll i=0;i<N;i++){
		for(ll k=0;k<N;k++){
			if(a[i][k]==0) continue;
			for(ll j=0;j<N;j++){
				c[i][j]+=a[i][k]*b[k][j]%mod;
			}
		}
	}
	for(ll i=0;i<N;i++) for(ll j=0;j<N;j++) a[i][j]=c[i][j]%mod;
}
#endif
#ifndef matrx_mul2
void matrx_mul(ll a[N][N],ll b[N][N]){
	ll c[N][N];
	memset(c,0,8*N*N);
	for(ll i=0;i<N;i++){
		for(ll j=0;j<N;j++){
			for(ll k=0;k<N;k++){
				c[i][j]+=a[i][k]*b[k][j]%mod;
			}
		}
	}
	for(ll i=0;i<N;i++) for(ll j=0;j<N;j++) a[i][j]=c[i][j]%mod;
}
#endif
//--------------------n power of a
void qpow(ll a[N][N],ll n){
	ll t[N][N];
	memset(t,0,8*N*N);
	for(ll i=0;i<N;i++) for(ll j=0;j<N;j++) t[i][j]=a[i][j]%mod;
	memset(a,0,8*N*N);
	for(ll i=0;i<N;i++) a[i][i]=1;
	while(n){
		if(n&1) matrx_mul(a,t);
		matrx_mul(t,t);
		n>>=1;
	}
}
//--------------------
int main() {
	ll fibonacci[2][2]=
		{{1,1},
		 {1,0}};
	ll n;
	scanf("%lld",&n);
	N=2;
	qpow(fibonacci,n);
	printf("%lld\n",fibonacci[0][1]);
}
