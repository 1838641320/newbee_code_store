#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using ll=long long;
#include<bitset>
using namespace std;
const ll mod =998244353; 
const int maxn=2e2+9;
typedef bitset<maxn> bi;
typedef bi mat[maxn];
int n;
int a[maxn][maxn]={},b[maxn][maxn]={};
int gause(mat a){
	int l=0,c=0;
	for(;c<n;l++,c++){
		int p=l;
		for(int i=l;i<n;i++) if(a[i][c]) p=i;
		swap(a[l],a[p]);
		if(a[l][c]==0) {l--;continue;}
		for(int i=0;i<n;i++) 
			if(i!=l&&a[i][c]) a[i]^=a[l];
	}
	return n-l;
}
mat t;
ll ans;
int main() {
	scanf("%d",&n);
	rep(i,0,n) rep(j,0,n) scanf("%d",&a[i][j]);
	rep(i,0,n) rep(j,0,n) scanf("%d",&b[i][j]);
	rep(col,0,n){
		rep(i,0,n) rep(j,0,n) t[i][j]=a[i][j];
		rep(i,0,n) if(b[i][col]) 
			t[i][i]=!t[i][i];
		ans+=gause(t);
	}
	ll out=1;
	while(ans--) out=out*2%mod;
	printf("%lld\n",out);
}