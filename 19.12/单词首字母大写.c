#include<stdio.h>
main() {
	char a[99],s;
	while(~scanf("%s%c",a,&s)) {
		if(*a>90)*a-=32;
		printf("%s%c",a,s);
	}
}
