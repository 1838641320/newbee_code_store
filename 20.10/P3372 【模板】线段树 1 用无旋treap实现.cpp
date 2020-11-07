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
#include<random>
#include<ctime>
const int maxn=1e5+9;
using namespace std;
mt19937 rd;
int n,m;
int ch[maxn][2],pri[maxn],szt[maxn];
ll val[maxn],lz[maxn],sum[maxn];
int root,L,M,R,sz;
void init(){sz=0,rd.seed(time(0));root=0;}
int newn(int x){
	szt[++sz]=1,val[sz]=sum[sz]=x,pri[sz]=rd();
	ch[sz][0]=ch[sz][1]=lz[sz]=0;
	return sz;
}
void update(int in) {
	int lch=ch[in][0],rch=ch[in][1];
	szt[in]=szt[lch]+szt[rch]+1;
	sum[in]=sum[lch]+sum[rch]+val[in];
}
void pushdown(int in){
	int la=lz[in],lch=ch[in][0],rch=ch[in][1];;
	if(!la) return ;
	if(lch) 
		val[lch]+=la,lz[lch]+=la,sum[lch]+=la*szt[lch];
	if(rch) 
		val[rch]+=la,lz[rch]+=la,sum[rch]+=la*szt[rch];
	lz[in]=0;
}
int merge(int l,int r){
	if(!l||!r) return l+r;
	if(pri[l]<pri[r]){
		pushdown(l),ch[l][1]=merge(ch[l][1],r);
		update(l);return l;
	}
	else {
		pushdown(r);ch[r][0]=merge(l,ch[r][0]);
		update(r);return r;
	}
}
void split(int in,int v,int &l,int &r){
	if(!in) return void(l=r=0);
	pushdown(in);
	int s=szt[ch[in][0]]+1;
	if(v>=s)
		l=in,split(ch[in][1],v-s,ch[in][1],r);
	else 
		r=in,split(ch[in][0],v,l,ch[in][0]);
	update(in);
}
int main(){
	init();
	read(n,m);
	for(int i=1;i<=n;i++){
		int x;read(x);
		root=merge(root,newn(x));
	}
	int op,x,y,k;
	while(m--){
		read(op,x,y);
		if(op==1){
			read(k);
			split(root,x-1,L,M);
			split(M,y-x+1,M,R);
			lz[M]+=k;val[M]+=k;sum[M]+=k*szt[M];
			root=merge(L,merge(M,R));
		}
		else if(op==2){
			split(root,x-1,L,M);
			split(M,y-x+1,M,R);
			printf("%lld\n",sum[M]);
			root=merge(L,merge(M,R));
		}
	}
}