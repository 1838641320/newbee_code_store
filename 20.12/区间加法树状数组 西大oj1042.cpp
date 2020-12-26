#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using ll=long long;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class A,class ...B>void read(A&a,B&...b){read(a);read(b...);}
//---------------------------------------------------------------------
int n;
const int maxn=1e5+9;
ll b1[maxn],b2[maxn];
void add(ll *b,int x,ll c){
	while(x<=n) b[x]+=c,x+=x&-x;
}
ll sum(ll *b,int x,ll sum=0){
	while(x) sum+=b[x],x-=x&-x;
	return sum;
}
void add(int l,int r,ll c){
	add(b2,l,c);add(b1,l,-c*(l-1));
	add(b2,r+1,-c);add(b1,r+1,c*r);
}
ll sum(int l,int r){
	l--;
	return (sum(b2,r)*r+sum(b1,r))-(sum(b2,l)*l+sum(b1,l));
}
int main() {
	int m,a,b;
	ll c;
	while(~scanf("%d%d",&n,&m)){
		memset(b1,0,(n+6)*sizeof(ll));
		memset(b2,0,(n+6)*sizeof(ll));
		rep(i,0,n) 
			read(c),add(b1,i+1,c);
		while(m--){
			int op;read(op,a,b);
			if(op==1) printf("%lld\n",sum(a,b));
			else read(c),add(a,b,c);
		}
	}
}