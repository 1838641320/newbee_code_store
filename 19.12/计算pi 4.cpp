#include<stdio.h>
double cal_sqrt3() {
	double up=1,down=0,mid=(up+down)/2;
	while(mid*mid!=(double)1/3) {
		if(mid*mid>(double)1/3) up=mid;
		else down=mid;
		mid=(up+down)/2;
	}
	return mid;
}
int main() {
	double p=cal_sqrt3(),an=p,sum=0;
	int i;
	printf("%lf\n",p);
	for(i=1; i<80; i+=2) {
		sum+=an;
		an*=-1*p*p*i/(i+2);
		printf("%.18lf\n",sum*6);
	}
}
