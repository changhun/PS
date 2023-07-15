#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int compress(string s, int step) {
	int ans = 0, st = 0, dup_count = 1;
	unsigned int cur = step;
	while (cur < s.length()) {
		if (s.substr(st, step) != s.substr(cur, step)) {
			ans += step;
			if (dup_count != 1)
				ans += to_string(dup_count).length();
			st = cur, dup_count = 1;
		}
		else
			dup_count += 1;
		cur += step;
	}

	if (dup_count == 1)
		ans += s.length() - st;
	else
		ans += step + to_string(dup_count).length();

	return ans;
}

int solution(string s) {
	int half = s.length() / 2;
	if (half == 0) half = 1;
	int ans = INF;
	for (int step = 1; step <= half; step++) {
		int ret = compress(s, step);
		if (ret < ans)
			ans = ret;
	}
	return ans;
}

int main() {
	string s = "aabbaccc";
	int ret = solution(s);
	cout << ret << endl;

	return 0;
}