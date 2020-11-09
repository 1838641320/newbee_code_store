#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
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
#include<random>
#include<ctime>
using namespace std;
const int maxn=1.4e6+9;
namespace treap{
	mt19937 rd;
	int mem[maxn],top=0;
	int ch[maxn][2]={},pri[maxn],val[maxn],szt[maxn];
	int root,L,R,M;
	void init(){
		top=root=0;
		rd.seed(time(0));
		for(int i=1;i<maxn;i++) mem[top++]=i;
	}
	int newnode(int v){
		int n=mem[--top];
		szt[n]=1,val[n]=v,pri[n]=rd();
		ch[n][0]=ch[n][1]=0;
		return n;
	}
	void update(int x){szt[x]=szt[ch[x][0]]+szt[ch[x][1]]+1;}
	int merge(int l,int r){
		if(!l||!r) return l+r;
		if(pri[l]<pri[r])
			{ch[l][1]=merge(ch[l][1],r);update(l);return l;}
		else 
			{ch[r][0]=merge(l,ch[r][0]);update(r);return r;}
	}
	void split(int in,int v,int &l,int &r){
		if(!in) return void(l=r=0);
		if(val[in]<=v)
			l=in,split(ch[in][1],v,ch[in][1],r);
		else 
			r=in,split(ch[in][0],v,l,ch[in][0]);
		update(in);
	}
	int getKth(int in,int k){
		while(1){
			int t=szt[ch[in][0]];
			if(k<=t) in=ch[in][0];
			else if(k==t+1) return val[in];
			else k-=t+1,in=ch[in][1];
		}
	}
	void insert(int v){
		split(root,v,L,R);
		root=merge(L,merge(newnode(v),R));
	}
	void erase(int v){
		split(root,v-1,L,R);
		split(R,v,M,R);
		if(M) mem[top++]=M;
		M=merge(ch[M][0],ch[M][1]);
		root=merge(L,merge(M,R));
	}
	int getRankOf(int v){
		split(root,v-1,L,R);
		int t=szt[L]+1;
		root=merge(L,R);
		return t;
	}
}
using namespace treap;
int main(){
	init();
	int n,m,ty,p;
	read(n);
	while(n--){
		read(ty,p);
		if(ty==1) insert(p);
		if(ty==2) erase(p);
		if(ty==3) printf("%d\n",getRankOf(p));
		if(ty==4) printf("%d\n",getKth(root,p));
		if(ty==5) printf("%d\n",getKth(root,getRankOf(p)-1));
		if(ty==6) printf("%d\n",getKth(root,getRankOf(p+1)));
	}
}
