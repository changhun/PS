#include <stdio.h>
#include <string.h>

int n;
const int MOD = 10007;
const int MAX_N = 1000;
int memo[MAX_N + 2][MAX_N + 2];

int solve(int len, int start) {
	if (len == 1)
		return 9 - start + 1;
	int &ret = memo[len][start];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = start; i <= 9; i++) {
		ret += solve(len - 1, i);
	}
	ret %= MOD;

	return ret;
}

int main() {
	memset(memo, -1, sizeof(memo));
	scanf("%d", &n);

	int ret = solve(n, 0);
	printf("%d\n", ret);

	return 0;
}