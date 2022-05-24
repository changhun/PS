//#include <stdio.h>
//#include <string.h>
//
///*
// * MOD �� ��� �����鼭 �����ص� ��. MOD ����. 
// * memo �� �ʱⰪ�� INF �� ���� -1�� �ص� ���� ����. -1�� �ص� �������� �ʱ�ȭ �ϱ� ����. �� �������� ã�� ��� INF �� �ؾ��� ��.
// * ������ ������ n == 0 �̸� return 1, n < 0 �̸� return 0 �ص� �� ��. (0 ����� �� ä��Ŵϱ�)
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