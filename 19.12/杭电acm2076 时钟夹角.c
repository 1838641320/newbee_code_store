#include<stdio.h>
#include<math.h>
#include<stdlib.h>
main() {
	int n,h,m,s,t;
	scanf("%d",&n);
	while(n--) {
		scanf("%d%d%d",&h,&m,&s);
		t=abs(3000*(h%12)+50*m+s*5/6-600*m-10*s);
		printf("%d\n",__min(t,36000-t)/100);
	}
}
