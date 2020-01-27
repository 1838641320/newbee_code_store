#include<algorithm>
#include<cstring>
#include<iostream>
#define maxn 100005
using namespace std;
typedef struct {
	int a;
	char q[10];
	int b;
}E;
E student[maxn] = { 0 };
int N, C, i, n = 0;
bool cmp(E first, E second) {
	int t;
	if (C == 1) return first.a < second.a;
	else {
		if (C == 3 && first.b != second.b) return first.b < second.b;
		if (C == 2 && (t=strcmp(first.q, second.q))) return t < 0;
		return first.a < second.a;
	}
}
int main() {
	while (n++,scanf("%d%d", &N, &C), N || C) {
		for (i = 0; i < N; i++) scanf("%d %s %d", &student[i].a, student[i].q, &student[i].b);
		sort(student, student + N, cmp);
		printf("Case %d:\n",n);
		for (i = 0; i < N; i++) printf("%06d %s %d\n", student[i].a, student[i].q, student[i].b);
	}
}