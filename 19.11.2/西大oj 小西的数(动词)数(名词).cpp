#include<stdio.h>
int main() {
	int i,n,bit=1,x,count=0;
	while(~scanf("%d%d",&n,&x)) {
		bit=1;count=0;
		for (i=1; i<=n; i++) {
			int temp=i;
			while(temp) {
				bit=temp%10;
				if(bit==x) count++;
				temp/=10;
			}
		}
		printf("%d\n",count);
	}
}
