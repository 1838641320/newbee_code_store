#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
using namespace std;
struct P{double x,y;};
P operator+(P a,P b){return {a.x+b.x,a.y+b.y};};
P operator-(P a,P b){return {a.x-b.x,a.y-b.y};};
double operator*(P a,P b){return a.x*b.x+a.y*b.y;};
double operator^(P a,P b){return a.x*b.y-a.y*b.x;}

P operator*(P a,double b){return {a.x*b,a.y*b};}
double poly_circle(P c,double r,vector<P>&poly){
	#define len2(a) (a.x*a.x+a.y*a.y)//圆和多边形相交面积
	#define tan(a,b) atan2(a^b,a*b)
	auto tri=[=](P p,P q)->double{//有向三角形和圆相交面积
		P d=q-p;
		double a=d*p/len2(d),b=(len2(p)-r*r)/len2(d),
			r2=r*r/2,det=a*a-b;
		if(det<=0) return tan(p,q)*r2;
		double s=max(0.,-a-sqrt(det)),t=min(1.,-a+sqrt(det));
		if(t<0||s>=1) return tan(p,q)*r2;
		P u=p+d*s,v=p+d*t;
		return tan(p,u)*r2+(u^v)/2+tan(v,q)*r2;
	};
	double sum=0;
	for(int i=0,s=poly.size();i<s;i++)
		sum+=tri(poly[i]-c,poly[(i+1)%s]-c);
	return abs(sum);
}
vector<P> poly;
void solve(P c,double area){
	double lb=0,ub=1e4,mid;
	rep(i,0,60){
		mid=(lb+ub)/2;
		if(poly_circle(c,mid,poly)>area) ub=mid;
		else lb=mid;
	}
	printf("%.9lf\n",ub);
}
int main(){
	int n,m;
	scanf("%d",&n);
	poly.resize(n);
	for(auto&[x,y]:poly) scanf("%lf%lf",&x,&y);
	double s=poly[n-1]^poly[0];
	rep(i,0,n-1) s+=poly[i]^poly[i+1];
	s=abs(s)*.5;
	scanf("%d",&m);
	while(m--){
		P c;double p,q;
		scanf("%lf%lf%lf%lf",&c.x,&c.y,&p,&q);
		solve(c,s*(q-p)/q);
	}
}