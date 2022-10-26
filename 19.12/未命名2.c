extern char field[105][105];
extern int N,M;
void dfs(int x, int y) {
	field[x][y] = '.';
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			int nx = x + dx, ny = y + dy;
			if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W') dfs(nx, ny);
		}
	}
	return ;
}
void s() {
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == 'W') {
				dfs(i, j);
				res++;
			}
		}
	}
	printf("%d\n", res);
}
