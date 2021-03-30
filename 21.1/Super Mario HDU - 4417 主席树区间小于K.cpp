#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
using namespace std;
const int maxn=1e5+9;
int tr[maxn*20],lc[maxn*20],rc[maxn*20],sz=0;
int T[maxn],a[maxn],n,q,b[maxn],bn;
#define mid (l+r>>1)
void build(int&ro,int l=1,int r=n){
	ro=++sz;tr[ro]=0;
	if(l==r) return ;
	build(lc[ro],l,mid),build(rc[ro],mid+1,r);
}
void update(int&ro,int P,int l=1,int r=n){
	tr[++sz]=tr[ro],lc[sz]=lc[ro],rc[sz]=rc[ro];
	tr[ro=sz]++;
	if(l==r) return ;
	if(P<=mid) update(lc[ro],P,l,mid);
	else update(rc[ro],P,mid+1,r);
}
int query(int ro,int P,int l=1,int r=n){
	if(l==r) return tr[ro];
	if(P<=mid) return query(lc[ro],P,l,mid);
	else return tr[lc[ro]]+query(rc[ro],P,mid+1,r);
}
int ___case=0;
void solve(){
	scanf("%d%d",&n,&q);
	int nt=n;
	rep(i,0,nt) scanf("%d",&a[i]),b[i]=a[i];
	b[n++]=1e9+7,b[n++]=-1;
	sort(b,b+n);
	n=unique(b,b+n)-b;
	build(T[0]);
	rep(i,0,nt) {
		T[i+1]=T[i];
		update(T[i+1],lower_bound(b,b+n,a[i])-b+1);
	}
	printf("Case %d:\n",++___case);
	rep(i,0,q){
		int x,y,h;
		scanf("%d%d%d",&x,&y,&h);
		int p=lower_bound(b,b+n,h)-b+1;
		if(b[p-1]!=h) p--;
		printf("%d\n",query(T[y+1],p)-query(T[x],p));
	}
}
int main(){
	int t;scanf("%d",&t);
	while(t--) solve();
}