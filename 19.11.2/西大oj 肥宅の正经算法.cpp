#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
	int start;
	int end;
} place;
int cmp(const void *a,const void *b) {
	return (*((place*)a)).end-(*((place*)b)).end;
}
int main() {
	int n,i;
	while(~scanf("%d",&n)) {
		int count=0,a,b;
		place plmm[n];
		memset(plmm,0,sizeof(place));
		for (i=0; i<n; i++)
			scanf("%d%d",&plmm[i].start,&plmm[i].end);
		qsort(plmm,n,sizeof(place),cmp);
		a=0;
		b=0;
		for (i=0; i<n; i++) {
			if(plmm[i].start>=b) {
				b=plmm[i].end;
				count++;
			}
		}
		printf("%d\n",count); 
	}
}
