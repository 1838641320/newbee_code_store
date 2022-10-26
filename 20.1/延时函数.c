#include<stdio.h>
#include<time.h>
void sleep(double t){
	double start=clock();
	while(clock()<start+t);
}
int main(){
	double n;
	scanf("%lf",&n);
	for(int i=1;i<=400;i++){
		sleep(n);
		putchar('.');
		if(!(i%20)) puts("");
	}
}
