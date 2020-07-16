#include"s.h"
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=2009;
typedef pair<double,double> pdd;
vector<pdd> vec;
double cal(double x,double y){
	double sum=0;
	for(auto i:vec) sum+=hypot(i.first-x,i.second-y);
	return sum;
}
double randd(){
	return ((double)rand()/RAND_MAX)*2-1;
}
pdd solve(){
	double t=100,x=0,y=0,d=cal(x,y);
	while(t>0.001){
		double dx=x+t*randd(),dy=y+t*randd();
		double d2=cal(dx,dy);
		if(d2<d)
			d=d2,x=dx,y=dy,printf("(%lf,%lf),\n",x,y,d);
		t*=0.97;
	}
	return {x,y};
}
int main() {
	srand(time(0));
	int n;scanf("%d",&n);
	rep(i,0,n) {
		double x,y;
		scanf("%lf%lf",&x,&y);
		vec.push_back({x,y});
	}
	putchar('{');
	auto ans=solve();
	putchar('}');
	//printf("(%lf,%lf)\n",ans.first,ans.second);
}