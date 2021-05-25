#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
unordered_map<string, int> m;

int solution(vector<vector<string>> clothes) {
	for (int i = 0; i < clothes.size(); i++) {
		if (m[clothes[i][1]] == 0) {
			m[clothes[i][1]] = 1;
		}
		else if (m[clothes[i][1]] > 0) {
			m[clothes[i][1]]++;
		}
	}

	int sum = 1;
	for (auto w : m) {
		sum *= (w.second + 1);
	}

	return sum - 1;
}