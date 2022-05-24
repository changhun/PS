#include <stdio.h>
#include <string.h>


const int MAX_N = 50;
int discovered[MAX_N + 2][MAX_N + 2];
int board[MAX_N + 2][MAX_N + 2];
int w, h;


int init() {
	scanf("%d %d", &w, &h);
	if (w == 0 || h == 0) return -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	memset(discovered, -1, sizeof(discovered));
	return 1;
}

const int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void dfs(int y, int x) {
	discovered[y][x] = 1;
	for (int di = 0; di < 8; di++) {
		int ny = y + dy[di];
		int nx = x + dx[di];
		if (ny < 0 || ny >= h) continue;
		if (nx < 0 || nx >= w) continue;
		if (board[ny][nx] == 0) continue;
		if (discovered[ny][nx] != -1) continue;
		dfs(ny, nx);
	}
}

int main() {
	while (1) {
		int ret = init();
		if (ret == -1) break;
		int ans = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == 1 && discovered[i][j] == -1) {
					dfs(i, j);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}