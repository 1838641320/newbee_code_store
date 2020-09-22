#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
int getgs(ll x,ll y){
	x|=y;
	int res=0;
	while(x&(1ll<<res)) 
		res++;
	return res;
}
int main() {
	int t;scanf("%d",&t);
	while(t--){
		int n,res=0,x,y;
		scanf("%d",&n);
		n/=2;
		rep(i,0,n) {
			scanf("%d%d",&x,&y);
			res^=getgs(x-1,y-1);
		}
		puts(res?"YES":"NO");
	}
}

// set<int> se[999]={};
// int getgs(int x,int y){
// 	set<int> se1;
// 	for(int i:se[x]) se1.insert(i);
// 	for(int i:se[y]) se1.insert(i);
// 	int res=0;
// 	while(se1.count(res)) res++;
// 	se[x+y].insert(res);
// 	return res;
// }
// int main() {
// 	se[2].insert(0);
// 	for(int i=2;i<50;printf("%d:  \n",i++)) for(int j=1;j*2<=i;j++) 
// 		printf("(%d,%d) : %d\n",j,i-j,getgs(i-j,j));
// 	for(int i=2;i<50;i++) {
// 		printf("%d:  ",i);
// 		for(int j:se[i]) printf("%d ",j);
// 		puts("");
// 	}
// }