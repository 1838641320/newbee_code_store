#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define a1 *(int*)a
#define b1 *(int*)b
#define re_rand srand(time(NULL));for(int i=0;i<20;i++) rand()
int cmp(const void*a,const void*b) {
	return (a1)-(b1);
}
int cmp2(int i,int j){return i<j;}
int main() {
	int n;
	while(~scanf("%d",&n)) {
		int a[n];
		memset(a,0,4*n);
		//for(int i=0; i<n; i++) scanf("%d",&a[i]);
		re_rand;//�����������a[]��ֵ 
		for(int i=0; i<n; i++) a[i]=rand();
		puts("");
		qsort(a,n,4,cmp);//����stdlib�Ŀ������� 
		for(int i=0; i<n; i++) {
			printf("%5d ",a[i]);
			//if(!((i+1)%20)) puts("");
		}
		puts("");
	}
}
