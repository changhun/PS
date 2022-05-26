#include <stdio.h>
#include <string.h>
typedef long long LL;
const int MAX_N = 90;

LL memo[MAX_N+2][2];

void init() {
	memset(memo, -1, sizeof(memo));
}

LL li_chin_su(int len, int val) {
	if (len == 1 || len == 0) return 1;
	LL &ret = memo[len][val];
	if (ret != -1) return ret;


	ret = li_chin_su(len - 1, 0);
	if (val == 0) {
		//ret += li_chin_su(len - 1, 1);
		ret += li_chin_su(len - 2, 0);
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
	init();
	LL ret = li_chin_su(n, 1);
	printf("%lld\n", ret);

	return 0;
}