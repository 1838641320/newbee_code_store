#include<bits/stdc++.h>
#define lch in*2
#define rch in*2+1
#define mid (l+r)/2
const int maxn=1e5+9;
typedef long long ll;
const ll mod=10007;
struct node { ll sum1,sum2,sum3,co,add,mul; }tr[maxn*4];
int n,m,L,R,D,ty,p;
void pushdown(int in,int l,int r){
	int len1=mid-l+1,len2=r-mid;
	auto &lc=tr[lch],&rc=tr[rch],&ro=tr[in];
	if(ro.co){
		ll d=ro.co;
		lc={len1*d%mod,len1*d*d%mod,len1*d*d*d%mod,d,0,1};
		rc={len2*d%mod,len2*d*d%mod,len2*d*d*d%mod,d,0,1};
	}
	if(ro.mul!=1){
		ll d=ro.mul;
		lc={lc.sum1*d%mod,lc.sum2*d*d%mod,lc.sum3*d*d*d%mod,lc.co,lc.add*d%mod,lc.mul*d%mod};
		rc={rc.sum1*d%mod,rc.sum2*d*d%mod,rc.sum3*d*d*d%mod,rc.co,rc.add*d%mod,rc.mul*d%mod};
	}
	if(ro.add){
		ll d=ro.add;
		lc.sum3=(lc.sum3+len1*d*d*d+3*lc.sum1*d*d+3*lc.sum2*d)%mod;
		lc.sum2=(lc.sum2+len1*d*d+2*lc.sum1*d)%mod;
		lc.sum1=(lc.sum1+len1*d)%mod;
		lc.add=(lc.add+d)%mod;
		rc.sum3=(rc.sum3+len2*d*d*d+3*rc.sum1*d*d+3*rc.sum2*d)%mod;
		rc.sum2=(rc.sum2+len2*d*d+2*rc.sum1*d)%mod;
		rc.sum1=(rc.sum1+len2*d)%mod;
		rc.add=(rc.add+d)%mod;
	}
	ro.co=0,ro.add=0,ro.mul=1;
}
void update(int in=1,int l=1,int r=n){
	if(l>R||r<L) return;
	ll len=r-l+1;
	if(L<=l&&R>=r){
		auto &p=tr[in];
		if(ty==1){
			p.sum3=(p.sum3+len*D*D*D+3*p.sum1*D*D+3*p.sum2*D)%mod;
			p.sum2=(p.sum2+len*D*D+2*p.sum1*D)%mod;
			p.sum1=(p.sum1+len*D)%mod;
			p.add=(p.add+D)%mod;
			return;
		}
		if(ty==2){
			p={p.sum1*D%mod,p.sum2*D*D%mod,p.sum3*D*D*D%mod,p.co,p.add*D%mod,p.mul*D%mod};
			return;
		}
		if(ty==3){
			p={len*D%mod,len*D*D%mod,len*D*D*D%mod,D,0,1};
			return;
		}
	}
	pushdown(in,l,r);
	update(lch,l,mid);update(rch,mid+1,r);
	auto &p=tr[in],&lc=tr[lch],&rc=tr[rch];
	p.sum1=(lc.sum1+rc.sum1)%mod;
	p.sum2=(lc.sum2+rc.sum2)%mod;
	p.sum3=(lc.sum3+rc.sum3)%mod;
}
ll query(int in=1,int l=1,int r=n){
	if(l>R||r<L) return 0;
	if(L<=l&&R>=r){
		if(p==1) return tr[in].sum1;
		if(p==2) return tr[in].sum2;
		if(p==3) return tr[in].sum3;
	}
	pushdown(in,l,r);
	return (query(lch,l,mid)+query(rch,mid+1,r))%mod;
}
int main(){
	while(scanf("%d%d",&n,&m),n||m){
		tr[0]={0,0,0,0,0,1};
		for(int i=0;i<4*n+5;i++) memcpy(tr+i,tr,48);
		while(m--){
			scanf("%d%d%d%d",&ty,&L,&R,&p);
			if(ty==4)
				printf("%lld\n",query());
			else
				D=p,update();
		}
	}
}