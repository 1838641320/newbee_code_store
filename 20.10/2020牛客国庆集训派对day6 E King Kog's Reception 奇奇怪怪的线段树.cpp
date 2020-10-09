#include<bits/stdc++.h>
// #include<cstdio>
// #include<cstring>
// #include<cstdlib>
#define rep(i,a,b) for(int i=a,bb=b;i<bb;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
ll gcd(ll x,ll y){while(y^=x^=y^=x%=y);return x;}
using namespace std;
//-----------------
#define lch in*2
#define rch in*2+1
#define mid (l+r)/2
const int maxn=1e6+9;
ll ap[maxn*4]={},ed[maxn*4];
int n=1e6,L,R,D;
void pushup(int in){
	ap[in]=ap[lch]+ap[rch];
	ed[in]=max(ed[lch]+ap[rch],ed[rch]);
}
void build(int in=1,int l=1,int r=n){
	if(l==r) {ed[in]=l;return;}
	build(lch,l,mid),build(rch,mid+1,r);
	pushup(in);
}
void update(int in=1,int l=1,int r=n){
	if(r<L||l>R) return;
	if(l==L&&r==R) {
		ap[in]+=D;ed[in]+=D;
		return;
	}
	update(lch,l,mid),update(rch,mid+1,r);
	pushup(in);
}
ll ans;
void query(int in=1,int l=1,int r=n){
	if(r<L||l>R) return;
	if(l>=L&&r<=R) {
		ans=max(ans+ap[in],ed[in]);
		return;
	}
	query(lch,l,mid),query(rch,mid+1,r);
}
int t[maxn],d[maxn],x;
int main(){
	int q;scanf("%d",&q);
	build();
	char op[4]={};
	rep(i,1,q+1){
		scanf("%s",op);
		if(op[0]=='+'){
			scanf("%d%d",t+i,d+i);
			L=R=t[i],D=d[i];
			update();
		}
		if(op[0]=='-'){
			scanf("%d",&x);
			L=R=t[x],D=-d[x];
			update();
		}
		if(op[0]=='?'){
			scanf("%d",&x);
			L=1,R=x;ans=0;
			query();
			printf("%lld\n",ans-x);
		}
	}
}