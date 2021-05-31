#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
vector<int> answer;
int small = INT_MAX;
int index = 0;

vector<int> solution(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] < small) {
			small = arr[i];
			index = i;
		}
	}
	arr.erase(arr.begin() + index);
	if (arr.empty()) {
		answer.push_back(-1);
	}
	else {
		for (auto w : arr) {
			answer.push_back(w);
		}
	}

	return answer;
}