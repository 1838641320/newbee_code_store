#include<stdio.h>
double b;
char op, l;
int main() {
	while (~scanf("%lf", &b)) {
		int i = 0, j;
		double save[106] = { 0 }, ans = 0;
		save[0] = b; l = getchar();
		if (save[0] == 0 && l == '\n') return 0;
		while (1) {
			scanf("%c %lf", &op, &b);
			switch (op) {
			case '+':save[++i] = b; break;
			case '-':save[++i] = -b; break;
			case '*':save[i] *= b; break;
			case '/':save[i] /= b; break;
			}
			if (getchar() == '\n') break;
		}
		for (j = 0; j < 106; j++) ans += save[j];
		printf("%.2lf\n", ans);
	}
}