#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
using ll=long long;
template<class ty>void myswap(ty&a,ty&b){ty t=b;b=a;a=t;}
template<class ty>void myrotate(ty a[],int s,int m,int e){
	if(s==m||m==e) return;
	for(int i=m;;){
		myswap(a[s++],a[i++]);
		if(s==m){
			if(i==e) return;
			m=i;
		}
		if(i==e) i=m;
	}
}
int main() {
	int n,p;scanf("%d%d",&n,&p);
	int a[109]={};
	rep(i,0,n) scanf("%d",&a[i]);
	myrotate(a,0,p%n,n);
	rep(i,0,n) printf(" %d"+!i,a[i]);
}
