#include <stdio.h>

typedef unsigned long long ULL;

enum FUNC_TYPE {
	MIN,
	MAX
};
const int MAX_N = (int)1e5;

bool min(int a, int b) {
	return a < b;
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

typedef struct {
	int hn;
	int heap[MAX_N + 2];

	bool(*comp)(int, int);

	void init(FUNC_TYPE type) {
		if (type == MIN) comp = min;
		hn = 0;
	}

	bool empty() {
		return hn == 0;
	}

	void push_heap(int val) {
		heap[++hn] = val;
		int p = hn / 2, c = hn;
		while (p >= 1 && comp(heap[c], heap[p])) {
			swap(heap[p], heap[c]);
			p /= 2;
			c /= 2;
		}
	}

	int pop_heap() {
		swap(heap[1], heap[hn--]);
		int p = 1, c = 2;
		while (c <= hn) {
			if (c + 1 <= hn && comp(heap[c + 1], heap[c]))
				c++;
			if (!comp(heap[c], heap[p])) break;
			swap(heap[c], heap[p]);
			p = c;
			c *= 2;
		}
		return heap[hn + 1];
	}

	int top() {
		return heap[1];
	}

}PriorityQueue;

PriorityQueue pq;
int n;
ULL ans;

void init() {
	ans = 0;
	pq.init(MIN);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		pq.push_heap(tmp);
	}
}

// 카드 하나면 답이 0 인가?
void solve() {
	for (int i = 0; i < n - 1; i++) {
		int a = pq.pop_heap();
		int b = pq.pop_heap();
		ans += a + b;
		pq.push_heap(a + b);
	}
	printf("%d\n", ans);
}

int main() {
	init();
	solve();

	return 0;
}