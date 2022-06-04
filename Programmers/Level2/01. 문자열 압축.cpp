#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>

using namespace std;

int length(int val) {
	stringstream ss;
	ss << val;
	string s;
	ss >> s;
	return s.size();
}

int calc(string &str, int len) {
	int ans = 0;
	int s = 0;
	int t = s + len;
	int cnt = 1;

	while (t + len <= str.size()) {
		int i = 0;
		for (; i < len; i++) {
			if (str[s+i] != str[t+i]) break;
		}
		if (i != len) {
			if (cnt >= 2) {
				ans += length(cnt) + len;
			}
			else
				ans += len;
			s = t;
			t = s + len;
			cnt = 1;
		}
		else {
			cnt++;
			t += len;
		}
	}

	if (s != t) {
		if (cnt >= 2)
			ans += length(cnt) + len;
		else
			ans += len;
	}

	ans += str.size() % len;
	return ans;
}


int solution(string s) {
	int answer = s.size();

	int halfLen = s.size() / 2;
	for (int i = 1; i <= halfLen; i++) {
		int ret = calc(s, i);
		if (ret < answer) answer = ret;
	}
	   	 
	return answer;
}

int main() {
	string s;
	int n;
	char buf[10002];
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s;
		int ret = solution(s);
		printf("%d\n", ret);	
	}
	
}