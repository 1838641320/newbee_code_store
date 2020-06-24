#include"s.h"
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=100000+9;
int N,M,L,R,D;
char cmd[9];
ll tr[maxn*4]={},lz[maxn*4]={};
void build(int in=1,int l=1,int r=N){
	if(l==r) return(void)scanf("%lld",tr+in);
	int mid=(l+r)/2;
	build(in*2,l,mid),build(in*2+1,mid+1,r);
	tr[in]=tr[in*2]+tr[in*2+1];
}
void pushdown(int in=1,int l=1,int r=N){
	if(lz[in]==0) return;
	ll la=lz[in],mid=(l+r)/2;
	lz[in]=0;
	lz[in*2]+=la;
	lz[in*2+1]+=la;
	tr[in*2]+=la*(mid-l+1);
	tr[in*2+1]+=la*(r-mid);
}
void add(int in=1,int l=1,int r=N){
	if(L>r||R<l) return;
	if(L<=l&&R>=r){
		tr[in]+=D*(r-l+1);
		lz[in]+=D;
		return;
	}
	int mid=(l+r)/2;
	pushdown(in,l,r);
	add(in*2,l,mid),add(in*2+1,mid+1,r);
	tr[in]=tr[in*2]+tr[in*2+1];
}
ll query(int in=1,int l=1,int r=N){
	if(L>r||R<l) return 0;
	if(L<=l&&R>=r) return tr[in];
	pushdown(in,l,r);
	int mid=(l+r)/2;
	return qurry(in*2,l,mid)+qurry(in*2+1,mid+1,r);
}
int main(){
	scanf("%d%d",&N,&M);
	build();
	while(M--){
		scanf("%s",cmd);
		if(cmd[0]=='Q'){
			scanf("%d%d",&L,&R);
			printf("%lld\n",qurry());
		}
		else{
			scanf("%d%d%d",&L,&R,&D);
			add();
		}
	}
}