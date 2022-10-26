#include#include<stdio.h>
#include<string.h>
int main() {
	int i;
	char *week[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" }, input_string[20];
	scanf("%s", input_string);
	for (i = 0; i < 7; i++) if (strcmp(input_string, week[i]) == 0) { printf("%d\n", i); return 0; }
	printf("-1\n");
}
