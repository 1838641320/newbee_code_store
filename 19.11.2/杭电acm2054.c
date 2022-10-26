#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int judge(char* A, char* B) {
	if(strcmp(A, B) == 0)
		return 1;
	else {
		if(A[0] == '-' && B[0] == '-') A[0] = B[0] = '0';
		int i1, i2, j1, j2;
		for (i1 = 0; A[i1] == '0' && i1 < strlen(A) - 1; i1++);
		for (i2 = 0; B[i2] == '0' && i2 < strlen(B) - 1; i2++);
		if(strcmp(A + i1, B + i2) == 0)
			return 1;
		if(A[i1] == '.')
			i1--;
		if(B[i2] == '.')
			i2--;
		if(strstr(A, ".") > 0) {
			for (j1 = strlen(A) - 1; A[j1] == '0'; j1--);
			A[j1 + 1] = 0;
			if(A[j1] == '.') A[j1] = 0;
		}
		if(strstr(B, ".") > 0) {
			for (j2 = strlen(B) - 1; B[j2] == '0'; j2--);
			B[j2 + 1] = 0;
			if(B[j2] == '.') B[j2] = 0;
		}
		if (1)
			;
		if (strcmp(A + i1, B + i2) == 0)
			return 1;
		else if(atof(A) == atof(B) && atof(A) > -1 && atof(A) < 1) return 1;
		return 0;
	}
}
int main() {
	char *a[5] = {"NO", "YES"}, A[99999], B[99999];
	while(~scanf("%s%s", &A, &B)) {
		printf("%s\n", a[judge(A, B)]);
		memset(A, 0, 99999);
		memset(B, 0, 99999);
	}
}
