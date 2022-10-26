#include<stdio.h>
#include<string.h>
int main() {
	int n,bit,i,j;
	while(~scanf("%d",&n)) {
		long long a[n];
		memset(a,0,n*8);
		a[0]=1;
		bit=0;
		for (i=2; i<=n; i++) {
			for (j=0; j<=bit; j++) a[j]*=i;
			for (j=0; j<=bit; j++) {
				a[j+1]+=a[j]/100000000;
				a[j]%=100000000;
			}
			if(a[bit+1]) bit++;
		}
		printf("%d",a[bit]);
		for (i=bit-1; i>=0; i--) printf("%08d",a[i]);
		printf("\n");
	}
}
