//#include <stdio.h>
//#include <string.h>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//const int MAX_N = 25;
//char board[MAX_N + 2][MAX_N + 2];
//
//int n;
///*
//int counts[MAX_N + 2];
//int nGroup;
//*/
//vector<int> counts;
//int cnt;
//int discovered[MAX_N][MAX_N];
//
//
//const int dy[4] = { -1, 0, 1, 0 };
//const int dx[4] = { 0, 1, 0, -1 };
//
//void init() {
//	scanf("%d", &n);
//	memset(discovered, -1, sizeof(discovered));
//	for (int i = 0; i < n; i++) {
//		scanf("%s", &board[i]);
//	}
//}
//
//void dfs(int y, int x) {
//	discovered[y][x] = 1;
//	cnt++;
//
//	for (int di = 0; di < 4; di++) {
//		int ny, nx;
//		ny = y + dy[di];
//		nx = x + dx[di];
//
//		if (ny < 0 || ny >= n) continue;
//		if (nx < 0 || nx >= n) continue;
//		if (board[ny][nx] == '0') continue; // 여기까지가 adjacent 확인이다
//		if (discovered[ny][nx] != -1) continue;
//		dfs(ny, nx);
//	}
//}
//
//int main() {
//	init();
//
//	for (int yi = 0; yi < n; yi++) {
//		for (int xi = 0; xi < n; xi++) {
//			if (discovered[yi][xi] == -1 && board[yi][xi] == '1') {
//				cnt = 0;
//				dfs(yi, xi);
//				counts.push_back(cnt);
//			}
//		}
//	}
//
//	sort(counts.begin(), counts.end());
//	printf("%d\n", counts.size());
//	for (int i = 0; i < counts.size(); i++) {
//		printf("%d\n", counts[i]);
//	}
//
//	return 0;
//}