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
int ch[maxn][2],pri[maxn],val[maxn],fl[maxn],szt[maxn];
int root,L,M,R,sz;
void init(){sz=0,rd.seed(time(0));root=0;}
int newn(int x){
	szt[++sz]=1,val[sz]=x,pri[sz]=rd();
	ch[sz][0]=ch[sz][1]=0;
	return sz;
}
void update(int in) {szt[in]=szt[ch[in][0]]+szt[ch[in][1]]+1;}
void pushdown(int in){
	if(!fl[in]) return ;
	swap(ch[in][0],ch[in][1]);
	fl[ch[in][0]]^=1;fl[ch[in][1]]^=1;
	fl[in]=0;
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
void print(int in){
	if(!in) return;
	pushdown(in);
	print(ch[in][0]);
	printf("%d ",val[in]);
	print(ch[in][1]);
}
int main(){
	read(n,m);
	for(int i=1;i<=n;i++)
		root=merge(root,newn(i));
	for(int l,r;m--;){
		read(l,r);
		split(root,l-1,L,M);
		split(M,r-l+1,M,R);
		fl[M]^=1;
		root=merge(L,merge(M,R));
	}
	print(root);
}