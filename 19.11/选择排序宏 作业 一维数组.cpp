#include <stdio.h>
#define sort998(a,n) int i1, i2;for (i1 = 0; i1 < n - 1; i1++)for (i2 = i1 + 1; i2 < n; i2++)if (a[i1]>a[i2]) a[i1] ^= a[i2] ^= a[i1] ^= a[i2]
int n = 5, i, x;
void sort(int a[]);
int search(int a[]);
void Insert(int a[]);
void Delete(int a[]);
int main(void)
{
	int a[10] = { 6,5,8,10,2 };
	int choose;
	sort(a);
	while (1)
	{
		printf("\n\n");
		printf("\t\t\t****************\n");
		printf("\t\t\t*  1. ²éÑ¯     *\n");
		printf("\t\t\t*  2. ²åÈë     *\n");
		printf("\t\t\t*  3. É¾³ý     *\n");
		printf("\t\t\t*  0. ÍË³ö     *\n");
		printf("\t\t\t****************\n");
		printf("ÇëÑ¡Ôñ£º\n");
		scanf("%d", &choose);
		if (choose == 0) break;
		else {
			switch (choose) {
			case 1:  search(a); break;
			case 2:  Insert(a); break;
			case 3:  Delete(a); break;
			}
		}
	}
	return 0;
}
void sort(int a[]) {sort998(a, n);}
int search(int a[]) {
	scanf("%d", &x);
	for (i = 0; i < n; i++)
		if (a[i] == x) { printf("%d\n", i); return i; }
		printf("Not Found\n");
}
void Insert(int a[]) {
	int j;
	scanf("%d", &x);
	a[n] = x;
	n++;
	sort(a);
	for (j = 0; j < n; j++) printf("%d ", a[j]);
}
void Delete(int a[]) {
	int j;
	scanf("%d", &x);
	for (j = 0; j < n; j++) if (a[j] == x) { a[j] = 0; break; }
	for (i = j; i < n; i++) a[i] ^= a[i + 1] ^= a[i] ^= a[i + 1];
	n--;
	sort(a);
	for (j = 0; j < n; j++) printf("%d ", a[j]);
}
