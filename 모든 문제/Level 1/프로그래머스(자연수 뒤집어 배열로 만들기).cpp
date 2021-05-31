#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
vector<int> answer;

vector<int> solution(long long n) {
	string str = to_string(n);
	reverse(str.begin(), str.end());
	for (int i = 0; i < str.length(); i++) {
		answer.push_back(stoi(str.substr(i, 1)));
	}

	return answer;
}