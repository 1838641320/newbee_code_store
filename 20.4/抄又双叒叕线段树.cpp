#include"pch.h"
#include<bits/stdc++.h>
using namespace std;
class Segment_Tree {
public:
	vector<int> tree,lz;
	void init(int n) {
		tree.resize(2*n+9);
		lz.resize(2*n+9);
	}
	void build(int in,int l,int r) {
		if (l==r) { scanf("%d",&tree[in]);return;}
		int mid=(l+r)/2;
		build(in*2,l,mid);build(in*2+1,mid+1,r);
		tree[in]=max(tree[in*2],tree[in*2+1]);
	}
	void pushdown(int in) {
		if (lz[in]==0) return;
		int la=lz[in];lz[in]=0;
		tree[in*2]+=la;tree[in*2+1]+=la;
		lz[in*2]+=la;lz[in*2+1]+=la;
	}
	void add(int in,int l,int r,int L,int R,int val) {
		if (L>r||R<l) return;
		if (L<=l&&R>=r) { tree[in]+=val,lz[in]+=val;return; }
		pushdown(in);
		int mid=(l+r)/2;
		add(in*2,l,mid,L,R,val);add(in*2+1,mid+1,r,L,R,val);
		tree[in]=max(tree[in*2],tree[in*2+1]);
	}
	int qurry(int in,int l,int r,int L,int R) {
		if (L>r||R<l) return INT_MIN;
		if (L<=l&&R>=r) return tree[in];
		pushdown(in);
		int mid=(l+r)/2;
		return max(qurry(in*2,l,mid,L,R),qurry(in*2+1,mid+1,r,L,R));
	}
};
Segment_Tree tt;
int main() {
	int n;
	scanf("%d",&n);
	tt.init(n);
	tt.build(1,1,n);
	for (int i=1;i<=n;i++) cout<<tt.qurry(1,1,n,i,i)<<' ';
	puts("");
	for (int i=1;i<=n-1;i++) cout<<tt.qurry(1,1,n,i,i+1)<<' ';
	puts("");
	for (int i=1;i<=n-3;i++) cout<<tt.qurry(1,1,n,i,i+3)<<' ';
	puts("");
	cout<<tt.qurry(1,1,n,1,n);
}