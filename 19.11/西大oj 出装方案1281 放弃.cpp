#include<stdio.h>
#include<string.h>
int main() {
	int T, N, equip[48] = { 0 }, j, sum, i, line, column, matrix[16][16] = { 0 };
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d", &N);
		sum = 0;
		memset(equip, 0, 48 * 4); memset(matrix, 0, 16 * 16 * 4);
		for (line = 0; line < N; line++) for (column = 0; column < N; column++) scanf("%d", &matrix[line][column]);
		for (j = 0; j < N; j++) {
			for (line = 0; line < N; line++) for (column = 0; column < N; column++)
				if (matrix[line][column]>equip[3 * j]) {
					equip[3 * j] = matrix[line][column];
					equip[3 * j + 1] = line;
					equip[3 * j + 2] = column;
				}
			for (column = 0; column < N; column++) matrix[equip[3 * j + 1]][column] = 0;
			for (line = 0; line < N; line++) matrix[line][equip[3 * j + 2]] = 0;
		}
		for (j = 0; j < N; j++)
			sum += equip[3 * j];
		printf("%d\n", sum);
	}
}