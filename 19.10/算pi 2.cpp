#include<stdio.h>
int main(){
double i,n=99,pi=0,sgn=1;
scanf("%lf",&n);
for (i=2;i<n;i=i+2)
	{pi=pi+(4*sgn)/(i*(i+1)*(i+2));sgn=-sgn;}
printf("\n%.15lf",pi+3);}
