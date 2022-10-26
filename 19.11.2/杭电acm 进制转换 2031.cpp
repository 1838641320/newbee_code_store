#include<stdio.h>
#include<string.h>
int main(){
	char result[128]={0};
	long long N;
	int i,R,T;
	while(~scanf("%lld%d",&N,&R)){
		i=0;
		if (N<0) {printf("-");N*=-1;}
		else if(N==0) {puts("0");continue;}
		while(N){
			result[i++]=N%R;
			N/=R;
		}
		i--;
		while(~i) {
			if(result[i]<=9) printf("%c",result[i--]+'0');
			else printf("%c",result[i--]-10+'A');
		}
		puts(""); 
		memset(result,0,128);
	}
}
