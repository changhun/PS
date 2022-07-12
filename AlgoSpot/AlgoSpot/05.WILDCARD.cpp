#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 100;
//#define MAX_LEN 100

int cache[MAX_LEN + 2][MAX_LEN + 2];


int wildCard(string &a, string &b, int sa, int sb);

int main() {
	int tc;

	scanf("%d", &tc);
	while (tc--) {
		int n;
		char wild[MAX_LEN + 2];
		char filename[MAX_LEN + 2];
		string a, b;

		getchar();
		scanf("%s", &wild);
		a = string(wild);
		scanf("%d", &n);
		vector<string> ans;
		for (int i = 0; i < n; i++) {
			getchar();
			scanf("%s", &filename);
			b = string(filename);
			memset(cache, -1, sizeof(cache));
			int ret = wildCard(a, b, 0, 0);
			//if (ret)
			//	printf("%s\n", filename);
			if (ret)
				ans.push_back(b);
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << endl;
	}
	return 0;
}


int wildCard(string &a, string &b, int sa, int sb) {
	if (sa == a.size() && sb == b.size())
		return 1;
	if (sa == a.size()) return 0;
	//if (sb == b.size()) return false;

	//if (sb == b.size()) {
	//	if (a[sa] != '*') return false;
	//}

	if (sb == b.size()) {
		for (int i = sa; i < a.size(); i++) {
			//if (a[sa] != '*') return 0; // 여기 실수해서 틀림
			if (a[i] != '*') return 0;
		}
		return 1;
	}

	int &ret = cache[sa][sb];
	if (ret != -1) return ret;

	ret = 0;

	if (a[sa] == '*') {
		for (int next = sb; next <= b.size(); next++) {
			ret = wildCard(a, b, sa + 1, next);
			if (ret == 1)
				return 1;
		}
	}
	
	//if (sb == b.size()) return false;

	if (a[sa] != b[sb] && a[sa] != '?' && a[sa] != '*') 
		return ret = 0;

	ret = wildCard(a, b, sa + 1, sb + 1);

	return ret;
}