#include<stdio.h>
void reverse(long long a){
	putchar(a%10+'0');
	if(a>9) reverse(a/10);
	else puts("");
}
int main(long long a) {
	while(~scanf("%lld",&a),~a) reverse(a);
}
