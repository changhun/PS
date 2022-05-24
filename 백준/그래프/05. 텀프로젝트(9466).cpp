//#include <stdio.h>
//#include <string.h>
//
//const int MAX_N = (int)1e5;
//
//int pick[MAX_N + 2];
//int discovered[MAX_N + 2];
//int finished[MAX_N + 2];
//// 한명이 하나만 선택하니까 필요 없을 듯.
//int n;
//int seq;
//int ans;
//
//
//void init() {
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		int v;
//		scanf("%d", &v);
//		pick[i] = v;
//	}
//	memset(discovered, -1, sizeof(discovered));
//	memset(finished, 0, sizeof(finished));
//	seq = 0;
//	ans = n;
//}
//
//void dfs2(int here) {
//	discovered[here] = seq++;
//	int there = pick[here];
//	if (discovered[there] == -1)
//		dfs2(there);
//	//else if (discovered[there] < discovered[here] && !finished[there]) {
//	else if (!finished[there]) {
//		ans -= discovered[here] - discovered[there] + 1;
//	}
//
//	finished[here] = 1;
//}
//
//int main() {
//	int tc;
//	scanf("%d", &tc);
//	while (tc--) {
//		init();
//		for (int i = 1; i <= n; i++) {
//			if (discovered[i] == -1)
//				dfs2(i);
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}