#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
unordered_set<int> s;
vector<int> answer;

vector<int> solution(vector<int> numbers) {
	sort(numbers.begin(), numbers.end());
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			int tmp = numbers[i] + numbers[j];
			s.insert(tmp);
		}
	}

	for (auto w : s) {
		answer.push_back(w);
	}

	sort(answer.begin(), answer.end());

	return answer;
}