#include<stdio.h>
int prime(int n) {
	for(int i=2; i*i<=n; i++) if(!(n%i)) return 0;
	return n<2?0:1;
}
int main() {
	int n,i=1;
	scanf("%d",&n);
	while(n--) {
		putchar(prime(i++)?'C':'c');
		putchar(prime(i++)?'C':'c');
		putchar(prime(i++)?'S':'s');
		putchar(prime(i++)?'U':'u');
	}
}
