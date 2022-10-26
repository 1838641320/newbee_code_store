#include<stdio.h>
#include<math.h>
#define s (a+b+c)/2
#define area sqrt(s*(s-a)*(s-b)*(s-c))
double calculate(double l1,double l2,double l3); 
int main(){
double size_area,a,b,c;
scanf("%lf%lf%lf",&a,&b,&c);
size_area=area;
printf("%lf\n",size_area);
printf("%lf\n",calculate(a,b,c));}
double calculate(double l1,double l2,double l3){return sqrt((l1+l2+l3)/2*((l1+l2+l3)/2-l1)*((l1+l2+l3)/2-l2)*((l1+l2+l3)/2-l3));}
