#include<stdio.h>
#define sort998(shuzu,i1,i2,n)	for (i1 = 0; i1 < n; i1++)for (i2 = 0; i2 < n; i2++) if (shuzu[i2] > shuzu[i2 + 1]) shuzu[i2] ^= shuzu[i2 + 1] ^= shuzu[i2] ^= shuzu[i2 + 1]
int main() {
	int a[10001], b[10001], n, i1, i2;
	while(scanf("%d", &n)!=-1){
	for (i1 = 0; i1 < n; i1++) scanf("%d", &a[i1]);
	for (i1 = 0; i1 < n; i1++) scanf("%d", &b[i1]);
	sort998(a, i1, i2, n);
	sort998(b, i1, i2, n);
	for (i1 = 0; i1 < n; i1++)
		if ((a[i1] == a[i1 - 1]) && (b[i1] == b[i1 - 1] && (i1>0))) continue;
		else printf("%d %d\n", a[i1], b[i1]);} 
}
