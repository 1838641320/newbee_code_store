#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
template<class ty>void read(ty&a){
	a=0;int f=0,c=getchar();
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class A,class ...B>void read(A&a,B&...b){read(a);read(b...);}
//---------------------------------------------------------------------
using namespace std;
const int maxn=5e1+9;
int a[maxn],l2[maxn],stmin[17][maxn],stmax[17][maxn];
int n,q,l,r;
void pre(int n){
	l2[1]=0;
	rep(i,2,maxn) l2[i]=l2[i/2]+1;
	rep(i,0,n) stmin[0][i]=stmax[0][i]=a[i];
	for(int i=1;1<<i<=n;i++){
		for(int j=0;j+(1<<i)-1<n;j++){
			stmin[i][j]=min(stmin[i-1][j],stmin[i-1][j+(1<<i-1)]);
			stmax[i][j]=max(stmax[i-1][j],stmax[i-1][j+(1<<i-1)]);
		}
	}
}
int main(){
	read(n);
	rep(i,0,n) read(a[i]);
	pre(n);
	read(q);
	while(q--){
		read(l,r);
		int x=floor(l2[r-l+1]);
		ll mi=min(stmin[x][l-1],stmin[x][r-(1<<x)]);
		ll ma=max(stmax[x][l-1],stmax[x][r-(1<<x)]);
		printf("%lld\n",ma*ma-mi*mi);
	}
}