#include<stdio.h>
#include<string.h>
int main() {
	int i, j, n;
	char string[6666];
	scanf("%d", &n);
	for (i = 0; i<n; i++) {
		memset(string, 0, 6666);
		scanf("%s", string);
		int length = strlen(string);
		for (j = 0;j<length / 2; j++) if(string[j]!=string[length-j-1]) break;
		if (2*(j+1) > length) printf("yes\n");
		else printf("no\n");
	}
}
