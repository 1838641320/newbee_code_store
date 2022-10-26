#include<stdio.h>
void sort(int a[],int n) {
	for (int i=0; i<n-1; i++)
		for (int j=i; j<n; j++)
			if (a[i]>a[j]) a[i]^=a[j]^=a[i]^=a[j];
}
int unique (int a[],int n) {
	for (int i=0; i<n;)
		if (a[i]==a[i+1]) {
			a[i+1]=0;
			for (int j=i+1; j<n; j++) {
				a[j]^=a[j+1]^=a[j]^=a[j+1];
			}
			n--;
		} else i++;
	return n;
}
int main () {
	int a[205],n;
	scanf("%d",&n);
	for (int i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a,n);
	n=unique(a,n);
	for (int i=0; i<n; i++) printf("%d ",a[i]);
}

