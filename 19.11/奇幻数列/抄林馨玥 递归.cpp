#include<stdio.h> 
#include<math.h>
double Fn(int n,int k){
	int j;
	double product;
	if(n==1) {
	product=1;
	return product;}
	else
	  {
	  	product=0;
	  	for(j=n-1;j>=1;j--)
	  	product=Fn(j,k)+product;}
	  	product=product+pow(n,k);
	return product;
}
int main(void)
{
	int n,k;
	double x;
	while(scanf("%d%d",&n,&k)!=EOF){
	    x=(int)Fn(n,k)%(int)pow(10,9);
		printf("%.0lf\n",x);
		}
	return 0;
}
