//#include <stdio.h>
//#include <string.h>
//
///*
// * MOD 로 계속 나누면서 관리해도 됨. MOD 성질. 
// * memo 의 초기값을 INF 로 할지 -1로 해도 될지 생각. -1로 해도 괜찮으면 초기화 하기 편함. 더 작은값을 찾는 경우 INF 로 해야할 듯.
// * 끝나는 조건을 n == 0 이면 return 1, n < 0 이면 return 0 해도 될 듯. (0 만들면 다 채운거니까)
// */
//
//const int MAX_N = 1000;
//const int INF = 987654321;
//const int MOD = 10007;
//
//int memo[MAX_N + 2];
//int n;
//void init() {
//	scanf("%d", &n);
//	//for (int i = 0; i <= n; i++) memo[i] = INF;
//	memset(memo, -1, sizeof(memo));
//}
//
//int solve(int len) {
//	if (len == 0) return 1;
//	else if (len < 0) return 0;
//
//	int &ret = memo[len];
//	if (ret != -1) return ret;
//	ret = (solve(len - 1) + 2*solve(len - 2)) % MOD;
//	return ret;
//}
//
//int main() {
//	init();
//	int ret = solve(n);
//	printf("%d\n", ret);
//
//	return 0;
//}