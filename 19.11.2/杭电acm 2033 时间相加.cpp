#include<stdio.h>
#include<string.h>
int main() {
	int AH, AM, AS, BH, BM, BS, i, n, ch, cm, cs;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d%d%d%d%d", &AH, &AM, &AS, &BH, &BM, &BS);
		cs = AS + BS;
		cm = AM + BM;
		ch = AH + BH;
		if (cs > 59) { cs %= 60; cm++; }
		if (cm > 59) { cm %= 60; ch++; }
		printf("%d %d %d\n", ch, cm, cs);
	}
}
