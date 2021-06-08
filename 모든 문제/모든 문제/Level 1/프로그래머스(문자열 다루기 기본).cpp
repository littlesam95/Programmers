#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
bool answer = false;

bool solution(string s) {
	if ((s.size() == 4) || (s.size() == 6)) {
		answer = true;
	}
	else {
		answer = false;
	}
	if (answer) {
		for (int i = 0; i < s.size(); i++) {
			if ((s[i] < 48) || (s[i] > 57)) {
				answer = false;
				break;
			}
		}
	}

	return answer;
}