#include<stdio.h>
int gcd(int a,int b) {int j=a,q=b;while(j) {q%=j;j^=q^=j^=q;}return q;}
int gcd2(int a,int b) {return b==0? a:gcd2(b,a%b);}
int main() {
	int a,b,c,d,up,down,t;
	char op;
	while(~scanf("%d/%d%c%d/%d",&a,&b,&op,&c,&d)) {
		up=a*d+c*b*((op=='+')*2-1);
		down=b*d;
		if(up) {
			t=gcd2(up,down);
			printf("%d/%d\n",up/t,down/t);
		}
		else puts("0/1");
	}
}
