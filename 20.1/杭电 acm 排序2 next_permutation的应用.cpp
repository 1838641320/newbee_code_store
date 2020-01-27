#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int main() {
	char in[5] = { 0 };
	while (~scanf("%c %c %c %c%*c", &in[0], &in[1], &in[2], &in[3])) {
		set<int> ans;
		while (ans.insert(strtol(in, 0, 10)), next_permutation(in, in + 4));
		for (auto x = ans.begin();;) {
			printf("%4d", *x);
			auto t = x++;
			if (x == ans.end()) break;
			putchar(*x / 1000 == *t / 1000 ? ' ' : '\n');
		}
		puts("");
	}
}