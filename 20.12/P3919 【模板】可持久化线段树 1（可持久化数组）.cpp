#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class A,class ...B>void read(A&a,B&...b){read(a);read(b...);}
//---------------------------------------------------------------------
#define mid (l+r>>1)
using namespace std;
int n,m;
const int maxn=1e6+9;
int val[maxn*40],lc[maxn*40],rc[maxn*40],sz=0;
int T[maxn],a[maxn];
void build(int&ro,int l=1,int r=n){
	ro=++sz;
	if(l==r) return void(val[ro]=a[l]);
	build(lc[ro],l,mid);
	build(rc[ro],mid+1,r);
}
int X,D;
void update(int&ro,int l=1,int r=n){
	val[++sz]=val[ro],lc[sz]=lc[ro],rc[sz]=rc[ro];
	ro=sz;
	if(l==r) return void(val[ro]=D);
	if(X<=mid) update(lc[ro],l,mid);
	else update(rc[ro],mid+1,r);
}
int query(int ro,int l=1,int r=n){
	if(l==r) return val[ro];
	if(X<=mid) return query(lc[ro],l,mid);
	else return query(rc[ro],mid+1,r);
}
int main(){
	read(n,m);
	for(int i=1;i<=n;i++) read(a[i]);
	build(T[0]);
	int v,op;
	for(int i=1;i<=m;i++){
		read(v,op,X);
		T[i]=T[v];
		if(op==1) read(D),update(T[i]);
		else printf("%d\n",query(T[i]));
	}
}