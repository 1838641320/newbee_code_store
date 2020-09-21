#includebitsstdc++.h
#define rep(i,a,b) for(ll i=a;ib;i++)
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
using ll=long long;
templateclass tyvoid myswap(ty&a,ty&b){ty t=b;b=a;a=t;}
templateclass tyvoid myrotate(ty a[],int s,int m,int e){
	if(s==mm==e) return;
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
	int n,p;scanf(%d%d,&n,&p);
	int a[109]={};
	rep(i,0,n) scanf(%d,&a[i]);
	myrotate(a,0,p%n,n);
	rep(i,0,n) printf( %d+!i,a[i]);
}