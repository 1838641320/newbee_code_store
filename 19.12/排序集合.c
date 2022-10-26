#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define a1 *(int*)a
#define b1 *(int*)b
typedef long long ll;
void swap(int *a,int *b) {int t;t=*b;*b=*a;*a=t;}
void sort(int *v,int n) {
	int i,j,k;
	for(i=0; i<n; i++) {
		for(j=0; j<n-i; j++) {
			if(v[j]>v[j+1]) {
				k=v[j];
				v[j]=v[j+1];
				v[j+1]=k;
			}
		}
	}
}
void sort_count(int a[],int n){
	int max=-2147483648,j,i;
	for(i=0;i<n-1;i++) max=__max(max,a[i]);
	int b[max+8];
	memset(b,0,4*max+32);
	for(i=0;i<n;i++) b[a[i]]++;
	for(i=j=0;i<=max;i++)while(b[i]--) a[j++]=i;
}
void sort668(int *a,int n) {
	int k,i,j=1,t;
	for (i=0;i<n-1;i++) {
		k=i+1;
		for(j=k;j<n;j++) 
			if(a[k]>a[j]) k=j; 
		t=a[i];a[i]=a[k];a[k]=t;
	} 
}
void sort334(int a[], int start, int end) {
	if(end<=start) return;
	int i = start + 1, j = end;
	do {
		while (a[i] > a[start] && i < j) i++;
		while (a[j] < a[start] && i < j) j--;
		if (j >= i) swap(&a[i], &a[j]);
		i++;
		j--;
	} while (j >= i);
	if (a[j+1] >= a[start]) swap(&a[start], &a[j+1]);
	else swap(&a[start], &a[j]);
	sort334(a,j+1,end);
	sort334(a,start,j);
}
void shell_sort(int *array,int size) {
	int i,j,gap,n;
	for(gap=2*(int)(size/4)+1;; gap=2*(int)(gap/4)+1) {
		//printf("%d ",gap);
		//内置插入排序 
		for(i=gap; i<size; i++) {
			int key=array[i];
			for(j=i-gap;j>=0; j-=gap)
				if(/*比较方式*/key>=array[j]/**/) break;
				else array[j+gap]=array[j];
			array[j+gap]=key;
		}
	if(gap==1) return;
	}
}
int cmp(const void*a,const void*b) {
	return (a1)-(b1);
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
	double start_time,end_time; 
	int s,h;
	scanf("%d",&h);
	int *a=malloc(4*h);
	srand((unsigned)time(NULL));
	for(s=0; s<h; s++) a[s]=rand();
	//printf("%d ",a[s]);
	printf("start\n");
	start_time=clock(); 
	//sort668(a,h);
	//sort(a,h);
	//sort334(a,0,h-1);
	//shell_sort(a,h);
	//qsort(a,h,4,cmp);
	sort_count(a,h);
	//insert_sort(a,h);
	//insert_sort2(a,h);
	end_time=clock(); 
	printf("time:%lfms\tend\n",end_time-start_time);
	//for(s=0; s<h; s++) printf("%d ",a[s]);
}

