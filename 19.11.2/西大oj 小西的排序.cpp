#include<stdio.h>
#define swap(a,b) {double t;t=b;b=a;a=t;}
int main() {
	int n,i;
	while(~scanf("%d",&n)) {
		double height[10000]={0},order[10000]={0};
		char b[10000][24]={0};
		for(i=0; i<n; i++) {
			scanf("%s %lf",b[i],&height[i]);
			order[i]=i;
		}
		for (i=0; i<n-1; i++) for(int j=i+1; j<n; j++) if(height[i]>height[j]) {
					swap(height[i],height[j]);
					swap(order[i],order[j]);
				}
		for (i=0; i<n; i++) printf("%s ",b[(int)order[i]]);
		puts("");
	}
}
