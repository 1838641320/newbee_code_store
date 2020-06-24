#include<bits/stdc++.h>
#define mid (l+r)/2
using namespace std;
const int maxn=200000+9;
int N,M,L,R,D,tr[maxn*4];
char cmd[9];
void build(int in=1,int l=1,int r=N){
	if(l==r) return (void)scanf("%d",tr+in);
	build(in*2,l,mid);build(in*2+1,mid+1,r);
	tr[in]=max(tr[in*2],tr[in*2+1]);
}
void add(int in=1,int l=1,int r=N){
	if(l>R||r<L) return;
	if(l==L&&r==R) { tr[in]=D;return; }
	add(in*2,l,mid);add(in*2+1,mid+1,r);
	tr[in]=max(tr[in*2],tr[in*2+1]);
}
int query(int in=1,int l=1,int r=N){
	if(l>R||r<L) return 0;
	if(l>=L&&r<=R) return tr[in];
	return max(qurry(in*2,l,mid),qurry(in*2+1,mid+1,r));
}
int main(){
	while(~scanf("%d%d",&N,&M)){
		build();
		while(M--){
			int a,b;
			scanf("%s%d%d",cmd,&a,&b);
			if(cmd[0]=='Q') {
				L=a,R=b;
				printf("%d\n",qurry());
			}
			else {
				L=R=a,D=b;
				add();
			}
		}
	}
}