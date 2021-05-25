#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a;i<b;i++)
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
//-------------------------------------------------
using namespace std;
const int maxn=2e5+9;
#define mid ((l+r)>>1)
int n,m,sz,T[maxn*2];
struct {int par,dep,lc,rc;}nd[maxn*40];
void build(int&in,int l=1,int r=n){
	in=++sz;
	if(l==r) {nd[in].par=l;return;}
	build(nd[in].lc,l,mid),build(nd[in].rc,mid+1,r);
}
void update(int&in,int pos,int pa,int l=1,int r=n){
	sz++;nd[sz]=nd[in];
	in=sz;
	if(l==r){nd[in].par=pa;return;}
	if(pos<=mid) update(nd[in].lc,pos,pa,l,mid);
	else update(nd[in].rc,pos,pa,mid+1,r);
}
void add(int&in,int pos,int l=1,int r=n){
	sz++;nd[sz]=nd[in];
	in=sz;
	if(l==r){nd[in].dep++;return;}
	if(pos<=mid) add(nd[in].lc,pos,l,mid);
	else add(nd[in].rc,pos,mid+1,r);
}
int query(int in,int pos,int l=1,int r=n){
	if(l==r) return in;
	if(pos<=mid) return query(nd[in].lc,pos,l,mid);
	else return query(nd[in].rc,pos,mid+1,r);
}
int findp(int ti,int pos){
	int y=query(T[ti],pos);
	if(nd[y].par==pos) return y;
	return findp(ti,nd[y].par);
}
void unite(int ti,int a,int b){
	int ta=findp(ti,a),tb=findp(ti,b);
	if(nd[ta].dep>nd[tb].dep) swap(ta,tb);//ta<=tb
	if(nd[ta].par==nd[tb].par) return;
	update(T[ti],nd[ta].par,nd[tb].par);
	if(nd[ta].dep==nd[tb].dep) add(T[ti],nd[tb].par);
}
int main(){
	scanf("%d%d",&n,&m);
	build(T[0]);
	int tim=0,op,a,b;
	for(tim=1;tim<=m;tim++){
		scanf("%d%d",&op,&a);
		T[tim]=T[tim-1];
		if(op==1){
			scanf("%d",&b);
			unite(tim,a,b);
		}
		else if(op==2) T[tim]=T[a];
		else {
			scanf("%d",&b);
			int ta=findp(tim,a),tb=findp(tim,b);
			printf("%d\n",nd[ta].par==nd[tb].par);
		}
	}
}