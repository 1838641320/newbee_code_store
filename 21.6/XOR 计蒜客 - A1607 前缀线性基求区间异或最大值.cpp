#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a,_b=b;i<_b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn=1e4+9;
int bas[maxn][30],pos[maxn][30];
int a[maxn],n,q,k;
void insert(int x,int p){
	for(int i=0;i<30;i++) 
		bas[p][i]=bas[p-1][i],
		pos[p][i]=pos[p-1][i];
	int now=p;
	for(int i=29;i>=0;i--)if(x>>i&1){
		if(!bas[now][i]){
			bas[now][i]=x;
			pos[now][i]=p;
			break;
		}
		if(pos[now][i]<p){
			swap(bas[now][i],x);
			swap(pos[now][i],p);
		}
		x^=bas[now][i];
	}
}
int query(int l,int r){
	int ret=0;
	for(int i=29;i>=0;i--)if(pos[r][i]>=l)
		ret=max(ret,ret^bas[r][i]);
	return ret;
}
void solve(){
	mem(bas,0),mem(pos,0);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]&=(~k);
		insert(a[i],i);
	}
	rep(ii,0,q){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r)|k);
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--) solve();
}