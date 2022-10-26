#include<stdio.h>
#include<string.h>
#include<math.h>
int main() {
	int T, i, i1, count, length;
	char s[204] = { 0 };
	scanf("%d", &T);
	getchar();
	for (i = 0; i < T; i++) {
		count = 0;
		scanf("%s", s);
		length = strlen(s);
		for (i1 = 0; i1 < length - 1; i1++)
			if ((abs(s[i1] - s[i1 + 1]) == ('M' - 'F'))) { s[i1] = 'J'; s[i1 + 1] = 'J'; }
		for (i1 = 0; i1 <= length; i1++){
			if (s[i1] == 'M' || s[i1] == 'F') count += 2;
			if (s[i1] == 'J') count++;
		}
		printf("%d\n", count / 2);
	}
}