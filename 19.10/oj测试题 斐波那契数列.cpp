#include<stdio.h>
int main(){
	int i,n=1,an1=1,an2=1,an3;
	while(scanf("%d",&n)!=EOF){
	an1=1;an2=1;
	if (n<3) {printf("1\n");continue;}
	else {for (i=2;i<n;i++){
		an3=an1+an2;
		an1=an2;
		an2=an3;}
	printf("%d\n",an3);}}
return 0;}
