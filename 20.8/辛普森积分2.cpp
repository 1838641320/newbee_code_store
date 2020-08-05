#include<bits/stdc++.h>
using namespace std;
double eps=1e-6;
double f(double x){
	return exp(x);
}
double simpson(double l,double r){
	double mid=(l+r)/2.0;
	return (f(l)+f(r)+4.0*f(mid))*(r-l)/6.0;
}
double intergration(double l,double r,double S){
	double mid=(l+r)/2.0,L=simpson(l,mid),R=simpson(mid,r);
	if(fabs(L+R-S)<eps) return L+R;
	return intergration(l,mid,L)+intergration(mid,r,R);
}
int main(){
	double l,r;
	while(~scanf("%lf%lf",&l,&r))
		printf("%lf\n",intergration(l,r,simpson(l,r)));
}