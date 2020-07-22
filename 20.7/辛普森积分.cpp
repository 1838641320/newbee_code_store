#include"s.h"
#include<bits/stdc++.h>
using namespace std;
double eps=1e-6;
double f(double x){
	return 8*pow(sin(x),3);
}
double simpson(double l,double r){
	return (f(l)+f(r)+4*f((l+r)/2))*(r-l)/6;
}
double cal(double l,double r,double S){
	//printf("%lf %lf\n",l,r);
	double L=simpson(l,(l+r)/2),R=simpson((l+r)/2,r);
	if(fabs(L+R-S)<eps) return L+R;
	return cal(l,(l+r)/2,L)+cal((l+r)/2,r,R);
}
int main(){
	double l,r;
	while(scanf("%lf %lf",&l,&r)==2)
		printf("%lf\n",cal(l,r,simpson(l,r)));
}