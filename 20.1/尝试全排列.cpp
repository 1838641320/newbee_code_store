#include<cstdio>
#include<cstring>
#include<cstdlib>
const int N = 4;
char in[5] = { 0 }, t, used[5], ans[5] = {0};
void solve(int n) {
	if (n == N) {
		printf("%4d ", strtol(ans,0,10));
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!used[i]) {
			ans[n] = in[i];
			used[i]++;
			solve(n + 1);
			used[i]--;
		}
		if (!n) puts("");
	}
}
int main() {
	while (~scanf("%c %c %c %c%*c", &in[0], &in[1], &in[2], &in[3])) solve(0);
}