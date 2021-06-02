#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a,_b=b;i<_b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
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
const int maxn=1e5+9;
ll val[19][maxn*2];
int n,m;
int lg2(int x){return x?31-__builtin_clz(x):-1;}
void build(int d,int l,int r){
	if(d==0) return;
	int mid=(l+r)>>1;
	val[d][mid]=val[0][mid];
	for(int i=mid-1;i>=l;i--) 
		val[d][i]=max(val[d][i+1],val[0][i]);
	val[d][mid+1]=val[0][mid+1];
	for(int i=mid+1;i<=r;i++) 
		val[d][i]=max(val[d][i-1],val[0][i]);
	build(d-1,l,mid);build(d-1,mid+1,r);
}
int query(int l,int r){
	if(l==r) return val[0][l];
	int dep=lg2((l-1)^(r-1))+1;
	return max(val[dep][l],val[dep][r]);
}
int main(){
	read(n,m);
	for(int i=1;i<=n;i++) read(val[0][i]);
	n=1<<(lg2(n)+1);
	build(lg2(n),1,n);
	rep(iii,0,m){
		int l,r;read(l,r);
		printf("%d\n",query(l,r));
	}
}