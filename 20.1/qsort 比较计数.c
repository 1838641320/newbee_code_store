#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#define maxn 524288
typedef long long ll;
int times,array[maxn]={0};
int cmp(const void *a,const void *b){
	times++;
	return *(int*)a-*(int*)b;
}
int main(){
	srand(time(0));
	for(int test=0;test<10;test++){
		times=0;
		for(int i=0;i<maxn;i++) array[i]=rand();
		qsort(array,maxn,4,cmp);
		double t=(double)times;
		printf("sort %d elememts compared %lld times = %lf*n*log2(n)\n",
		maxn,times,t/(maxn*log2(maxn)));
	}
	getchar();
}
