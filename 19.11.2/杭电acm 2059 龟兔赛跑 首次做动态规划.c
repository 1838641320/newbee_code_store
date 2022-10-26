#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define min(a,b) __min(a,b)
int main() {
	double L,N,C,T,VR,VT1,VT2,p[105],time[105];
	while(~scanf("%lf%lf%lf%lf%lf%lf%lf",&L,&N,&C,&T,&VR,&VT1,&VT2)) {
		int i=1,j;
		double time9=L/VR,delta,time1;
		memset(p,0,840);
		for(i=1; i<105; i++) time[i]=1e100;
		time[0]=0;
		for(i=1; i<=N; i++) scanf("%lf",p+i);
		p[0]=0;
		p[(int)N+1]=L;
		for(i=1; i<=N+1; i++) {
			for(j=0; j<i; j++) {
				delta=p[i]-p[j];
				time1=delta/VT1;
				if(j!=0) time1+=T;
				if(delta>C) time1+=C/VT1+(delta-C)/VT2-delta/VT1;
				time[i]=min(time[i],time[j]+time1);
			}
		}
		if(time9>time[(int)N+1]) puts("What a pity rabbit!");
		else puts("Good job,rabbit!");
	}
}
