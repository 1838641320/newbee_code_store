// #include<bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
pair<ll,ll> find_f(double x,double eps=1e-15){
	double delt=1e99,t;
	ll y=floor(x);
	x=fmod(x,1);
	ll lz=0,lm=1,rz=1,rm=1,midz,midm;
	pair<ll,ll> res;
	while(delt>eps){
		midz=lz+rz,midm=lm+rm;
		t=fabs(1.0*midz/midm-x);
		if(delt>t) res={midz,midm},delt=t;
		t=fabs(1.0*lz/lm-x);
		if(delt>t) res={lz,lm},delt=t;
		t=fabs(1.0*rz/rm-x);
		if(delt>t) res={rz,rm},delt=t;
		if(1.0*midz/midm>x) for(ll times=1;1.0*midz/midm>x;times*=2){
			rz=midz,rm=midm;
			midz+=times*lz;
			midm+=times*lm;
		}
		else for(ll times=1;1.0*midz/midm<x;times*=2){
			lz=midz,lm=midm;
			midz+=times*rz;
			midm+=times*rm;
		}
	}
	res.first+=y*res.second;
	return res;
}
int main(){
	double x,eps=1e-15;
	while(scanf("%lf",&x)>0){
		auto res=find_f(x,eps);
		printf("%lld/%lld\n",res.first,res.second);
	}
}