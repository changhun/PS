#include <vector>
//#include <bits/stdc++.h>
const int INF = int(1e9);

using namespace std;

int max(int a, int b) {
	if (a >= b)
		return a;
	return b;
	
}

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int ans = 0;
		int min_price = INF;
		for (int i = 0; i < prices.size(); i++) {
			if (prices[i] < min_price) {
				min_price = prices[i];
			}
			ans = max(ans, prices[i] - min_price);
		}
		return ans;
	}

};

int main() {
	Solution sol;
	vector<int> prices = { 7,1,5,3,6,4 };
	int ret = sol.maxProfit(prices);
	printf("%d\n", ret);

	return 0;
}