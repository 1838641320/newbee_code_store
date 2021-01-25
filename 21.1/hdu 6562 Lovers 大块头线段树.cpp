#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define mem(a,b) memset(a,b,sizeof a)
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
using namespace std;
const int maxn=1e5+9;
const ll mod=1e9+7;
struct node{
    ll sum,len,s10,adl,dle,dri;
}tr[4*maxn];
#define lch in*2
#define rch in*2+1
int L,R,D,n,q;
void pushdown(node &t,ll up,ll lo,ll adl){
    t.s10=t.s10*adl%mod;
    t.sum=(t.sum*adl+t.s10*up+t.len*lo)%mod;
    t.dle=(t.dle*adl+lo)%mod;
    t.dri=(t.adl*up+t.dri)%mod;
    t.s10=t.s10*adl%mod;
    t.adl=t.adl*adl%mod;
}
void pushdown(int in,int l,int r){
    if(tr[in].adl==1) return;
    pushdown(tr[lch],tr[in].dri,tr[in].dle,tr[in].adl);
    pushdown(tr[rch],tr[in].dri,tr[in].dle,tr[in].adl);
    tr[in].adl=1;
    tr[in].dle=tr[in].dri=0;
}
void pushup(int in){
    tr[in].sum=(tr[lch].sum+tr[rch].sum)%mod;
    tr[in].s10=(tr[lch].s10+tr[rch].s10)%mod;
}
void build(int in=1,int l=1,int r=n){
    if(l==r) return void(tr[in]={0,1,1,1,0,0});
    int mid=l+r>>1;
    build(lch,l,mid),build(rch,mid+1,r);
    tr[in].adl=1;tr[in].sum=tr[in].dle=tr[in].dri=0;
    tr[in].len=r-l+1;
    tr[in].s10=(tr[lch].s10+tr[rch].s10)%mod;
}
void update(int in=1,int l=1,int r=n){
    if(l>R||r<L) return;
    if(l>=L&&r<=R) return pushdown(tr[in],D,D,10);
    pushdown(in,l,r);
    int mid=l+r>>1;
    update(lch,l,mid),update(rch,mid+1,r);
    pushup(in);
}
ll query(int in=1,int l=1,int r=n){
    if(l>R||r<L) return 0;
    if(l>=L&&r<=R) return tr[in].sum%mod;
    pushdown(in,l,r);
    int mid=l+r>>1;
    return (query(lch,l,mid)+query(rch,mid+1,r))%mod;
}
char s[9]={};
void solve(){
    scanf("%d%d",&n,&q);
    build();
    while(q--){
        scanf("%s%d%d",s,&L,&R);
        if(s[0]=='w') scanf("%d",&D),update();
        else printf("%lld\n",query());
    }
}
int main(){
    int t;scanf("%d",&t);
    rep(i,1,t+1) printf("Case %d:\n",i),solve();
}