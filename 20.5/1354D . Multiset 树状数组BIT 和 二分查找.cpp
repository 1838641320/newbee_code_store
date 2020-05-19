#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+9;
int bit[maxn]={},n,q;
void add(int i,int x) {
	while (i<=n) bit[i]+=x,i+=i&-i; 
}
int sum(int i) {
	int res=0;
	while (i) res+=bit[i],i-=i&-i;
	return res;
}
int find(int k) {
	int lb=0,ub=n+1;
	while (ub-lb>1) {
		int mid=(ub+lb)/2;
		if (sum(mid)>=k) ub=mid;
		else lb=mid;
	}
	return ub;
}
int main() {
	cin>>n>>q;
	for (int i=1,a;i<=n;i++) scanf("%d",&a),add(a,1);
	while(q--){
		int k;scanf("%d",&k);
		if (k>0) add(k,1);
		else add(find(-k),-1);
	}
	int ans=find(1);
	printf("%d\n",ans>n?0:ans);
}