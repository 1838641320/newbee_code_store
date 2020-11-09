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
//----------------------------------------
#include<cmath>
using namespace std;
const int maxn=2.5e5+9,base=maxn/3;
int bi[maxn]={},id[maxn]={},pi[maxn]={};
int n,m,x,t;
void add(int x,int t){
	while (x<maxn) bi[x]+=t,x+=x&-x;
}
int sum(int x){
	int ret=0;
	while (x) ret+=bi[x],x-=x&-x;
	return ret;
}
int getKth(int k){
	int res=0;
	for (int i=log2(maxn);~i;i--){
		int t=res+(1<<i);
		if (t<maxn&&bi[t]<k)
			res=t,k-=bi[t];
	}
	return res+1;
}
char s[99]={};
int main(){
	scanf("%d%d",&n,&m);
	rep(i,0,n){
		read(x);
		add(base+i,1);
		pi[x]=base+i;
		id[base+i]=x;
	}
	int L=base,R=base+n-1;
	while (m--){
		scanf("%s%d",s,&x);
		if(s[0]=='T'){
			add(pi[x],-1);add(--L,1);
			pi[x]=L,id[L]=x;
		}
		else if(s[0]=='B'){
			add(pi[x],-1);add(++R,1);
			pi[x]=R,id[R]=x;
		}
		else if(s[0]=='I'){
			read(t);
			int p1=pi[x],p2,i1=x,i2;
			p2=getKth(sum(p1)+t);
			i2=id[p2];
			swap(id[p1],id[p2]);
			swap(pi[i1],pi[i2]);
		}
		else if(s[0]=='A') 
			printf("%d\n",sum(pi[x])-1);
		else if(s[0]=='Q') 
			printf("%d\n",id[getKth(x)]);
	}
}
