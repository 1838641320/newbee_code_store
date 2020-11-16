#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;~c&&!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class A,class ...B>void read(A&a,B&...b){read(a);read(b...);}
//----------------------------------
template<class key=int,class ty=int,int maxsize=(int)1e5+9>
struct HashMap{
	struct n{
		key u;
		ty v;
		int nex;
	}e[maxsize*2];
	int head[maxsize],sz=0;
	HashMap(){sz=0,memset(head,0,sizeof(head));}
	ty&operator[](key a){
		int t=a%maxsize;
		for(int i=head[t];i;i=e[i].nex)
			if(e[i].u==a) return e[i].v;
		return e[++sz]={a,0,head[t]},head[t]=sz,e[sz].v;
	}
};
HashMap<ll,ll,int(2e6+9)> Su;
ll n,m;
void add(ll p,ll x){
	ll cnt=1;
	while(p<=n) 
		Su[p]+=(cnt++)*x,p+=p&-p;
}
ll sum(ll x){
	ll ret=0;
	while(x) 
		ret+=Su[x],x-=x&-x;
	return ret;
}
int main(){
	read(n,m);
	while(m--){
		int c;
		ll l,r;
		read(c,l,r);
		if(c==1) add(l,r);
		else printf("%lld\n",sum(r)-sum(l-1));
	}
}