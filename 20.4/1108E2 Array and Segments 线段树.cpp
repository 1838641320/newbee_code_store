#include"pch.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e5+9;
int n,m,tree[4*maxn]={},lazy[4*maxn]={};
void build(int in,int l,int r) {
	if (l==r) { scanf("%d",tree+in);return; }
	int mid=(l+r)/2;
	build(2*in,l,mid);build(2*in+1,mid+1,r);
	tree[in]=max(tree[2*in],tree[2*in+1]);
}
void push_down(int in) {
	if (lazy[in]==0) return;
	int lz=lazy[in];
	tree[2*in]+=lz;tree[2*in+1]+=lz;
	lazy[2*in]+=lz;lazy[2*in+1]+=lz;
	lazy[in]=0;
}
void add(int in,int l,int r,int L,int R,int val) {
	if (L>r||R<l) return;
	if (L<=l&&R>=r) { tree[in]+=val;lazy[in]+=val;return; }
	push_down(in);
	int mid=(l+r)/2;
	add(2*in,l,mid,L,R,val);add(2*in+1,mid+1,r,L,R,val);
	tree[in]=max(tree[2*in],tree[2*in+1]);
}
int qurry(int in,int l,int r,int L,int R) {
	if (L>r||R<l) return INT_MIN;
	if (L<=l&&R>=r) return tree[in];
	push_down(in);
	int mid=(l+r)/2;
	return max(qurry(in*2,l,mid,L,R),qurry(in*2+1,mid+1,r,L,R));
}
set<int> q,ans;
vector<pii> L[maxn],R[maxn];
int maxval;
int main() {
	cin>>n>>m;
	build(1,1,n);
	for (int i=1;i<=m;i++) {
		int l,r;
		scanf("%d%d",&l,&r);
		L[l].push_back({r,i});R[r].push_back({l,i});
	}
	for (int i=1;i<=n;i++) {
		for (int j=0;j<L[i].size();j++) {
			add(1,1,n,i,L[i][j].first,-1);
			q.insert(L[i][j].second);
		}
		int ttt=tree[1]-qurry(1,1,n,i,i);
		if (ttt>maxval) {
			maxval=ttt;
			ans=q;
		}
		for (int j=0;j<R[i].size();j++) {
			add(1,1,n,R[i][j].first,i,1);
			q.erase(R[i][j].second);
		}
	}
	printf("%d\n%d\n",maxval,ans.size());
	for (int i:ans) printf("%d ",i);
}