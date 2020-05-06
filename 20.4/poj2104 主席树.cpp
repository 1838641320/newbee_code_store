#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+9;
int sum[32*maxn],lc[32*maxn],rc[32*maxn];
int a[maxn],b[maxn],T[maxn],n,q,m,nodecnt;
void build(int &rt,int l,int r) {
	rt=++nodecnt;sum[rt]=0;
	if (l==r) return;
	int mid=(l+r)/2;
	build(lc[rt],l,mid);build(rc[rt],mid+1,r);
}
int update(int pre,int x,int val,int l,int r) {
	int rt=++nodecnt,mid=(l+r)/2;
	lc[rt]=lc[pre],rc[rt]=rc[pre],sum[rt]=sum[pre]+val;
	if (l==r) return rt;
	if (x<=mid) lc[rt]=update(lc[pre],x,val,l,mid);
	else		rc[rt]=update(rc[pre],x,val,mid+1,r);
	return rt;
}
int qurry(int lr,int rr,int x,int l,int r) {
	if (l==r) return l;
	int mid=(l+r)/2,k=sum[lc[rr]]-sum[lc[lr]];
	if (x<=k) return qurry(lc[lr],lc[rr],x,l,mid);
	else	return qurry(rc[lr],rc[rr],x-k,mid+1,r);
}
void init() {
	memset(sum,0,4*(n+8));memset(lc,0,4*(n+8));memset(rc,0,4*(n+8));
	memcpy(b,a,4*(n+8));
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-b-1;
	build(T[0],1,m);
}
void solve() {
	cin>>n>>q;
	nodecnt=0;
	for (int i=1;i<=n;i++) scanf("%d",a+i);
	init();
	for (int i=1;i<=n;i++) {
		int th=lower_bound(b+1,b+n+1,a[i])-b;
		T[i]=update(T[i-1],th,1,1,m);
	}
	while (q--) {
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		int jj=qurry(T[x-1],T[y],z,1,m);
		printf("%d\n",b[jj]);
	}
}
int main() {
	solve();
}