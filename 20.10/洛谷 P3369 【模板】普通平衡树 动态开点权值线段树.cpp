#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;!isdigit(c)&&~c;c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class a,class ...b>void read(a&A,b&...B){read(A);read(B...);}
//-----------------------
const int maxn=1e5+9;
struct {int v,l,r;} tr[maxn*30]={};
int cnt=0,root=0;
const ll inf=2e7;
#define mid (l+r>>1)
#define lch tr[in].l
#define rch tr[in].r
void init(){mem(tr,0);cnt=root=0;}
void insert(int v,int&in=root,ll l=-inf,ll r=inf){
	if(!in) in=++cnt;
	tr[in].v++;
	if(l==r) return;
	if(mid>=v) insert(v,lch,l,mid);
	else insert(v,rch,mid+1,r);
}
void erase(int v,int in=root,ll l=-inf,ll r=inf){
	tr[in].v--;
	if(l==r) return;
	if(mid>=v) erase(v,lch,l,mid);
	else erase(v,rch,mid+1,r);
}
int getKth(int k,int in=root,ll l=-inf,ll r=inf){
	int t;
	while(l!=r){
		t=tr[lch].v;
		if(t>=k) in=lch,r=mid;
		else k-=t,in=rch,l=mid+1;
	}
	return l;
}
int getRankof(int x,int in=root,ll l=-inf,ll r=inf){
	int sum=1;
	while(l!=r&&in){
		if(mid<x) sum+=tr[lch].v,l=mid+1,in=rch;
		else r=mid,in=lch;
	}
	return sum;
}
int main(){
	int n,ty,p;
	read(n);
	while(n--){
		read(ty,p);
		if(ty==1) insert(p);
		else if(ty==2) erase(p);
		else if(ty==3) printf("%d\n",getRankof(p));
		else if(ty==4) printf("%d\n",getKth(p));
		else if(ty==5) printf("%d\n",getKth(getRankof(p)-1));
		else if(ty==6) printf("%d\n",getKth(getRankof(p+1)));
	}
}