#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
typedef long long ll;
template<typename T>
void read(T&a){
	a=0;int c=getchar(),f=0;
	for(;!isdigit(c);c=getchar()) f|=c=='-';
	for(;isdigit(c);c=getchar()) a=a*10+c-'0';
	if(f) a=-a;
}
pair<ll,ll> find_f(double x,double eps=1e-10){
	double delt=1e99;
	ll lz=0,lm=1,rz=1,rm=1;
	pair<ll,ll> res;
	while(delt>eps){
		ll midz=lz+rz,midm=lm+rm;
		double t=1.0*midz/midm-x;
		if(fabs(t)<delt) res={midz,midm},delt=fabs(t);
		if(t>0) rz=midz,rm=midm;
		else lz=midz,lm=midm;
	}
	return res;
}
int main(){
	double x,eps=1e-10;
	while(scanf("%lf%lf",&x,&eps)>0){
		auto res=find_f(x,eps);
		printf("%lld/%lld\n",res.first,res.second);
	}
}