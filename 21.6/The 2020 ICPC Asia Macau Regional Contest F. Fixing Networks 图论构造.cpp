#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a,_b=b;i<_b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef uint64_t ull;
template<class A>void read(A&a){
	a=0;int c=getchar(),f=0;
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class A,class ...B>
void read(A&a,B&...b){read(a);read(b...);}
using namespace std;
//-------------------------------------------------
#include<set>
#include<queue>

const int maxn=1e5+9;
set<int> g[maxn];

int n,d,c;

int main() {
	scanf("%d%d%d",&n,&d,&c);
	if(d==0){
		if(n==c) {
			puts("Yes");
			rep(i,0,n) puts("");
		}
		else puts("No");
		return 0;
	}
	if(d==1){
		if(n==c*2){
			puts("Yes");
			rep(i,0,n) printf("%d\n",i&1?i:i+2);
		}
		else puts("No");
		return 0;
	}
	int minc=d+1;
	if(minc*c>n) return puts("No"),0;
	if((n%minc)%2&&d%2) return puts("No"),0;
	puts("Yes");
	for(int i=0;i<c-1;i++){
		int s=i*minc+1;
		int t=(i+1)*minc;
		for(int j=s;j<=t;j++){
			for(int k=j+1;k<=t;k++)
				g[j].insert(k),
				g[k].insert(j);
		}
	}
	int s=minc*(c-1)+1,t=n,len=(t-s+1);
	if(d%2) {
		d--;
		for(int i=s;i<=t;i++){
			int u=(i+len/2-s)%len+s;
			g[i].insert(u);
			g[u].insert(i);
		}
	}
	d/=2;
	for(int j=1;j<=d;j++){
		for(int i=s;i<=t;i++){
			int u=(i+j-s)%len+s;
			g[i].insert(u),
			g[u].insert(i);
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j:g[i]) printf("%d ",j);
		puts("");
	}
}