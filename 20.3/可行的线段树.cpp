#include<cstdio>
#ifdef segmenttree
struct segTr {
	int s,dat[1<<18];
} sgt;
void init(int _n) {
	sgt.s = 1;
	while (sgt.s<_n) sgt.s *= 2;
}
void update(int i,int x) {
	i += sgt.s-1;
	sgt.dat[i] = x;
	while (i>0) {
		i = (i-1)/2;
		sgt.dat[i] = sgt.dat[2*i+1]+sgt.dat[2*i+2];
	}
}
int sum(int a,int b,int k,int l,int r) {
	if (a>=r||b<=l) return 0;
	if (l>=a&&r<=b) return sgt.dat[k];
	return sum(a,b,k*2+1,l,(l+r)/2)+sum(a,b,k*2+2,(l+r)/2,r);
}
#endif
#ifndef segmenttree
int bit[(int)1e5+8] = {0},n;
int sum(int i) {
	int s = 0;
	while (i>0) {
		s += bit[i];
		i -= i&-i;
	}
	return s;
}
void add(int i,int x) {
	while (i<=n) {
		bit[i] += x;
		i += i&-i;
	}
}
#endif
int main() {
#ifdef segmenttree
	int ll,rr;
	sgt.s = 15;
	int n = sgt.s;
	init(sgt.s);
	for (int i = 1;i<=n;i++) update(i,2*i);
	while (~scanf("%d%d",&ll,&rr)) printf("%d\n",sum(ll,rr,0,0,s));
#endif
#ifndef segmenttree
	int ll,rr;
	n = 15;
	for (int i = 1;i<=n;i++) add(i,2*i);
	while (~scanf("%d%d",&ll,&rr)) printf("%d\n",sum(rr)-sum(ll));
#endif
}