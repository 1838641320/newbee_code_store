#include<stdio.h>
#define abscanset(glory,nuts,guts) 	glory = nuts;guts = (char*)glory;guts++;guts = guts + *(int*)guts + 4
char fact() { printf(""); return 0; }
int main() {
	char(*function)(), *b, *c, *d, empty;
	long long a[800] = { 212122024577877,18392909292934419200,13258597303796236287,
		3488226974999825612,18446740340980327787,6583804984356553859,17022199216589554817,6765967946821550568,14757395258967641283 };
	a[700] = 8031924123371070824; a[701] = 6581362;
	a[600] = 1099510397929;
	scanf("%d", &empty);
	abscanset(function, fact, b);
	char *offset1, *offset2;
	int *mov_byte1, *mov_byte2;
	d = (char*)a;
	for (offset1 = 0;; offset1++) {
		if ((*(b + (int)offset1) ^ 0xffffffe8) == 0) break;
	}
	for (offset2 = 0;; offset2++) {
		if ((*(d + (char)offset2) ^ 0xffffffe8) == 0) break;
	}
	mov_byte1 = (int*)(d + (int)offset2 + 1);
	mov_byte2 = (int*)(b + (int)offset1 + 1);
	*mov_byte1 = (char*)b - (char*)a;
	*mov_byte1 += *mov_byte2;
	mov_byte1 = (int*)((char*)mov_byte1 - 5);
	*mov_byte1 = (int)&a[700];
	for (offset1++;; offset1++) {
		if ((*(b + (int)offset1) ^ 0xffffffe8) == 0) break;
	}
	for (offset2++;; offset2++) {
		if ((*(d + (int)offset2) ^ 0xffffffe8) == 0) break;
	}
	mov_byte1 = (int*)(d + (int)offset2 + 1);
	mov_byte2 = (int*)(b + (int)offset1 + 1);
	*mov_byte1 = (char*)b - (char*)a;
	*mov_byte1 += *mov_byte2;
	function = (char(*)())(&a[600]);
	printf("%d", function);
	function();
	scanf("%d", &empty);
	return 0;
}
