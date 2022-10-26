#include<stdio.h>
 double fact(int n);
 int main(void) 
 {
 	int m,n,t;
 	double C;
 	printf("Enter m,n:");
 	scanf("%d%d",&m,&n);
    while(m>n) {
	printf("Enter m,n:");
 	scanf("%d%d",&m,&n);}
	C=fact(n)/(fact(m)*fact(n-m));
	printf("C=%f\n",C);
	return 0;	
}
double fact(int n)
{
	double product;
	int i;
	product=1;
	for(i=1;i<=n;i++){
	   product=product*i;}
	return product;	 
 }
