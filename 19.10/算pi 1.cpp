#include<stdio.h>
int main(){
	double n,a=1,pi=1;
	scanf("%lf",&n);
	for (;a<n;a++) pi=pi*(1-1/(4*a*a));
	printf("%.15lf",2/pi);}
