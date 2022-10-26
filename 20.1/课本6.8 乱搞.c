#include<stdio.h>
long long a=0;
int main(long long b) {
	if(!a) while(~scanf("%lld",&a),~a) main(a);
	putchar(b%10+'0');
	if(b>9) main(b/10);
	else puts("");
}
