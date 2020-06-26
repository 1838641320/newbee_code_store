#include"s.h"
#include<bits/stdc++.h>
#define lch in*2
#define rch in*2+1
#define mid (l+r)/2
const int maxn=5e4+9;
using namespace std;
int tr[maxn*4],n,m,L,R,D,lz[maxn*4],f;
void build(int in=1,int l=1,int r=n){
	if(l==r) return void(tr[in]=1);
	build(lch,l,mid);build(rch,mid+1,r);
	tr[in]=tr[lch]+tr[rch];
}
void pushdown(int in=1,int l=1,int r=n){
	if(lz[in]==-1) return;
	int la=lz[in];
	lz[lch]=lz[rch]=la;
	tr[lch]=(mid-l+1)*la;
	tr[rch]=(r-mid)*la;
	lz[in]=-1;
}
void update(int in=1,int l=1,int r=n){
	if(l>R||r<L) return;
	if(L<=l&&R>=r) {
		tr[in]=D*(r-l+1);
		lz[in]=D;
		return;
	}
	pushdown(in,l,r);
	update(lch,l,mid);update(rch,mid+1,r);
	tr[in]=tr[lch]+tr[rch];
}
int query(int in=1,int l=1,int r=n){
	if(l>R||r<L) return 0;
	if(L<=l&&R>=r) return tr[in];
	pushdown(in,l,r);
	return query(lch,l,mid)+query(rch,mid+1,r);
}
int q2(int k,int in=1,int l=1,int r=n){
	if(l==r) return l;
	pushdown(in,l,r);
	if(tr[lch]>=k) return q2(k,lch,l,mid);
	else return q2(k-tr[lch],rch,mid+1,r);
}
void solve(){
	scanf("%d%d",&n,&m);
	build();memset(lz,-1,sizeof lz);
	while(m--){
		int ty;scanf("%d%d%d",&ty,&L,&R);
		L++,R++;
		if(ty==2) {
			D=1;
			printf("%d\n",R-L+1-query());
			update();
		}
		else {
			D=0;
			int t=R-1;
			R=L-1,L=1;
			int res1=query();
			R=n;
			int res2=query();
			if(res1==res2){ puts("Can not put any one.");continue; }
			int s=q2(res1+1),e=q2(res1+min(res2-res1,t));
			printf("%d %d\n",s-1,e-1);
			L=s,R=e;
			update();
		}
	}
}
int main(){
	int __;scanf("%d",&__);
	while(__--) solve(),puts("");
}