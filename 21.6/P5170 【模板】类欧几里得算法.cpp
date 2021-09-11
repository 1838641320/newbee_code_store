#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const ll mod=998244353;
const ll i2=499122177,i6=166374059;
ll qpow(ll x,ll n,ll c=1){for(;n;n/=2,x=x*x%mod)if(n&1)c=c*x%mod;return c;}
//f(a,b,c,n)=sum_{i=0}^n {floor((a*i+b)/c)  }
//g(a,b,c,n)=sum_{i=0}^n {floor((a*i+b)/c)*i}
//h(a,b,c,n)=sum_{i=0}^n {floor((a*i+b)/c)^2}
struct cnode{ll f,g,h;};
cnode like_euclid(ll a,ll b,ll c,ll n){
	ll ac=a/c%mod,bc=b/c%mod,m=(a*n+b)/c%mod;
	ll n1=(n+1)*n/2%mod,n2=n*(n+1)%mod*(n*2+1)%mod*i6%mod;
	if(!a) 
		return {(n+1)*bc%mod,n1*bc%mod,(n+1)*bc%mod*bc%mod};
	cnode ans;
	if(a>=c||b>=c){
		cnode tp=like_euclid(a%c,b%c,c,n);
		ans.f=tp.f+n1*ac+(n+1)*bc;
		ans.g=tp.g+n2*ac+n1*bc;
		ans.h=tp.h+tp.f*bc*2%mod+tp.g*ac*2%mod+
			n2*ac%mod*ac+(n+1)*bc%mod*bc+ac*bc%mod*n%mod*(n+1);
		ans.f%=mod;ans.g%=mod;ans.h%=mod;
		return ans;
	}
	cnode tp=like_euclid(c,c-b-1,a,(a*n+b)/c-1);
	ans.f=n*m-tp.f;
	ans.f=(ans.f%mod+mod)%mod;
	ans.g=(m%mod*n%mod*(n+1)-tp.f-tp.h)%mod*i2%mod;
	ans.g=(ans.g%mod+mod)%mod;
	ans.h=n*m%mod*(m+1)%mod-tp.g*2-tp.f*2-ans.f;
	ans.h=(ans.h%mod+mod)%mod;
	return ans;
}
ll t,n,a,b,c;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
        auto res=like_euclid(a,b,c,n);
        printf("%lld %lld %lld\n",res.f,res.h,res.g);
    }
}