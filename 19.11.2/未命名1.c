#include<stdio.h>
#include<math.h>
main(){
	float a,b;
	while(~scanf("%f%f",&a,&b)&&a+b)
	printf("%s\n",(a+sqrt(a*a-4*b))/2!=(int)(a+sqrt(a*a-4*b))/2||a*a<4*b?"No":"Yes");
}
