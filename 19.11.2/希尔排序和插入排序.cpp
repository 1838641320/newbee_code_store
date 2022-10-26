#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define re_rand srand(time(NULL));for(int i=0;i<20;i++) rand()
void shell_sort(int array[],int size) {
	int i,j,gap,n;
	for(gap=2*(int)(size/4)+1;; gap=2*(int)(gap/4)+1) {
		//printf("%d ",gap);
		//内置插入排序 
		for(i=gap; i<size; i++) {
			int key=array[i];
			for(j=i-gap;/*比较方式*/key<array[j]/**/&&j>=0; j-=gap)
				array[j+gap]=array[j];
			array[j+gap]=key;
		}
	if(gap==1) return;
	}
}
void insert_sort(int array[],int size) {
	for(int i=0; i<size; i++) {
		for(int j=i+1; array[j]<array[j-1]&&j>0; j--)
			array[j]^=array[j-1]^=array[j]^=array[j-1];
	}
}
void insert_sort2(int array[],int size) {
	for(int i=1; i<size; i++) {
		int key=array[i],j;
		for(j=i-1; key<array[j]&&j>=0; j--)
			array[j+1]=array[j];
		array[j+1]=key;
	}
}
int main() {
	int n,*a,choice;
	while(~scanf("%d",&n)) {
		a=(int*)malloc(4*n);
		re_rand;//这三行赋初值 
		for(int i=0; i<n; i++) a[i]=rand();
		scanf("%d",&choice);
		//排序 
		if(choice)insert_sort2(a,n);
		else shell_sort(a,n);
		//输出 
		puts("");
		for(int i=0; i<n; i++)printf("%5d ",a[i]);
		puts("");
	}
}
