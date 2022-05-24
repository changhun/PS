#include <stdio.h>
#include <vector>
#include <algorithm>

#if 0
using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	vector<int>seq(n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		seq[i] = tmp;
	}

	sort(seq.begin(), seq.end());
	for (int i = 0; i < n; i++)
		printf("%d\n", seq[i]);
}

int main() {
	solve();

	return 0;
}
#endif

#if 0
const int MAX_N = (int)1e6;
int arr[MAX_N];
int tmp[MAX_N];

void merge_sort(int s, int e) {
	if (s == e) return;

	int m = (s + e) / 2;
	merge_sort(s, m);
	merge_sort(m+1, e);
	int i = s, j = m+1;
	int k = s;
	while (i <= m && j <= e) {
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while (i <= m) tmp[k++] = arr[i++];
	while (j <= e) tmp[k++] = arr[j++];
	for (k = s; k <= e; k++) {
		arr[k] = tmp[k];
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	merge_sort(0, n - 1);
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);

}
#endif

#if 1 // priority_queue

#include <queue>
#include <deque>
using namespace std;

int main() {
	int n;
	int tmp;
	scanf("%d", &n);
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		pq.push(tmp);
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", pq.top());
		pq.pop();
	}
}

#endif
