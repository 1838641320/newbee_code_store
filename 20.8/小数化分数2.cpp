#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll,ll> find_f(double x,double eps=1e-15){
	double delt=1e99,t;
	ll y=floor(x),ts;
	x=fmod(x,1);
	if(fabs(x)<eps) return {y,1};
	ll lz=0,lm=1,rz=1,rm=1,mz,mm;
	pair<ll,ll> res;
	while(delt>eps){
		mz=lz+rz,mm=lm+rm;
		if(1.0*mz>mm*x){
			for(ts=1;1.0*(lz*ts+mz)>(lm*ts+mm)*x;ts*=2);
			for(;ts;ts/=2) if(1.0*(lz*ts+mz)>(lm*ts+mm)*x)
				mz+=lz*ts,mm+=lm*ts;
			rz=mz,rm=mm;
		}
		else {
			for(ts=1;1.0*(rz*ts+mz)<(rm*ts+mm)*x;ts*=2);
			for(;ts;ts/=2) if(1.0*(rz*ts+mz)<(rm*ts+mm)*x)
				mz+=rz*ts,mm+=rm*ts;
			lz=mz,lm=mm;
		}
		t=fabs(1.0*mz/mm-x);
		if(delt>t) res={mz,mm},delt=t;
	}
	res.first+=y*res.second;
	return res;
}
int main(){
	// freopen("2.txt","r",stdin);
	// freopen("3.txt","w",stdout);
	// auto start=clock();
	double x;
	while(~scanf("%lf",&x)){
		auto res=find_f(x);
		printf("%lld/%lld\n",res.first,res.second);
	}
	// fclose(stdout);
	// freopen("CON","w",stdout);
	// cout<<clock()-start<<endl;
}