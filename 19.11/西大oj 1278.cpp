#include<stdio.h>
#include<math.h>
int main() {
	int n, T, i;
	int i2, can_flag;
	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		can_flag = 1;
		char a[10086] = { 0 };
		scanf("%d%s", &n, a);
		//scanf("%s", a);
		if (n % 2 != 0) { printf("0\n"); continue; }
		for (i2 = 0; i2 < n / 2; i2++) {
			if (abs(a[i2] - a[n - 1 - i2])>3 || a[i2]>'z' || a[i2]<'a' || a[n - 1 - i2]>'z' || a[n - 1 - i2] < 'a' ||( abs(a[i2] - a[n - 1 - i2]) == 1)) { can_flag = 0; break; }
		}
		printf("%d\n", can_flag);
	}
}
