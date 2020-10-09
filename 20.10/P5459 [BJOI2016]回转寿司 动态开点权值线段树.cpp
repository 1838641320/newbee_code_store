// #include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
ll gcd(ll x,ll y){while(y^=x^=y^=x%=y);return x;}
using namespace std;
//-----------------
#define mid (l+r>>1)
#define lch tr[in].l
#define rch tr[in].r
const int maxn=1e5+9;
const ll inf=1e10;
int cnt=1;
struct {
	int v,l,r;
}tr[maxn*40];
void insert(int &in, ll val,ll l=-inf, ll r=inf){
	if(!in) in=cnt++;
	tr[in].v++;
	if(l==r) return;
	if(mid>=val) insert(lch,val,l,mid);
	else insert(rch,val,mid+1,r);
}
ll query(int in, ll L, ll R,ll l=-inf, ll r=inf){
	if(!in) return 0;
	if(l>=L&&r<=R) return tr[in].v;
	ll ret=0;
	if(mid>=L) ret+=query(lch,L,R,l,mid);
	if(mid<R) ret+=query(rch,L,R,mid+1,r);
	return ret;
}
int n,l,r;
ll s[maxn];
int main(){
	scanf("%d%d%d", &n, &l, &r);
	for(int i=1; i<=n;i++){
		scanf("%lld",s+i);
		s[i]+=s[i-1];
	}
	ll res=0;
	int root=1;
	insert(root,0);
	for(int i=1; i<=n;i++){
		res+=query(root,s[i]-r,s[i]-l);
		insert(root,s[i]);
	}
	printf("%lld\n", res);
}