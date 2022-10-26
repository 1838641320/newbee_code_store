#include<stdio.h>
#include<math.h>
double dist(double x,double y) {
double sum;
sum=sqrt(x*x+y*y);
return sum;}

int main(){
	double i,x,y,S=0;
	for (i=0;i<10;i=i+1){
		scanf("%lf%lf",&x,&y);
		S=S+dist(x,y);}
	printf("distance = %lf",S);}
