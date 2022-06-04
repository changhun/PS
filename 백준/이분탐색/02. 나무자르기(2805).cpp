//#include <stdio.h>
//#include <bits/stdc++.h>
//
//using namespace std;
//
//const int MAX_N = (int)1e6;
//const int MAX_M = (int)2e9;
//const int MAX_H = (int)1e9;
//
//
//
//int maxH = -1;
//
//bool is_ok(int targetSum, vector<int> &heights, int height) {
//	//int sum = 0; // �뵵�� �°� ���� type �� �����ϱ�. ���� ���ǹ����� �����ϴ� �κ� �ۼ� �� �� �Ÿ� long long ���� �������.
//	long long sum = 0; // �����غ��� targetSum �� �ִ밪�� 2*10^9 �̴�. sum �� 2*10^9 - 1 ���� ���¿��� �ϳ� �� ���ϸ� int �Ѿ�� �ִ�.
//	for (auto& h : heights) { // range based for ������
//		if (h > height) {
//			sum += h - height;
//			if (sum >= targetSum)
//				return true;
//		}
//	}
//	return false;
//}
//
//int solution(int targetSum, vector<int> &heights) {
//	int s = 0;
//	//int e = maxH - 1; // vector.max ������ ã�ƺ���
//	int e = *max_element(heights.begin(), heights.end()); // �ּҰ��� min_element
//	int ans = -1;
//
//	while (s <= e) {
//		int m = (s + e) / 2;
//		if (is_ok(targetSum, heights, m)) {
//			ans = m;
//			s = m + 1;
//		}
//		else {
//			e = m - 1;
//		}
//	}
//	return ans;
//}
//
//int main() {
//	int N, M;
//	
//	scanf("%d %d", &N, &M);
//	vector<int> heights(N);
//
//	for (int i = 0; i < N; i++) {
//		scanf("%d", &heights[i]);
//		if (heights[i] > maxH) maxH = heights[i];
//	}
//
//	int ret = solution(M, heights);
//	printf("%d\n", ret);
//
//	return 0;
//}