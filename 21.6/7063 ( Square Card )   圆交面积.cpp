#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
#define rep(i,a,b) for(int i=a;i<(int)b;i++)
#define per(i,a,b) for(int i=a;i>(int)b;i--)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
// typedef __uint128_t ull;
//-------------------------------------------
const double pi=acos(-1);
double area(double r,double h){
    return r*r*acos(h/r)-h*sqrt(r*r-h*h);
}
double circular_intersect(double r1,double r2,double d){
    if(r1>r2) swap(r1,r2);
    if(r1+r2<=d) return 0;
    if(r2-r1>d) return pi*r1*r1;
    double ang1=acos((r1*r1+d*d-r2*r2)/(2*r1*d));
    double ang2=acos((r2*r2+d*d-r1*r1)/(2*r2*d));
    return ang1*r1*r1 + ang2*r2*r2 - r1*d*sin(ang1);
}
void solve(){
    double r1,r2,x1,x2,y1,y2,a;
    scanf("%lf%lf%lf%lf%lf%lf%lf",&r1,&x1,&y1,&r2,&x2,&y2,&a);
    double dis=hypot(x2-x1,y2-y1);
    r1=sqrt(r1*r1-a*a/4)-a/2;
    if(r2*r2-a*a/4<=0){
        printf("%.6lf\n",0.0);
        return;
    }
    r2=sqrt(r2*r2-a*a/4)-a/2;
    if(r2<=0){
        printf("%.6lf\n",0.0);
        return;
    }
    printf("%.6lf\n",min((circular_intersect(r1,r2,dis))/(pi*r1*r1),1.0));
}
int main(){
    int t;scanf("%d",&t);
    while(t--) 
        solve();
}