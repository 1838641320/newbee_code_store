#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#include<queue>
typedef long long ll;
namespace fastio{const int Q=(1<<19)+1;static char in[Q],*is=in,*it=in,out[Q],*os=out;
int gc(){return is==it?it=(is=in)+fread(in,1,Q,stdin),(is==it?EOF:*is++):*is++;}
void pc(char c){*os++=c;if(os-out==Q)fwrite(out,1,os-out,stdout),os=out;;}
template<class A>void print(A a,char c=' '){static char o1[99]={},*o=o1;if(a<0) pc('-'),a=-a;if(a==0) pc('0');while(a>0) *(++o)=a%10,a/=10;while(o!=o1) pc(*(o--)+48);pc(c);}
template<class A,class...B>void print(A a,char c,B...b){print(a,c);print(b...);}
template<class T>void read(T&a){a=0;int f=0,c=gc();for(;!isdigit(c);c=gc()) f|=c=='-';for(;isdigit(c);c=gc()) a=a*10+(c^'0');if(f) a=-a;}
template<class A,class...B>void read(A&x,B&...y){read(x),read(y...);}
struct F{~F(){fwrite(out,1,os-out,stdout),os=out;}}f;
}using namespace fastio;
const ll mod=998244353;
int n,k;
namespace binomial{
	const int mmm=2e6+9;
	ll fac[mmm],ivf[mmm];
	ll qpow(ll x,ll n,ll c=1){
		for(;n;n/=2,x=x*x%mod)if(n&1)c=c*x%mod;
		return c;
	}
	void init(){
		fac[0]=1;
		for(int i=1;i<mmm;i++) fac[i]=fac[i-1]*i%mod;
		ivf[mmm-1]=qpow(fac[mmm-1],mod-2);
		for(int i=mmm-1;i>0;i--) ivf[i-1]=ivf[i]*i%mod;
	}
	ll C(int n,int m){
		if(!fac[0]) init();
		if(n<0||m<0||n<m) return 0;
		return fac[n]*ivf[m]%mod*ivf[n-m]%mod;
	}
	ll catalan(int n){return C(2*n,n)-C(2*n,n-1);}
}
void solve(){
	read(n,k);
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=0;i<k;i++) if(a[n-i]!=-1&&a[n-i]!=0) {
		print(0,'\n');
		return;
	}
	ll ans=binomial::fac[k]%mod;
	for(int i=1;i<=n-k;i++){
		if(a[i]==0){
			ans=ans*(k+1)%mod;
		}
		if(a[i]==-1){
			ans=ans*(k+i)%mod;
		}
	}
	print(ans,'\n');
}
int main(){
	binomial::init();
	int t=1;
	read(t);
	while(t--)
		solve();
}

/*输出流在线的版本
namespace fastio{
int gc(){const int Q=(1<<21)+1;static char in[Q],*is=in,*it=in;return is==it?it=(is=in)+fread(in,1,Q,stdin),(is==it?EOF:*is++):*is++;}
template<class A>void print(A a,char c=' '){static char o1[99]={},*o=o1;if(a<0) putc('-',stdout),a=-a;if(a==0) putc('0',stdout);while(a>0) *(++o)=a%10,a/=10;while(o!=o1) putc(*(o--)+48,stdout);putc(c,stdout);}
template<class A,class ...B>void print(A a,char c,B...b){print(a,c);print(b...);}
template<class T>void read(T&a){a=0;int f=0,c=gc();for(;!isdigit(c);c=gc()) f|=c=='-';for(;isdigit(c);c=gc()) a=a*10+(c^'0');if(f) a=-a;}
template<class A,class...B>void read(A&x,B&...y){read(x),read(y...);}
}using namespace fastio;
*/
