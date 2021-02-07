#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
template<class ty>void read(ty&a){
    a=0;int f=0,c=getchar();
    for(;!isdigit(c);c=getchar()) f|=c=='-';
    for(;isdigit(c);c=getchar()) a=a*10+(c^48);
    if(f) a=-a;
}
template<class A,class ...B>void read(A&a,B&...b){read(a);read(b...);}
//---------------------------------------------
using namespace std;
const int maxn=2e5+9;
struct{int lc,rc,v;}tr[maxn*36]={};
#define mid (l+r>>1)
int n,m;
int a[maxn]={},T[maxn]={},pos[maxn];
int sz,x,d,L,R;
void update(int&ro,int l=1,int r=n){
    tr[++sz]=tr[ro];ro=sz;
    tr[ro].v+=d;
    if(l==r) return;
    if(x<=mid) update(tr[ro].lc,l,mid);
    else update(tr[ro].rc,mid+1,r);
}
int query(int ro,int l=1,int r=n){
    if(l>R||r<L) return 0;
    if(l>=L&&r<=R) return tr[ro].v;
    return query(tr[ro].lc,l,mid)+query(tr[ro].rc,mid+1,r);
}
int kth(int ro,int l=1,int r=n){
    if(l==r) return l;
    int tv=tr[tr[ro].lc].v;
    if(x<=tv) return kth(tr[ro].lc,l,mid);
    else return x-=tv,kth(tr[ro].rc,mid+1,r);
}
void solve(){
    sz=0;
    read(n,m);
    for(int i=1;i<=n;i++) read(a[i]);
    mem(T,0),mem(tr,0);mem(pos,-1);
    for(int i=n;i>0;i--){
        x=i;d=1;T[i]=T[i+1];
        update(T[i]);
        if(pos[a[i]]!=-1) {
            x=pos[a[i]];d=-1;
            update(T[i]);
        }
        pos[a[i]]=i;
    }
    int s,ans=0;
    while(m--){
        read(L,R);
        L=(L+ans)%n+1;R=(R+ans)%n+1;
        if(L>R) swap(L,R);
        s=query(T[L]);
        x=(s+1)/2;
        ans=kth(T[L]);
        printf(" %d",ans);
    }
    puts("");
}
int main(){
    int t;scanf("%d",&t);
    for(int i=1;i<=t;i++) 
        printf("Case #%d:",i),solve();
}