#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int mod=1e9+7;
typedef int mat[2][2];
typedef int vec[2];
void mul(mat a,mat b){//a=b*a
	mat c;
	rep(i,0,2) rep(j,0,2) 
		c[i][j]=((ll)a[i][0]*b[0][j]+(ll)a[i][1]*b[1][j])%mod;
	rep(i,0,2) rep(j,0,2) b[i][j]=c[i][j];
}
void mul(mat a,vec b){
	vec c;
	rep(i,0,2) c[i]=((ll)a[i][0]*b[0]+(ll)a[i][1]*b[1])%mod;
	b[0]=c[0],b[1]=c[1];
}
void add(vec a,vec b){(a[0]+=b[0])%=mod,(a[1]+=b[1])%=mod;}
mat id1={1,0,0,1},op2={3,2,3,mod-2},op3={0,1,1,0};
int n,a[maxn],b[maxn];
struct node{
	mat tag_m;vec tag_a;
	int a2,b2,ab,a,b;
}tr[maxn*8];
void pushup(int in){
	node&lch=tr[in<<1],&rch=tr[in<<1|1],&now=tr[in];
	(now.a2=lch.a2+rch.a2)%=mod;
	(now.b2=lch.b2+rch.b2)%=mod;
	(now.ab=lch.ab+rch.ab)%=mod;
	(now.a =lch.a +rch.a) %=mod;
	(now.b =lch.b +rch.b) %=mod;
}
void node_update(node&now,mat m,ll len){
	ll c11=m[0][0],c12=m[0][1],c21=m[1][0],c22=m[1][1];
	if(c11==1&&c22==1&&c21+c12==0) return;
	mul(m,now.tag_a);
	mul(m,now.tag_m);
	ll a2=now.a2,b2=now.b2,ab=now.ab,a=now.a,b=now.b;
	now.a2=((c11*c11%mod)*a2+2ull*(c11*c12%mod)*ab+(c12*c12%mod)*b2)%mod;
	now.b2=((c21*c21%mod)*a2+2ull*(c21*c22%mod)*ab+(c22*c22%mod)*b2)%mod;
	now.ab=((c11*c21%mod)*a2+(c11*c22%mod+c12*c21%mod)*ab+(c12*c22%mod)*b2)%mod;
	now.a =(a*c11+b*c12)%mod;
	now.b =(a*c21+b*c22)%mod;
}
void node_update(node&now,vec v,ll len){
	ll d1=v[0],d2=v[1];
	if(d1+d2==0) return;
	now.a2=(now.a2+(2*d1*now.a+len*(d1*d1%mod)))%mod;
	now.b2=(now.b2+(2*d2*now.b+len*(d2*d2%mod)))%mod;
	now.ab=(now.ab+(d2*now.a+d1*now.b+d1*d2%mod*len))%mod;
	now.a=(now.a+d1*len)%mod;
	now.b=(now.b+d2*len)%mod;
	add(now.tag_a,v);
}
void pushdown(int in,int l,int r){
	node&lch=tr[in<<1],&rch=tr[in<<1|1];
	int mid=((l+r)>>1),llen=mid-l+1,rlen=r-mid;
	node_update(lch,tr[in].tag_m,llen);
	node_update(rch,tr[in].tag_m,rlen);
	memcpy(tr[in].tag_m,id1,sizeof(id1));
	node_update(lch,tr[in].tag_a,llen);
	node_update(rch,tr[in].tag_a,rlen);
	tr[in].tag_a[0]=tr[in].tag_a[1]=0;
}
void build(int in=1,int l=1,int r=n){
	tr[in].tag_m[0][0]=tr[in].tag_m[1][1]=1;
	if(l==r){
		tr[in].a=a[l],tr[in].b=b[l];
		tr[in].a2=(ll)a[l]*a[l]%mod;
		tr[in].b2=(ll)b[l]*b[l]%mod;
		tr[in].ab=(ll)a[l]*b[l]%mod;
		return;
	}
	int mid=((l+r)>>1);
	build(in<<1,l,mid),build(in<<1|1,mid+1,r);
	pushup(in);
}
template<class T>
void update(T op,int L,int R,int in=1,int l=1,int r=n){
	if(L<=l&&R>=r) return node_update(tr[in],op,r-l+1);
	pushdown(in,l,r);
	int mid=((l+r)>>1);
	if(L<=mid) update(op,L,R,in<<1,l,mid);
	if(R>mid) update(op,L,R,in<<1|1,mid+1,r);
	pushup(in);
}
int query(int L,int R,int in=1,int l=1,int r=n){
	if(L<=l&&R>=r) return tr[in].ab;
	pushdown(in,l,r);
	int ret=0,mid=((l+r)>>1);
	if(L<=mid) ret+=query(L,R,in<<1,l,mid);
	if(R>mid) ret+=query(L,R,in<<1|1,mid+1,r);
	return ret%mod;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	build();
	int q,tag,l,r,v,op;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d%d%d",&tag,&l,&r,&v);
			vec ve={(1-tag)*v,tag*v};
			update(ve,l,r);
			continue;
		}
		scanf("%d%d",&l,&r);
		if(op==2) update(op2,l,r);
		else if(op==3) update(op3,l,r);
		else if(op==4) printf("%u\n",query(l,r));
	}
}