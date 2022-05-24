//#include <stdio.h>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//
//
//int a, p;
//
//int nextNum(int cur, int n_repeat) {
//	int sum = 0;
//	while (cur > 0) {
//		int val = cur % 10;
//		int val2 = 1;
//		for (int i = 0; i < n_repeat; i++)
//			val2 *= val;
//		sum += val2;
//		cur /= 10;
//	}
//	return sum;
//}
//
//int main() {
//	scanf("%d %d", &a, &p);
//	map<int, int> m;
//	int cnt = 1;
//
//	while (m[a] == 0) {
//		m[a] = cnt++;
//		a = nextNum(a, p);
//	}
//	printf("%d\n", m[a] - 1);
//	return 0;
//}