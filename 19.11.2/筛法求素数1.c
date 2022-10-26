#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	// 输入n，在prime数组里存放1~n的素数 
	int n;
	scanf("%d",&n);
	int *original=malloc(4*n),*prime=malloc(4*n),p=0;
	memset(original,0,4*n);
	memset(prime,0,4*n);
	original[0]=original[1]=1;//不是质数标记为一（合数标记为一 
	for(int i=2; i<n; ++i) {
		if(!original[i])//不是合数，保存 
			prime[p++]=i;//存在质数数组里 
		for(int i1=0;i1<p;i1++) {
			if(i*prime[i1]>=n) break;//超出范围了 
			original[i*prime[i1]]=1;//质数的倍数，是合数 
			if(!i%prime[i1]) break;//i是某质数的倍数，跳出
		}
	}
	//在prime数组里存放1~n的素数
	puts("输出素数输入1，统计个数按2");
	int choice;
	scanf("%d",&choice);
	switch(choice) {
	case 1 :
		for(int i1=0; i1<p; i1++)
			printf("%d ",prime[i1]);
		break;
	case 2:
		printf("%d\n",p);
	}
}
