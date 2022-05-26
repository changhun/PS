/* 	count_stairs ���� �κп��� if (val < 0 || val > 9) return 0; �� ���� ������ �ƴϸ�
 *	count_stairs ȣ�� �ϴ� ������ val < 0 || val > 9 �� �Ÿ� ������ �����ؾ� �Ѵ�.
 */

#include <stdio.h>
#include <string.h>

typedef long long  LL;
const int MAX_N = 100;
const int MOD = (int)1e9;

LL memo[MAX_N + 2][10];
int n;

void init() {
	memset(memo, -1, sizeof(memo));
	scanf("%d", &n);
}

int count_stairs(int len, int val) {
	if (val < 0 || val > 9) return 0;
	if (len == 1) return 1;

	LL &ret = memo[len][val];
	if (ret != -1) return ret;

	ret = 0;
	//if (val - 1 >= 0) ret += count_stairs(len - 1, val - 1);
	//if (val + 1 <= 9) ret += count_stairs(len - 1, val + 1);
	ret += count_stairs(len - 1, val - 1);
	ret += count_stairs(len - 1, val + 1);
	ret %= MOD;
	return ret;
}

int main() {
	init();
	LL ret = 0;
	for (int i = 1; i <= 9; i++) {
		ret += count_stairs(n, i);
	}
	ret %= MOD;

	printf("%lld\n", ret);
	return 0;
}