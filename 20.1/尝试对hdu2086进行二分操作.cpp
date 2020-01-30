#include<cstdio>
#include<cstring>
#include<algorithm>
constexpr int maxn=3006;
double a0,an1,c[maxn];
int n,i;
int cmp(double an){
	double pre=a0,next;
	for(i=1;i<=n;i++){
		next=2*an+2*c[i]-pre;
		pre=an;
		an=next;
	}
	return next>=an1;
}
double b_search(){
	double lb=-1e13,ub=1e13,mid;
	while(ub>0.0001+lb){
		mid=(lb+ub)/2;
		if(cmp(mid)) ub=mid;
		else lb=mid;
	}
	return (lb+ub)/2;
}
int main(){

	while(~scanf("%d",&n)){
		scanf("%lf%lf",&a0,&an1);
		memset(c,0,3006*8);
		for(i=1;i<=n;i++) scanf("%lf",&c[i]);
		printf("%.2lf\n",b_search());
	}
}

