#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
int answer = 0;
int arr[10001];
unordered_set<int> s;

int solution(vector<int> nums) {
	for (int i = 0; i < nums.size(); i++) {
		s.insert(nums[i]);
	}
	if (s.size() >= nums.size() / 2) {
		answer = nums.size() / 2;
	}
	else {
		answer = s.size();
	}
	return answer;
}