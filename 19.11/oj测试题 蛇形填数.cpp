#include<stdio.h>
#include<string.h>
int main() {
	short direction, column, line;
	int n, i;
	while (scanf("%d", &n) != -1) {
		column = n - 1;
		line = 0;
		direction = 1;
		int matrix[n][n];
		memset(matrix, 0, n * n * 4);
		for (i = 1; i <= n*n; i++)
		{
			switch (direction)
			{
			case 1:
				if ((line + 1) == n || matrix[column][line + 1] != 0) {
					matrix[column][line] = i; direction++; column--; break;
				}
				else { matrix[column][line] = i; line++; break; }
			case 2:
				if (column == 0 || matrix[column - 1][line] != 0) {
					matrix[column][line] = i; direction++; line--; break;
				}
				else { matrix[column][line] = i; column--; break; }
			case 3:
				if (line == 0 || matrix[column][line - 1] != 0) {
					matrix[column][line] = i; direction++; column++; break;
				}
				else { matrix[column][line] = i; line--; break; }
			case 4:
				if ((column + 1) == n || matrix[column + 1][line] != 0) {
					matrix[column][line] = i; direction = 1; line++; break;
				}
				else { matrix[column][line] = i; column++; break; }
			default:break;
			}
		}
		for (line = 0; line < n; line++) {
			for (column = 0; column < n - 1 ; column++)printf("%d ", matrix[column][line]);
		printf("%d \n", matrix[n - 1][line]);
		};
	}
}
