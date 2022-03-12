#include<iostream>
#include<algorithm>
#include<cstring>
#pragma GCC optimize("Ofast")
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
#include<queue>
#include<numeric>
#include<array>
typedef long long ll;
const int maxn=5e6+9;
namespace fastio{
inline int gc(){const int Q=(1<<21)+1;static char in[Q],*is=in,*it=in;
return is==it?it=(is=in)+fread(in,1,Q,stdin),(is==it?EOF:*is++):*is++;}
template<class A>inline void print(A a,char c=' '){static char o1[99]={},*o=o1;if(a<0) putc('-',stdout),a=-a;
if(a==0) putc('0',stdout);while(a>0) *(++o)=a%10,a/=10;while(o!=o1) putc(*(o--)+48,stdout);putc(c,stdout);}
template<class A,class ...B>void print(A a,char c,B...b){print(a,c);print(b...);}
template<class T>inline void read(T&a){a=0;int f=0,c=gc();
for(;!isdigit(c);c=gc()) f|=c=='-';for(;isdigit(c);c=gc()) a=a*10+(c^'0');if(f) a=-a;}
template<class A,class...B>void read(A&x,B&...y){read(x),read(y...);}
}using namespace fastio;
int deep[maxn],par[maxn];
int a[maxn],l[maxn],r[maxn],ans[maxn];
ll s[maxn];
int findp(int x){while(x!=par[x])x=par[x]=par[par[x]];return x;}
vector<int> st;
void solve(int __case){
	int n,q;
	read(n,q);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) s[i+1]=s[i]+a[i];
	s[n+1]=-1ll<<60;
	st.push_back(n+1);
	deep[n+1]=0;
	iota(par,par+3+n,0);
	rep(i,0,q) read(l[i],r[i]);
	for(int i=q-1,j=n+1;i>=0;i--){
		while(j>l[i]){
			j--;
			while(s[st.back()]>=s[j]){
				int t=st.back();st.pop_back();
				par[t]=findp(t-1);
			}
			deep[j]=st.size();
			st.push_back(j);
		}
		ans[i]=deep[j]-deep[findp(r[i])]+1;
	}
	rep(i,0,q) print(ans[i],'\n');
}
int main(){
	st.reserve(5e6+9);
	int t=1;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) solve(i);
}
