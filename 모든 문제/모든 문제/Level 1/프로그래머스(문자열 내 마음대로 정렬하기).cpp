#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
vector<string> answer;
int index;

bool comp(string A, string B) {
	if (A.substr(index, 1) == B.substr(index, 1)) {
		return A < B;
	}
	return A.substr(index, 1) < B.substr(index, 1);
}

vector<string> solution(vector<string> strings, int n) {
	index = n;
	sort(strings.begin(), strings.end(), comp);
	for (auto w : strings) {
		answer.push_back(w);
	}

	return answer;
}