#include <stdio.h>

int main() {
	int E, S, M;
	scanf("%d %d %d", &E, &S, &M);
	for (int i = 0; ;i++) {
		int val = 28 * i + S - 1;
		if (val % 15 == E - 1 && val % 19 == M - 1) {
			printf("%d\n", val + 1);
			break;
		}
	}

	return 0;
}