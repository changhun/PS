#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e4 + 2;


int getMaxRect(vector<int>& fence, int s, int e) {
	if (s == e)
		return fence[s];

	int m = (s + e) / 2;
	int leftRet = getMaxRect(fence, s, m);
	int rightRet = getMaxRect(fence, m+1, e);

	int left = m;
	int right = m + 1;
	int minHeight = min(fence[left], fence[right]);

	int ret = max(leftRet, rightRet);
	ret = max(ret, minHeight * 2);
	while (s < left || right < e) {
		if (left == s)
			right++;
		else if (right == e)
			left--;
		else {
			if (fence[left - 1] > fence[right + 1])
				left--;
			else
				right++;
		}
		minHeight = min(minHeight, fence[left]);
		minHeight = min(minHeight, fence[right]);
		ret = max(ret, minHeight * (right - left + 1));
	}
	return ret;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		vector<int> fence = vector<int>(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &fence[i]);

		int ret = getMaxRect(fence, 0, n - 1);
		printf("%d\n", ret);
	}

	return 0;
}