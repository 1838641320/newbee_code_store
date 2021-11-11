#include<iostream>
#include<algorithm>
#include<cstring>
#include<complex>
double eps=1e-9;
double f(double x){
	return exp(x);
}
double simpson(double l,double r){
	double mid=(l+r)/2.0;
	return (f(l)+f(r)+4.0*f(mid))*(r-l)/6.0;
}
double cotes(double l,double r){
	double d=(r-l);
	return (7*f(l)+32*f(l+d/4)+12*f(l+d/2)+32*f(r-d/4)+7*f(r))*d/90;
}
double intergration(double l,double r,double S,double (*intg)(double l, double r)){
	double mid=(l+r)/2.0,L=intg(l,mid),R=intg(mid,r);
	if(fabs(L+R-S)<eps) return L+R;
	printf("%lf %lf\n",l,r);
	return intergration(l,mid,L,intg)+intergration(mid,r,R,intg);
}
int main(){
	double l,r;
	while(~scanf("%lf%lf",&l,&r)){
		printf("%.20lf\n",intergration(l,r,simpson(l,r),simpson));
		printf("%.20lf\n",intergration(l,r,simpson(l,r),cotes));
	}
}