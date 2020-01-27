#include<cstdio>
#include<algorithm>
#include<time.h>
#include<math.h>
#define maxn 524288
int times, ar[maxn] = { 0 };
bool cmp(int a, int b) { times++; return a < b; }
int main() {
	srand(time(0));
	for (int z = 0; z < 10; z++) {
		times = 0;
		for (int i = 0; i < maxn; i++) ar[i] = rand();
		std::sort(ar, ar + maxn,cmp);
		double t = times;
		printf("sort %d elememts compared %d times = %lf*n*log2(n)\n",
			maxn, times, t / (maxn * log2(maxn)));
	}
	getchar();
}