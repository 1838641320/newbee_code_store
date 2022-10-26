#include<stdio.h>
double an(double n) {
	if(n<=2) return 1;
	if((long long)n%2) return 2*an(n-1)+1;
	else return 2*an(n-1)-1;
}
int main() {
	double n;
	while(~scanf("%lf",&n)) {
		if(n==1) puts("3");
		else printf("%.lf\n",6*an(n-1));
	}
}
