//#include <stdio.h>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//const int MAX_N = 1000;
//const int MAX_M = (int)1e4;
//
//vector<vector<int> >adj;
//int start;
//int n, m;
//
//// 여기선 굳이 구조체 사용할 필요 없음.
//#if 0
//struct Queue {
//	int node;
//}que[MAX_N + 2];
//int rp, wp;
//
//void push(int val) {
//	//que[wp++] = val;
//	que[wp++] = { val }; // 문법 확인하기
//}
//
//int front() {
//	return que[rp++];
//}
//#else
//int que[MAX_N + 2];
//int rp, wp;
//
//void push(int val) {
//	que[wp++] = val;
//}
//
//int pop() {
//	return que[rp++];
//}
//
//bool empty() {
//	return rp >= wp;
//}
//
//#endif
//int touched[MAX_N + 2];
//int visited[MAX_N + 2];
//
///* 노드 n 을 인덱스 n 에 저장할 지 아니면 n-1 에 저장할 지 생각하기 */
//
//
//void init() {
//	scanf("%d %d %d", &n, &m, &start);
//	//adj = vector<vector<int> >(n + 1, vector<int>(0));
//	adj = vector<vector<int> >(n + 1);
//	for (int i = 0; i < m; i++) {
//		int a, b;
//		scanf("%d %d", &a, &b);
//		adj[a].push_back(b);
//		adj[b].push_back(a);
//	}
//	for (int i = 1; i <= n; i++)
//		sort(adj[i].begin(), adj[i].end());
//
//	memset(touched, 0, sizeof(touched));
//	memset(visited, 0, sizeof(visited));
//	// Init Queue
//	rp = wp = 0;
//}
//
//
//void bfs(int start) {
//	push(start);
//	touched[start] = 1; // 여기서 하는 게 맞는지?
//
//	while (!empty()) {
//		int here = pop();
//		printf("%d ", here);
//
//		for (int i = 0; i < adj[here].size(); i++) {
//			int there = adj[here][i];
//			if (touched[there]) continue;
//			touched[there] = 1;
//			push(there);
//		}
//	}
//}
//
//void dfs(int here) {
//	if (visited[here]) return;
//	visited[here] = 1;
//	printf("%d ", here);
//
//	for (int i = 0; i < adj[here].size(); i++) {
//		int there = adj[here][i];
//		dfs(there);
//	}
//
//	// visited[here] = 0; // 리턴시 설정 해줘야 함?
//}
//
//int main() {
//	init();
//	dfs(start);
//	puts("");
//	bfs(start);
//
//	return 0;
//}