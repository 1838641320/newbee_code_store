#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
const int mod=10007,maxn=309;
double R;
struct P{ int x,y; }p[maxn];
int mat[maxn][maxn],n;
ll qpow(ll x,ll n){
	ll c=1;
	for(x%=mod;n;n/=2,x=x*x%mod) if(n&1) c=c*x%mod;
	return c;
}
ll det(int n,int a[maxn][maxn]){
	ll res=1;
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[j][i]==0) continue;
			ll t=a[i][i]*qpow(a[j][i],mod-2)%mod;
			for(k=i;k<n;k++) a[i][k]=((a[i][k]-t*a[j][k]%mod)+mod)%mod;
			swap(a[i],a[j]);
			res=mod-res;
		}
		res=(res*a[i][i])%mod;
	}
	return (res+mod)%mod;
}
bool coline(P &a,P &b,P &c){
	int x1=b.x-a.x,x2=c.x-a.x;
	int y1=b.y-a.y,y2=c.y-a.y;
	return x1*y2==x2*y1&&(x2*x2+y2*y2)<(x1*x1+y1*y1);
}
int solve(){
	memset(mat,0,sizeof mat);
	scanf("%d%lf",&n,&R);
	rep(i,0,n) scanf("%d%d",&p[i].x,&p[i].y);
	rep(i,0,n) rep(j,0,n){
		if(i==j||hypot(p[i].x-p[j].x,p[i].y-p[j].y)>R) continue;
		int k=0;
		for(;k<n;k++) if(i!=k&&j!=k&&coline(p[i],p[j],p[k])) break;
		if(k==n) mat[i][i]++,mat[i][j]--;
	}
	int res=det(n-1,mat);
	return res?res:-1;
}
int main(){
	int t;scanf("%d",&t);
	while(t--) printf("%d\n",solve());
}