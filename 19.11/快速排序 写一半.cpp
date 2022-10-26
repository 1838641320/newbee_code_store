#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define max 2000
void swap(int *a,int *b) {int t;t=*b;*b=*a;*a=t;}
void sort334(int a[], int end, int start);
int main() {
	srand(9968 * time(NULL));
	int i, a[max] = { 0 };
	for (int q = 0; q < max; q++) rand();
	for (i = 0; i < max; i++) a[i] = rand();
	sort334(a, 0, max);
	for (i = 0; i < max; i++) {
		if (i % 20 == 0) printf("\n");
		printf("%5d ", a[i]);
		//printf("%5d ", a[i]-a[i+1]);
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
