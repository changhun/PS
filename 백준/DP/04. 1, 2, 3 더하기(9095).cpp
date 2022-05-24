#include <stdio.h>
#include <string.h>

const int MAX_N = 11;
int memo[MAX_N + 2];

int count_ways(int n) {
	if (n == 1) return 1;
	else if (n == 2) return 2;
	else if (n == 3) return 4;

	int &ret = memo[n];
	if (ret != -1) return ret;

	ret = count_ways(n - 1) + count_ways(n - 2) + count_ways(n - 3);
	return ret;	
}

int main() {
	memset(memo, -1, sizeof(memo));

	int tc, n;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		int ret = count_ways(n);
		printf("%d\n", ret);
	}
	return 0;
}