#include<stdio.h>
int main() {
	int  *i2,a[60]={0};
	i2 = a;
	*i2 = 1819043176;
	*(i2+1) = 0x6F77206F;
	*(i2+2) = 2863311527809936498;
	printf("%s", a);
}
