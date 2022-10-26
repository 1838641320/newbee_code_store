#include<stdio.h>
int main () {
	int n;
	double item=1,sum=0,i;
	scanf("%d",&n);
	for (i=1; i<=n; i++) {
		item/=i;
		sum+=item;
	}
	printf("%lf\n",sum);
}

