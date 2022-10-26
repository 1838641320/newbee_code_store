#include<stdio.h>
#include<string.h>
#define max 100000
int main() {
	char dec[2 * max + 6] = { 0 }, binary[4 * max + 6] = { 0 };
	int length, i, i2, carry, carry_l, j;
	while (1) {
		i2 = 0;
		memset(dec, 0, 2 * max + 6); memset(binary, 0, 4 * max + 6);
		if (scanf("%s", dec + max + 2) == -1) break;
		length = strlen(dec + max + 2);
		while (i2 < 4 * length) {
			j = max + 1 + length - i2;
			carry = 0; carry_l = 0;
			for (i = 0; i < length; i++) {
				if (i2 == 0) dec[j - i] = 5 * (dec[j - i] - '0');
				else dec[j - i] = 5 * dec[j - i];
				carry = dec[j - i] / 10;
				dec[j - i] = dec[j - i] % 10 + carry_l;
				carry ^= carry_l ^= carry ^= carry_l;
			}
			dec[j - length] = carry_l;
			if (dec[j] == 5) binary[4 * max - i2] = 1;
			j--; i2++;
		}
		for (i = 0; binary[i] == 0; i++);
		while (i <= 4 * max) {
			printf("%c", binary[i] + '0');
			i++;
		}
		printf("\n");
	}
}
