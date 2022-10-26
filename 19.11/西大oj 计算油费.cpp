#include<stdio.h>
int main(){
	long long litre,trouble_some;
	short type, service;
	scanf("%lld%hd%c%c",&litre,&type,&service,&service);
	if (service=='m') service=95;
	if (service=='e') service=97;
	if (type==97) type=793;
	if (type==95) type=744;
	if (type==92) type=695;
	litre=litre*type*service;
	trouble_some=((litre+50)%10000);
	if (trouble_some%200==100) trouble_some-=100;
	if(trouble_some/100>=10) printf("%d.%d",litre/10000,trouble_some/100);
	else printf("%d.0%d",litre/10000,trouble_some/100);
}
