#include<stdio.h>
void popstack(long long *stack) {
	short i;
	stack[0] = 0;
	for (i = 0; i <9; i++) stack[i + 1] ^= stack[i] ^= stack[i + 1] ^= stack[i];
}
void revese(long long *stack, int top) {
	long long a[10] = { 0 };
	if (stack[9] == 0) top--;
	int i;
	for (i = 0; i <= top; i++) a[top - i] = stack[i];
	for (i = 0; i <= top; i++)  stack[i] = a[i];
}
int main() {
	long long call[3][10] = { 0 }, in2;
	short in1, store1 = 0, store2 = 0, store3 = 0, i;
	while (scanf("%hd%lld", &in1, &in2) != -1) {
		switch (in1) {
		case 0:
			if ((store1 == 9) && (call[0][9] != 0)) { popstack(call[0]); call[0][9] = in2; break; }
			else call[0][store1] = in2; if (store1 != 9) store1++; break;
		case 1:
			if ((store2 == 9) && (call[1][9] != 0)) { popstack(call[1]); call[1][9] = in2; break; }
			else call[1][store2] = in2; if (store2 != 9) store2++; break;
		case 2:
			if ((store3 == 9) && (call[2][9] != 0)) { popstack(call[2]); call[2][9] = in2; break; }
			else call[2][store3] = in2; if (store3 != 9) store3++; break;
		default: break;
		}
	}
	revese(call[0], store1); revese(call[1], store2); revese(call[2], store3);
	for (i = 0; i <= 9; i++) printf("%lld %lld %lld\n", call[0][i], call[1][i], call[2][i]);
}
