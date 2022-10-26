#include<stdio.h>
#include<math.h>
char b[999999]={0};
char *s(char *a,int n){
	if(n==1) sprintf(a,"%c",'A');
	else sprintf(a,"%s%c%s",s(a,n-1),'A'+n-1,s(a+(int)pow(2,n),n-1));
	return a;
}
int main(int N){
	scanf("%d",&N);
	printf("%s",s(b,N));
}
