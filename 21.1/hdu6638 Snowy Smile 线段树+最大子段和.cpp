#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
const int maxn=2e3+9,inf=1e9+9;
int Ys[maxn],Xs[maxn];
struct piii{
	int x,y,w;
	bool operator<(piii&a){return x<a.x;}
}in[maxn]={};
ll sum[maxn*4],ls[maxn*4],rs[maxn*4],tot[maxn*4];
int tx,ty;
void build(int in=1,int l=1,int r=ty){
	sum[in]=ls[in]=rs[in]=tot[in]=0;
	if(l==r) return;
	int mid=l+r>>1;
	build(in<<1,l,mid),build(in<<1|1,mid+1,r);
}
void update(ll D,int pos,int in=1,int l=1,int r=ty){
	if(l==r) {
		ls[in]=rs[in]=tot[in]=sum[in]+=D;
		return;
	}
	int mid=l+r>>1,lch=in<<1,rch=lch|1;
	if(pos<=mid) update(D,pos,lch,l,mid);
	else update(D,pos,rch,mid+1,r);
	sum[in]=sum[lch]+sum[rch];
	ls[in]=max(ls[lch],sum[lch]+ls[rch]);
	rs[in]=max(rs[rch],sum[rch]+rs[lch]);
	tot[in]=max(max(tot[lch],tot[rch]),rs[lch]+ls[rch]);
}
int n;
void solve(){
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d%d",&in[i].x,&in[i].y,&in[i].w);
		Xs[i]=in[i].x;
		Ys[i]=in[i].y;
	}
	sort(Xs,Xs+n);
	sort(Ys,Ys+n);
	tx=unique(Xs,Xs+n)-Xs;
	ty=unique(Ys,Ys+n)-Ys;
	sort(in,in+n);
	rep(i,0,n) {
		in[i].x=lower_bound(Xs,Xs+tx,in[i].x)-Xs+1;
		in[i].y=lower_bound(Ys,Ys+ty,in[i].y)-Ys+1;
	}
	ll ans=0;
	for(int i=1;i<=tx;i++){
		int j=i,k=0;
		while(k<n&&in[k].x<j) k++;
		build();
		for(;j<=tx;j++){
			while(k<n&&in[k].x<=j) 
				update(in[k].w,in[k].y),k++;
			ans=max(ans,tot[1]);
		}
	}
	printf("%lld\n",ans);
	mem(Xs,0),mem(Ys,0);
}
int main(){
	int t;scanf("%d",&t);
	while(t--) solve();
}