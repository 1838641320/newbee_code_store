#include<stdio.h>
#include<string.h>
int main() {
	int a[52][6] = { 0 }, m, n, im, in, High_Score, count;
	double sum[52];
	while (scanf("%d%d", &n, &m) > 0) {
		memset(a, 0, 4 * 52 * 6);
		for (in = 0; in < n; in++) for (im = 0; im < m; im++) scanf("%d", &a[in][im]);
		for (in = 0; in < n; in++) {
			sum[in] = 0;
			for (im = 0; im < m; im++) sum[in] += a[in][im];
			if (in != n - 1) printf("%.2lf ", sum[in] / m);
			else printf("%.2lf\n", sum[in] / m);
		}
		memset(sum, 0, 4 * 52);
		for (im = 0; im < m; im++) {
			sum[im] = 0;
			for (in = 0; in < n; in++) sum[im] += a[in][im];
			if (im != m - 1) printf("%.2lf ", sum[im] / n);
			else printf("%.2lf\n", sum[im] / n);
		}
		count = 0;
		for (in = 0; in < n; in++) {
			High_Score = 1;
			for (im = 0; im < m; im++)
				if (a[in][im] < sum[im] / n) { High_Score = 0; break; }
			if (High_Score == 1) count++;
		}
		printf("%d\n\n", count);
	}
}

