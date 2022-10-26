#include<stdio.h>
#define max 40
int main() {
	int i,j,n;
	while(~scanf("%d",&n)) {
		long long a[max]= {1,1},b[max];
		for (i=0; i<n; i++) {
			if (i>1) {
				for (j=1; j<=i; j++) b[j]=a[j-1]+a[j];
				for (j=1; j<=i; j++) a[j]=b[j];
			}
			for(j=0; j<i; j++) printf("%lld ",a[j]);
			printf("%lld\n",a[i]);
		}
		puts("");
	}
}
