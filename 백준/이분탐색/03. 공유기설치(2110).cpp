#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = (int)2e5;
const int MAX_POS = (int)1e9;


bool is_ok(int C, vector<int> &dist, int pivot) {
	int cnt = 0;
	int s = 0;
	int i;
	
	while (s < dist.size() && cnt < C - 1) {
		int sum = 0;
		for (i = 0; s + i < dist.size() && sum < pivot; i++) {
			sum += dist[s+i];
		}
		if (sum < pivot) return false;
		s += i;
		cnt++;
	}

	if (cnt >= C - 1) return true;

	return false;
}

int solution(int C, vector<int> &dist) {
	// s, e 어떻게 정할지 좀 더 고려해보기
	//int e = MAX_POS;
	int e = accumulate(dist.begin(), dist.end(), 0);
	int s = 1;
	int ans = 0;

	while (s <= e) {
		int m = (s + e) / 2;
		if (is_ok(C, dist, m)) {
			ans = m;
			s = m + 1;
		}
		else {
			e = m - 1;
		}
	}
	return ans;
}

int main() {
	int N, C;
	int a, b;

	scanf("%d %d", &N, &C);
	vector<int> dist(N - 1);
	vector<int> pos(N);

	for (int i = 0; i < N; i++)
		scanf("%d", &pos[i]);
	sort(pos.begin(), pos.end()); // POS 가 정렬되지 않은 데이터임
	for (int i = 0; i < N - 1; i++)
		dist[i] = pos[i + 1] - pos[i];

	int ret = solution(C, dist);
	printf("%d\n", ret);

	return 0;
}