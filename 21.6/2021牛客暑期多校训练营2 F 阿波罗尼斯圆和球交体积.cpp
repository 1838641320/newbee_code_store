#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
using namespace std;
double hypot(double a,double b,double c){return sqrt(a*a+b*b+c*c);}
const double pi=acos(-1);
double cos(double a,double b,double c){return (a*a+b*b-c*c)/(2*a*b);}
double capv(double r,double h){return pi*h*h*(r-h/3.0);}//球缺(冰淇淋盖)体积
double caps(double r,double h){return 2*pi*r*h;}//球缺(冰淇淋盖)面积
double sphere_intersect(double x1,double y1,double z1,double r1,
                        double x2,double y2,double z2,double r2) {
    if(r1>r2) swap(r1,r2);
    double d=hypot((x1-x2),(y1-y2),(z1-z2));
    if(d>=r2+r1)return 0;
    if(d<=r2-r1)return pow(r1,3)*4*pi/3;
    double h1=r1-r1*cos(r1,d,r2),h2=r2-r2*cos(r2,d,r1);
    return capv(r1,h1)+capv(r2,h2);
}
void solve2(){
	double pp[4][3],c1[3],e1[3],c2[3],e2[3];
	rep(i,0,4) rep(j,0,3) scanf("%lf",&pp[i][j]);
	double k1,k2;
	scanf("%lf%lf",&k1,&k2);
	rep(i,0,3) {
		double len=(pp[1][i]-pp[0][i]);
		c1[i]=pp[0][i]+(len/(k1+1)*(k1)+len/(k1-1)*(k1))/2.0;
		e1[i]=pp[0][i]+len/(k1-1)*(k1);
		len=pp[3][i]-pp[2][i];
		c2[i]=pp[2][i]+(len/(k2+1)*(k2)+len/(k2-1)*(k2))/2.0;
		e2[i]=pp[2][i]+len/(k2-1)*(k2);
	}
	double r1=0,r2=0;
	rep(i,0,3){
		r1+=pow(c1[i]-e1[i],2);
		r2+=pow(c2[i]-e2[i],2);
	}
	r1=sqrt(r1),r2=sqrt(r2);
	double dis=0;
	rep(i,0,3){
		dis+=pow(c2[i]-c1[i],2);
	}
	dis=sqrt(dis);
	printf("%lf\n",sphere_intersect(c1[0],c1[1],c1[2],r1,c2[0],c2[1],c2[2],r2));
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve2();
}