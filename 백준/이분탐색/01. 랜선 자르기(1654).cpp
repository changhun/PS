//#include <stdio.h>
//#include <bits/stdc++.h>
//
//using namespace std;
//
//const int MAX_K = (int)1e4;
//const int MAX_N = (int)1e6;
//
//int arr[MAX_K + 2];
//int n, k;
//int max_len;
//
//bool is_ok(int *arr, int k, int n, int len) {
//	//int cnt = 0;
//	unsigned int cnt = 0;
//	for (int i = 0; i < k; i++) {
//		cnt += arr[i] / len; // len 이 1 이고 arr[i] 가 큰 값일 수 도 있으므로 cnt 의 type을 unsigned int 로 해야함.
//		if (cnt >= n) return true;
//	}
//	return false;
//}
//
//int main() {	
//	scanf("%d %d", &k, &n);
//	for (int i = 0; i < k; i++) {
//		scanf("%d", &arr[i]);
//		max_len = max_len > arr[i] ? max_len : arr[i];
//	}
//
//
//	//int s = 1, e = max_len; // (s+e) / 2 할 때 s+e 에서 이미 int 범위 넘어갈 수 있다(ex> s == 2^30, e == 2^31 - 1). 해당 값을 /2 하면 -값으로 저장됨.
//	unsigned int s = 1, e = max_len;
//	int ans = 0;
//	while (s <= e) {
//		int m = (s + e) / 2; // m 은 굳이 unsigned int 로 안 해도 될 듯. 
//
//		if (is_ok(arr, k, n, m)) {
//			ans = m;
//			s = m + 1;
//		}
//		else {
//			e = m - 1;
//		}
//	}
//	printf("%d\n", ans);
//	return 0;
//}