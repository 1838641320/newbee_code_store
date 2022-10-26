#include<stdio.h>
int main() {
	long long a;
	while(~scanf("%llX",&a)) {
		if(a<0) printf("-%llX %lld -%llo\n",-a,a,-a);
		else printf("%llX %lld %llo\n",a,a,a);
	}
}
