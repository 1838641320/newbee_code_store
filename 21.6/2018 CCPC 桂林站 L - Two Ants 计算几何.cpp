#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
struct P{double x,y;};
P operator+(P a,P b){return {a.x+b.x,a.y+b.y};};
P operator-(P a,P b){return {a.x-b.x,a.y-b.y};};
double operator*(P a,P b){return a.x*b.x+a.y*b.y;};
double operator^(P a,P b){return a.x*b.y-a.y*b.x;};
P operator*(const P&a,double b){return {a.x*b,a.y*b};}
int side(P&a,P&b,P&c){return ((c-a)^(b-a))>=0;}
P rotate(P&a,double t){
	double c=cos(t),s=sin(t);
	return {a.x*c-a.y*s,a.x*s+a.y*c};
}
int n,k;
P get_intersect(P p1,P p2,P p3,P p4){
	P base=p4-p3;
	double r1=base^(p1-p3),r2=base^(p2-p3);
	double k=r2-r1;
	if(fabs(k)<1e-12) return {1e99,1e99};
	return (p1*r2-p2*r1)*(1.0/k);
}
void solve(){
	P p1,p2,p3,p4,e1,e2,e3,e4;
	{
		double x1,y1,x2,y2,x3,y3,x4,y4;
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		p1={x1,y1},p2={x2,y2},p3={x3,y3},p4={x4,y4};
		double len=hypot(x4-x3,y4-y3),ang=atan2(y4-y3,x4-x3);
		e1=p1-p3,e2=p2-p3,e3={0,0},e4={len,0};
		e1=rotate(e1,-ang);
		e2=rotate(e2,-ang);
	}
	{//l2 cross l1
		double r1=(p1-p4)^(p2-p4),r2=(p1-p3)^(p2-p3);
		if(r1*r2<0) 
			return (void)puts("0.000");
	}
	{//colinear
		double r1=fabs(e1.y)+fabs(e2.y);
		if(fabs(r1)<1e-12) 
			return (void)puts("0.000");
	}
	if(e1.y*e2.y<=0) return (void)puts("inf");
	if(e1.y>0){
		if(side(e4,e2,e1)) swap(e2,e1);
	}
	else{
		if(side(e3,e1,e2)) swap(e2,e1);
	}
	auto res=get_intersect(e1,e3,e2,e4);
	if(fabs(res.x)>1e50) return (void)puts("inf");
	{
		double r1=e2^e1,r2=(e2-res)^(e1-res);
		if(r1*r2>=0) return (void)puts("inf");
		printf("%lf\n",fabs(r2)/2);
	}
}
int main(){
	int t;scanf("%d",&t);
	for(int ii=1;ii<=t;ii++){
		printf("Case %d: ",ii);
		solve();
	}
}