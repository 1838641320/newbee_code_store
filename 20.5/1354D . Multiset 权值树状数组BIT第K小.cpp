#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+9;
int bit[maxn]={},n,q;
void add(int i,int x) {
	while (i<=n)  bit[i]+=x,i+=i&-i; 
}
int sum(int i) {
	int res=0;
	while (i) res+=bit[i],i-=i&-i;
	return res;
}
int kth(int k) {
	int res=0,cnt=0;
	for (int d=log2(n);~d;d--) {
		res+=1<<d;
		if (res>n||cnt+bit[res]>=k)
			res-=1<<d;
		else
			cnt+=bit[res];
	}
	return res+1;
}
int main() {
	cin>>n>>q;
	for (int i=1,a;i<=n;i++) scanf("%d",&a),add(a,1);
	while(q--){
		int k;scanf("%d",&k);
		if (k>0) add(k,1);
		else add(kth(-k),-1);
	}
	int ans=kth(1);
	printf("%d\n",ans>n?0:ans);
}