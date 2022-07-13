#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 10000;
const int INF = 987654321;

int cache[MAX_LEN + 2];

int difficulty(string s) {
	int i;
	for (i = 0; i <= s.size() - 2; i++)
		if (s[i] != s[i + 1]) break;	
	if (i == s.size() - 1) return 1;

	for (i = 0; i <= s.size() - 2; i++) {
		if (s[i + 1] - s[i] != 1) break;
	}
	if (i == s.size() - 1) return 2;

	for (i = 0; i <= s.size() - 2; i++) {
		if (s[i + 1] - s[i] != -1) break;
	}
	if (i == s.size() - 1) return 2;

	for (i = 0; i <= s.size() - 3; i++) {
		if (s[i] != s[i + 2]) break;
	}
	if (i == s.size() - 2) return 4;

	int diff = s[1] - s[0];
	for (i = 0; i <= s.size() - 2; i++)
		if (s[i + 1] - s[i] != diff) break;
	if (i == s.size() - 1) return 5;

	return 10;

}

int totalDifficulty(string &s, int start) {
	if (s.size() == start) return 0;
	if (start > s.size()) return INF;

	int &ret = cache[start];
	if (ret != -1) return ret;

	ret = INF;
	for (int len = 3; len <= 5; len++) {
		int tmp = difficulty(s.substr(start, len)) + totalDifficulty(s, start + len);
		ret = min(ret, tmp);
	}

	return ret;

}

int main() {
	int tc;
	scanf("%d", &tc);
	string s;
	while (tc--) {
 		cin >> s;
		memset(cache, -1, sizeof(cache));
		int ret = totalDifficulty(s, 0);
		printf("%d\n", ret);
	}

	return 0;
}