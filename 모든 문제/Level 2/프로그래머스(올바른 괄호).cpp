#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool answer = true;

bool solution(string s) {
	int st_count = 0;
	for (int i = 0; i < s.size(); i++) { // ���ڿ��� ���� ���� char������ ó���ؾ� �ð��ʰ��� �� �ɸ�.
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