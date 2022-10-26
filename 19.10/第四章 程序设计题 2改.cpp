#include<stdio.h>
#include<math.h>
double fact (int n);
int main() {
double x,s=0,item,i=0;
scanf("%lf",&x);
item=x;
do {i=i+1;
s=s+item;
item=item*x/i;} while (fabs(item)>=1e-20);
printf("%.15e",s/x);}
