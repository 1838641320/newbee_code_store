#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
template<class ty>ty gcd(ty x,ty y){while(x^=y^=x^=y%=x);return y;}
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;!isdigit(c)&&~c;c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class a,class ...b>void read(a&A,b&...B){read(A);read(B...);}
//-----------------------
using namespace std;
int seed=20201119;
int rd(){return seed=seed*ll(1e9+93)^123456879;}
namespace treap{
	const int maxn=5e4+9;
	int val[maxn],pri[maxn],szt[maxn],ch[maxn][2],sz;
	int root,L,M,R;
	int fl[maxn],ad[maxn],ma[maxn];
	void init(){root=sz=0;}
	int newn(int x){
		val[++sz]=x,pri[sz]=rd(),szt[sz]=1,ch[sz][0]=ch[sz][1]=0;
		fl[sz]=ad[sz]=0,ma[sz]=x;
		return sz;
	}
	void up(int in){
		int lch=ch[in][0],rch=ch[in][1];
		szt[in]=szt[lch]+szt[rch]+1;
		ma[in]=val[in];
		if(lch) ma[in]=max(ma[in],ma[lch]);
		if(rch) ma[in]=max(ma[in],ma[rch]);
	}
	void down(int in){
		int lch=ch[in][0],rch=ch[in][1];
		if(ad[in]){
			if(lch) 
				val[lch]+=ad[in],ad[lch]+=ad[in],ma[lch]+=ad[in];
			if(rch) 
				val[rch]+=ad[in],ad[rch]+=ad[in],ma[rch]+=ad[in];
			ad[in]=0;
		}
		if(fl[in]){
			if(lch) fl[lch]^=1;
			if(rch) fl[rch]^=1;
			swap(ch[in][0],ch[in][1]);
			fl[in]=0;
		}
	}
	void split(int in,int k,int&l,int&r){
		if(!in) return void(l=r=0);
		down(in);
		int t=szt[ch[in][0]]+1;
		if(t<=k)
			l=in,split(ch[l][1],k-t,ch[l][1],r);
		else 
			r=in,split(ch[r][0],k,l,ch[r][0]);
		up(in);
	}
	int merge(int l,int r){
		if(!l||!r) return l+r;
		if(pri[l]<pri[r]){
			down(l);ch[l][1]=merge(ch[l][1],r);
			up(l);return l;
		}
		else {
			down(r);ch[r][0]=merge(l,ch[r][0]);
			up(r);return r;
		}
	}
	void add(int l,int r,int v){
		split(root,l-1,L,M);
		split(M,r-l+1,M,R);
		ad[M]+=v,ma[M]+=v,val[M]+=v;
		root=merge(L,merge(M,R));
	}
	void flip(int l,int r){
		split(root,l-1,L,M);
		split(M,r-l+1,M,R);
		fl[M]^=1;
		root=merge(L,merge(M,R));
	}
	int find_max(int l,int r){
		split(root,l-1,L,M);
		split(M,r-l+1,M,R);
		int ret=ma[M];
		root=merge(L,merge(M,R));
		return ret;
	}
}
using namespace treap;
int n,m,li,ri,xi,op;
int main(){
	read(n,m);
	init();
	while(n--) root=merge(root,newn(0));
	while(m--){
		read(op,li,ri);
		if(op==1) read(xi),add(li,ri,xi);
		else if(op==2) flip(li,ri);
		else printf("%d\n",find_max(li,ri));
	}
}