#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool answer = true;

bool solution(string s) {
	int st_count = 0;
	for (int i = 0; i < s.size(); i++) { // 문자열로 하지 말고 char형으로 처리해야 시간초과가 안 걸림.
		if (s[i] == '(') {
			st_count++;
		}
		else if (s[i] == ')') {
			st_count--;
		}
		if (st_count < 0) {
			return false;
		}
	}
	if (st_count > 0) {
		return false;
	}

	return answer;
}