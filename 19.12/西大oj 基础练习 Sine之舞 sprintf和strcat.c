#include<stdio.h>
#include<math.h>
#include<string.h>
char ans[999999]={0};
char*sa(char*a,double n,double i){
	if(n==i) {
		sprintf(a,"sin(%.lf)",n);
	}
	else {
		char c=(int)i%2?'-':'+';
		sprintf(a,"sin(%.lf%c%s)",i,c,sa(a+6+(int)log10(i),n,i+1));
	}
	return a;
}
char*s(char*a,double n,double i){
	char an[1700]={0},num[6]={0};
	if(n==i) sprintf(a,"%s+%.lf",sa(a+1,1,1),n);
	if(n>i) {
		sprintf(a,"(%s",s(a+1,n,i+1));
		an[0]=')';
		sa(an+1,n+1-i,1);
		strcat(a,an);
		sprintf(num,"+%.lf",i);
		strcat(a,num);
	}
	return a;
}
int main(){
	double n;
	scanf("%lf",&n);
	s(ans,n,1);
	printf("%s",ans);
}
