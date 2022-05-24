//#include <stdio.h>
//#include <vector>
//#include <string.h>
//
//using namespace std;
//
//const int MAX_N = 1000;
//
//vector<vector<int> >adj;
//int n, m;
//int visited[MAX_N + 2];
//
//void init() {
//	int a, b;
//	scanf("%d %d", &n, &m);
//	adj = vector<vector<int> >(n + 2);
//	for (int i = 0; i < m; i++) {
//		scanf("%d %d", &a, &b);
//		adj[a].push_back(b);
//		adj[b].push_back(a);
//	}
//
//	memset(visited, 0, sizeof(visited));
//}
//
//void dfs(int here) {
//	if (visited[here]) return;
//	visited[here] = true;
//
//	for (int i = 0; i < adj[here].size(); i++) {
//		int there = adj[here][i];
//		dfs(there);
//	}
//}
//
//int main() {
//	init();
//	int cnt = 0;
//	for (int i = 1; i <= n; i++) {
//		if (!visited[i]) {
//			cnt++;
//			dfs(i);
//		}
//	}
//
//	printf("%d\n", cnt);
//
//	return 0;
//}