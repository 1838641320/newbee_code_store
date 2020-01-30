#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<algorithm>
constexpr int maxn=666;
int a[maxn]={0},i;
int b_search(int a[],int n,int key){
	int lb=-1,ub=n,mid;
	while(ub>1+lb){
		mid=(lb+ub)/2;
		if(a[mid]>=key) ub=mid;
		else lb=mid;
	}
	return ub;
}
int bsearch2(int a[],int start,int end,int key){
	int mid=(start+end)/2;
	if(start+1>=end) return end;
	if(a[mid]>=key) return bsearch2(a,start,mid,key);
	return bsearch2(a,mid,end,key);
}
int main(){
	int key;
	srand(time(0));
	for(i=0;i<maxn;i++) a[i]=rand();
	std::sort(a,a+maxn);
	//for(i=0;i<maxn;i++) printf("%d ",a[i]);
	while(~scanf("%d",&key)) printf("%d %d\n",a[b_search(a,maxn,key)],a[bsearch2(a,0,maxn,key)]);
}