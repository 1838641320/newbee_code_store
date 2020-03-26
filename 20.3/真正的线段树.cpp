#include <cstdio>
typedef long long ll;
using namespace std;
ll n,m;
struct node {
	ll l,r,data;
	ll lz;
}tree[1000010];
ll arr[1000010];
void build(ll l,ll r,ll index,ll arr[]) {
	tree[index].lz = 0;
	tree[index].l = l;
	tree[index].r = r;
	if (l==r) {
		tree[index].data = arr[l];
		return;
	}
	ll mid = (l+r)/2;
	build(l,mid,index*2,arr);
	build(mid+1,r,index*2+1,arr);
	tree[index].data = tree[index*2].data+tree[index*2+1].data;
	return;
}
void push_down(ll index) {
	if (tree[index].lz!=0) {
		tree[index*2].lz += tree[index].lz;
		tree[index*2+1].lz += tree[index].lz;
		ll mid = (tree[index].l+tree[index].r)/2;
		tree[index*2].data += tree[index].lz*(mid-tree[index*2].l+1);
		tree[index*2+1].data += tree[index].lz*(tree[index*2+1].r-mid);
		tree[index].lz = 0;
	}
	return;
}
void up_data(ll index,ll l,ll r,ll k) {
	if (tree[index].r<=r&&tree[index].l>=l) {
		tree[index].data += k*(tree[index].r-tree[index].l+1);
		tree[index].lz += k;
		return;
	}
	push_down(index);
	if (tree[index*2].r>=l)
		up_data(index*2,l,r,k);
	if (tree[index*2+1].l<=r)
		up_data(index*2+1,l,r,k);
	tree[index].data = tree[index*2].data+tree[index*2+1].data;
	return;
}
ll search(ll index,ll l,ll r) {
	if (tree[index].l>=l&&tree[index].r<=r)
		return tree[index].data;
	push_down(index);
	ll num = 0;
	if (tree[index*2].r>=l)
		num += search(index*2,l,r);
	if (tree[index*2+1].l<=r)
		num += search(index*2+1,l,r);
	return num;
}
int main() {
	 build(1,1,n,arr); 
	 
}