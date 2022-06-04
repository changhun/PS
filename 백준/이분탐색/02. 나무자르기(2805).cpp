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
//	//int sum = 0; // 용도에 맞게 변수 type 잘 설정하기. 만약 조건문으로 리턴하는 부분 작성 안 할 거면 long long 으로 해줘야함.
//	long long sum = 0; // 생각해보니 targetSum 의 최대값이 2*10^9 이다. sum 이 2*10^9 - 1 값인 상태에서 하나 더 더하면 int 넘어갈수 있다.
//	for (auto& h : heights) { // range based for 익히기
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
//	//int e = maxH - 1; // vector.max 같은거 찾아보기
//	int e = *max_element(heights.begin(), heights.end()); // 최소값은 min_element
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