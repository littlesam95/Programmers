#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
bool answer = true;
int p_cnt = 0;
int y_cnt = 0;

bool solution(string s) {
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] >= 65) && (s[i] <= 90)) {
			s[i] = (char)(int(s[i] + 32));
		}
	}
	for (int i = 0; i < s.length(); i++) {
		if (s.substr(i, 1) == "p") {
			p_cnt++;
		}
		if (s.substr(i, 1) == "y") {
			y_cnt++;
		}
	}

	if (p_cnt != y_cnt) {
		answer = false;
	}
	return answer;
}