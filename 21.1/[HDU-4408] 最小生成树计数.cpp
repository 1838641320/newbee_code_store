#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
template<class A>void read(A&a){
	a=0;int c=getchar(),f=0;
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+(c^48);
	if(f) a=-a;
}
template<class A,class ...B>
void read(A&a,B&...b){read(a);read(b...);}
using namespace std;
typedef long long ll;
const int maxn=1e2+9;
int n,m;
ll p;
int pa1[maxn],pa2[maxn];
int findp(int pa[],int x){return pa[x]==x?x:pa[x]=findp(pa,pa[x]);}
ll det(ll a[maxn][maxn],int n){
	ll res=1;
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++)while(a[j][i]){
			ll t=a[i][i]/a[j][i];
			for(k=i;k<n;k++)
				a[i][k]=(a[i][k]-t*a[j][k])%p;
			swap(a[i],a[j]);
			res=p-res;
		}
		res=res*(a[i][i]%p+p)%p;
	}
	return res;
}
struct edge{int u,v,w;}e[maxn*10];
ll k[maxn][maxn];
void solve(){
	for(int i=1;i<=n;i++) pa2[i]=i;
	rep(i,0,m)
		read(e[i].u,e[i].v,e[i].w);
	sort(e,e+m,[](edge&a,edge&b){return a.w<b.w;});
	int ii=0,ip=0;
	ll ans=1;
	for(;ii<=m;ii++) if(e[ii].w!=e[ip].w){
		for(int i=0;i<n;i++) pa1[i]=i;
		rep(i,0,n) rep(j,0,n) k[i][j]=0;
		for(int i=ip;i<ii;i++){
			int v=findp(pa2,e[i].v),u=findp(pa2,e[i].u);
			if(u==v) continue;
			v--,u--;
			k[v][v]++,k[u][u]++;
			k[u][v]--,k[v][u]--;
			pa1[findp(pa1,u)]=pa1[findp(pa1,v)];
		}
		for(int i=1;i<n;i++){
			int v=findp(pa1,i),u=findp(pa1,i-1);
			if(v==u) continue;
			k[v][v]++,k[u][u]++;
			k[u][v]--,k[v][u]--;
			pa1[v]=pa1[u];
		}
		for(int i=ip;i<ii;i++){
			pa2[findp(pa2,e[i].v)]=findp(pa2,e[i].u);
		}
		ans=(ans*det(k,n-1))%p;
		ip=ii;
	}
	for(int i=1;i<=n;i++) if(findp(pa2,i)!=findp(pa2,1)) {
		puts("0");return;
	}
	printf("%lld\n",ans%p);
	mem(e,0);
}
int main(){
	while(read(n,m,p),n|p|m) solve();
}