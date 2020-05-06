#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 200010;
int n, q, m, cnt = 0;
int a[N], b[N], T[N];
int sum[N*32], L[N*32], R[N*32];
int build(int l, int r){
	rt = ++cnt;
	sum[rt] = 0;
	if(l==r) return rt;
	int mid=(l+r)/2;
	L[rt]=build(l, mid),R[rt]=build(mid+1, r);
	return rt;
}
int update(int pre, int x,int val,int l=1,int r=m){
	int rt = ++cnt;
	L[rt]=L[pre];R[rt]=R[pre];sum[rt]=sum[pre]+val;
	if(l==r) return rt;
	int mid=(l+r)/2;
	if (x<=mid) L[rt]=update(L[pre],x,val,l,mid);
	else 		R[rt]=update(R[pre],x,val,mid+1,r);
	return rt;
}
int query(int u, int v, int x, int l=1, int r=m){
	if (l==r) return l;
	int k=sum[L[v]]-sum[L[u]],mid=(l+r)/2;
	if (x<=k) return query(L[u],L[v],k,l,mid);
	else 	return query(R[u],R[v],x-k,mid+1,r);
}
void init_hash(){
	for(int i=1;i<=m;i++) b[i] = a[i];
	sort(b+1, b+1+n);
	m=unique(b+1, b+1+n)-b-1;
}
int main(){
	scanf("%d%d", &n, &q);
	for (int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	T[0]=build(1, m);
	for (int i=1;i<=n;i++){
		int t = lower_bound(b+1, b+1+m, a[i])-b;
		T[i] = update(T[i-1],t,1);
	}
	while (q--){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		int t = query(T[x-1], T[y], z);
		printf("%d\n", b[t]);
	}
	return 0;
}