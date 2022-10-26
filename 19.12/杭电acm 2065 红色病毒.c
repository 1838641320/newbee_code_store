#include<stdio.h>
#define mod 100
#define AC_code2
typedef long long ll;
#ifdef looking_for_pattern
ll fact[60]={0};
void fact_cal(){
	for(ll i=1;i<59;i++){
		ll an=1,n=i;
		while(--n) an*=n;
		fact[i-1]=an;
	}
}
ll C(ll n,ll m){
	return fact[n]/(fact[m]*fact[n-m]);
}
int main(){
	fact_cal();
	int n,i,j,k,count;
	while(~scanf("%d",&n)){
		count=0;
		for(i=0;i<=n;i++){
			for(j=0;j<=n;j++){
				for(k=0;k<=n;k++){
					if((i%2==0)&&(k%2==0)&&(i+j+k<=n)) {
						count+=fact[n]/fact[i]/fact[j]/fact[k]/fact[n-i-j-k];
						//printf("%d%d%d%d ",i,j,k,n-i-j-k);
					}
				}
			}
		}
		printf("%lld",count);
		puts("");
	}
}
#endif
#ifdef AC_code1
ll qpow(ll a,ll n){
	ll t=a%mod;
	a=1;
	while(n){
		if(n&1) a=a*t%mod;
		t=t*t%mod;
		n>>=1;
	}
	return a;
}
int main(){
	ll n,i,T;
	while(~scanf("%lld",&n)&&n) {
		for(i=1;i<=n;i++){
			scanf("%lld",&T);
			printf("Case %lld: %lld\n",i,(qpow(4,T-1)+qpow(2,T-1))%mod);
		}
		puts("");
	}
}
#endif
#ifdef looking_for_pattern2
typedef long long ll;
ll qpow(ll a,ll n){
	ll t=a%mod;
	a=1;
	while(n){
		if(n&1) a=a*t%mod;
		t=t*t%mod;
		n>>=1;
	}
	return a;
}
int main(){
	ll n,i,T;
	while(~scanf("%lld",&n)&&n) {
		for(int j=1;j<10*n;j++) {
			printf("%2lld ",(qpow(4,j-1)+qpow(2,j-1))%mod);
			if(!(j%20)) puts("");
		}
		puts("");
	}
}
#endif
#ifdef AC_code2
int main(){
	ll save[21]={52,56,20,72,72,56,60,12,92,56,0,52,12,56,40,92,32,56,80,32},n,i,T;
	while(~scanf("%lld",&n)&&n) {
		for(i=1;i<=n;i++){
			scanf("%lld",&T);
			printf("Case %lld: ",i);
			if(T>2) printf("%lld",save[(T-1)%20]);
			else if (T==1) putchar('2');
			else putchar('6');
			puts("");
		}
		puts("");
	}
}
#endif
