#include<stdio.h>
#include<math.h>
double fact (int n);
int main() {
double x,s=0,item;
scanf("%lf",&x);
int i=2;
s=1+x;
do {item=pow(x,i)/fact(i);
i++;
s=s+item;} while (fabs(item)>=0.000000000001);
printf("%.11lf",s);
return 0;}
double fact(int n){
int j;
double product=1.0;
for (j=1;j<=n;j++) {product=product*j;}
return product;}

