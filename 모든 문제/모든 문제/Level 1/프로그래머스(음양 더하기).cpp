#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
int answer = 0;

int solution(vector<int> absolutes, vector<bool> signs) {
	for (int i = 0; i < signs.size(); i++) {
		if (signs[i]) {
			answer += absolutes[i];
		}
		else {
			answer -= absolutes[i];
		}
	}

	return answer;
}