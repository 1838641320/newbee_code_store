#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
namespace SimulateAnneal{

	mt19937 rd(time(0));
	double precision=0.001,init_temp=1000,speed=0.97;
	double (*cal)(vector<double> &a);
	void init(double (*cal_)(vector<double> &a),double a=precision,double b=init_temp,double c=speed){
		cal=cal_;
		precision=a;
		init_temp=b;
		speed=c;
	}
	double rdd(){
		return 1.0*rd()/rd.max();
	}
	vector<double> solve(vector<double> a){
		vector<double> b,ans=a;
		double ansv=cal(a);
		for(double t=init_temp;t>precision;t*=speed){
			b=a;
			for(auto &i:b) i+=t*(rdd()*2.0-1.0);
			double d=cal(b),expe=1.0*((ansv-d)/t*1.0);
			if(expe>rdd())
				a=b;
			if(d<ansv) 
				ans=b,ansv=d;
		}
		return ans;
	}

}
double cal(vector<double> &a){
	double sum=0;
	double x=a[0],y=a[1];
	sum=exp(3*x)*(x+y*y+2*y);
	return sum;
}
int main(){
	SimulateAnneal::init(cal,0.000001,100,0.98);
	auto res=SimulateAnneal::solve({0,0});
	for(auto i:res) printf("%lf ",i);
	printf("\n%lf\n",cal(res));
}