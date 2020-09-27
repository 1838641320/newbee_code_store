#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof a)
using ll=long long;
using namespace std;
const int maxn=1e5+9;
const double eps=1e-6;
mt19937 rd(time(0));
struct point{
	double x,y,r;
}p[3];
double cal(double x,double y){
	double d[3]={},res=0;
	rep(i,0,3) d[i]=hypot(x-p[i].x,y-p[i].y)/p[i].r;
	rep(i,0,3) res+=pow(d[i]-d[(i+1)%3],2);
	return res;
}
double mrd(){
	return 2.0*(rd()-0.5*rd.max())/rd.max();
}
int main() {
    rep(i,0,3) scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].r);
	double x=0,y=0;
	rep(i,0,3) x+=p[i].x/3,y+=p[i].y/3;
	double temper=5,ang=cal(x,y);
	while(temper>eps){
		double dx=x+temper*mrd(),
			dy=y+temper*mrd();
		double neang=cal(dx,dy);
		if(neang<ang) 
			x=dx,y=dy,ang=neang;
		temper*=0.999;
	}
	if(cal(x,y)<eps) printf("%lf %lf",x,y);
}