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
//		cnt += arr[i] / len; // len �� 1 �̰� arr[i] �� ū ���� �� �� �����Ƿ� cnt �� type�� unsigned int �� �ؾ���.
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
//	//int s = 1, e = max_len; // (s+e) / 2 �� �� s+e ���� �̹� int ���� �Ѿ �� �ִ�(ex> s == 2^30, e == 2^31 - 1). �ش� ���� /2 �ϸ� -������ �����.
//	unsigned int s = 1, e = max_len;
//	int ans = 0;
//	while (s <= e) {
//		int m = (s + e) / 2; // m �� ���� unsigned int �� �� �ص� �� ��. 
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