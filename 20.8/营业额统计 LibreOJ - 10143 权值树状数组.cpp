#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+9;
int bi[maxn]={},base=maxn/2-1;
int lowbit(int x){return x&-x;}
void add(int x){
	while(x<maxn) bi[x]++,x+=lowbit(x);
}
int sum(int x){
	int res=0;
	while(x) res+=bi[x],x-=lowbit(x);
	return res;
}
int get(int x){
	int res=0;
	for(int i=log2(maxn);~i;i--){
		int t=res+(1<<i);
		if(t<maxn&&x>bi[t]) 
			res=t,x-=bi[t];
	}
	return res+1;
}
int main(){
	int n,x,ans,k;
	scanf("%d%d",&n,&ans);
	add(1),add(maxn-1),add(base+ans);
	while(--n){
		scanf("%d",&x);
		int p=sum(base+x);
		int lb=get(p),ub=get(p+1);
		if(ub==maxn-1) ub=1e9;
		if(lb==1) lb=-1e9;
		ans+=min(base+x-lb,ub-x-base);
		add(base+x);
	}
	printf("%d\n",ans);
}