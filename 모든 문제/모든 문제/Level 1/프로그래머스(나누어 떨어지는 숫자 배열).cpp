#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
vector<int> answer;

vector<int> solution(vector<int> arr, int divisor) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] % divisor == 0) {
			answer.push_back(arr[i]);
		}
	}

	if (answer.size() > 0) {
		sort(answer.begin(), answer.end());
	}
	else if (answer.size() == 0) {
		answer.push_back(-1);
	}

	return answer;
}