//#include <stdio.h>
//#include <malloc.h>
//#include <string.h>
//
//const int INF = 987654321;
//const int MAX_N = (int)1e6;
//int memo[MAX_N + 2];
//
//int n;
//
//void init() {
//	scanf("%d", &n);
//	//memset(memo, -1, sizeof(memo));
//	for (int i = 0; i <= n; i++) memo[i] = INF;
//}
//
//int dp(int val) {
//	if (val == 1) return 0;
//
//	int &ret = memo[val];
//	int tmp;
//
//	if (ret != INF) return ret;
//	
//	if (val % 3 == 0) {
//		ret = dp(val / 3) + 1;
//	}
//	if (val % 2 == 0) {
//		tmp = dp(val / 2) + 1;
//		ret = tmp < ret ? tmp : ret;
//	}
//	tmp = dp(val - 1) + 1;
//	ret = tmp < ret ? tmp : ret;
//
//	return ret;
//}
//
//int main() {
//	init();
//	int ret = dp(n);
//	printf("%d\n", ret);
//
//	return 0;
//}