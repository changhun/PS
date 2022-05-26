#include <stdio.h>
#include <string.h>

const int MAX_N = 1000;
const int INF = 987654321;
enum {
	EMPTY = -1,
	NOT_RIPED,
	RIPED
};

int board[MAX_N + 2][MAX_N + 2];
int distance[MAX_N + 2][MAX_N + 2];
int h, w;

struct Queue {
	int y, x;
}que[MAX_N * MAX_N];
int rp, wp;

bool empty() {
	return rp >= wp;
}

void push(int y, int x) {
	que[wp++] = { y, x };
}

struct Queue& front() {
	return que[rp];
}

struct Queue pop() {
	return que[rp++];
}

void init() {
	scanf("%d %d", &w, &h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &board[i][j]);
				distance[i][j] = INF;
		}
	}

	wp = rp = 0;
}

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };
int bfs() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (board[i][j] == RIPED) {
				//que[wp++] = { i, j };
				push(i, j);
				distance[i][j] = 0;
			}
		}
	}

	while (!empty()) {
		struct Queue& here = front();
		pop();
		for (int di = 0; di < 4; di++) {
			int ny = here.y + dy[di];
			int nx = here.x + dx[di];
			if (ny < 0 || ny >= h) continue;
			if (nx < 0 || nx >= w) continue;
			if (distance[ny][nx] == INF && board[ny][nx] == NOT_RIPED) {
				push(ny, nx);
				distance[ny][nx] = distance[here.y][here.x] + 1;
			}
		}
	}

	int max = -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (board[i][j] == EMPTY) continue;
			if (distance[i][j] == INF) return -1;
			max = distance[i][j] > max ? distance[i][j] : max;
		}
	}
	return max;
}

int main() {
	init();
	int ret = bfs();
	printf("%d\n", ret);

	return 0;
}