#include <bits/stdc++.h>
int main() {
	int n;
	while (~scanf("%d", &n)) {
		int a[105][105] = { 0 }, x = 1, y = n, l = n, begin = 1;
		do {
			a[x][y] = begin;
			for (int i = 1; i <= l - 1; i++)a[x++][y] = begin++;
			for (int i = 1; i <= l - 1; i++)a[x][y--] = begin++;
			for (int i = 1; i <= l - 1; i++)a[x--][y] = begin++;
			for (int i = 1; i <= l - 1; i++)a[x][y++] = begin++;
			x++; y--; l = l - 2;
		} while (l >= 1 && a[x][y] == 0);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) printf(j == n ? "%d\n" : "%d ", a[i][j]);	
	}
	return 0;
}
