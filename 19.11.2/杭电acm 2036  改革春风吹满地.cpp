#include<stdio.h>
int main() {
	double x2,y2,n,x1,y1,x0,y0;
	while(~scanf("%lf",&n)) {
		if(n==0) return 0;
		double area=0;
		scanf("%lf%lf",&x1,&y1);
		x0=x1;y0=y1;
		for (int i=1;i<n; i++) {
			scanf("%lf%lf",&x2,&y2);
			area+=x1*y2-x2*y1;
			x1=x2;y1=y2;
		}
		area+=x2*y0-x0*y2;
		printf("%.1lf\n",area/2);
	}
}
