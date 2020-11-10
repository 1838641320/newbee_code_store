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
//----------------------------------------
#include<random>
#include<ctime>
template<class ty=int,int maxn=(int)1e6+9>class treap{
	std::mt19937 rd;
	int mem[maxn],top;
	int szt[maxn],ch[maxn][2],val[maxn],pri[maxn]={};
public:
	int L,M,R,root;
	treap(){
		top=0;root=0;
		rd.seed(time(0));top=0;
		for(int i=1;i<maxn;i++) mem[top++]=i;
	}
	int newn(int v){
		int n=mem[--top];
		szt[n]=1,val[n]=v,pri[n]=rd();
		ch[n][0]=ch[n][1]=0;
		return n;
	}
	void update(int in){szt[in]=szt[ch[in][0]]+szt[ch[in][1]]+1;}
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
			l=in,split(ch[l][1],v,ch[l][1],r);
		else 
			r=in,split(ch[r][0],v,l,ch[r][0]);
		update(in);
	}
	int getKth(int k){
		for(int t,in=root;1;){
			t=szt[ch[in][0]];
			if(k<=t) in=ch[in][0];
			else if(k==t+1) return val[in];
			else in=ch[in][1],k-=t+1;
		}
	}
	void insert(int v){
		split(root,v,L,R);
		root=merge(L,merge(newn(v),R));
	}
	void erase(int v){
		split(root,v-1,L,R);
		split(R,v,M,R);
		if(M) mem[top++]=M;
		M=merge(ch[M][0],ch[M][1]);
		root=merge(L,merge(M,R));
	}
	int getRankOf(int x){
		split(root,x-1,L,R);
		int ret=szt[L]+1;
		root=merge(L,R);
		return ret;
	}
};
treap<int,(int)2e5+9> tr;
int main(){
	int n,op,x;
	read(n);
	while(n--){
		read(op,x);
		if(op==1) tr.insert(x);
		else if(op==2) tr.erase(x);
		else if(op==3) printf("%d\n",tr.getRankOf(x));
		else if(op==4) printf("%d\n",tr.getKth(x));
		else if(op==5) printf("%d\n",tr.getKth(tr.getRankOf(x)-1));
		else if(op==6) printf("%d\n",tr.getKth(tr.getRankOf(x+1)));
	}
}