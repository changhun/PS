//#include <stdio.h>
//#include <algorithm>
//#include <string.h>
//// sort 함수 사용하려고 해도 namespace std 사용해야하나? sort 가 해당 namespace 에 들어있나? 맞음.
//const int MAX_N = 1000;
//
//
//int discovered[MAX_N + 2];
//int finished[MAX_N + 2];
//int n;
//int arr[MAX_N + 2];
//int sorted[MAX_N + 2];
//int adj[MAX_N + 2];
//int seq; // node visit sequence
//int cnt; // cycle count
//
//void init() {
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &arr[i]);
//		sorted[i] = arr[i];
//	}
//
//	std::sort(&sorted[1], &sorted[n+1]);
//	for (int i = 1; i <= n; i++) {
//		int u, v;
//		u = arr[i];
//		v = sorted[i];
//		adj[u] = v;
//	}
//
//	memset(discovered, -1, sizeof(discovered));
//	memset(finished, 0, sizeof(finished));
//
//	seq = cnt = 0;
//}
//
//
//void dfs2(int here) {
//	discovered[here] = seq++;
//
//	int there = adj[here];
//	if (discovered[there] == -1)
//		dfs2(there);
//	//else if (discovered[there] < discovered[here])
//	else if (!finished[there]){
//		cnt++;
//	}
//
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
//		printf("%d\n", cnt);
//	}
//
//	return 0;
//}