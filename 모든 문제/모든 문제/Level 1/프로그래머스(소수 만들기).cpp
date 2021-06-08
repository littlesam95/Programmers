#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
int arr[3000];
int answer = 0;

void init() {
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i < 3000; i++) {
		arr[i] = 1;
	}
	for (int i = 2; i <= sqrt(3000); i++) {
		if (arr[i] == 0) continue;
		for (int j = (i * i); j <= 3000; j += i) {
			arr[j] = 0;
		}
	}
}

void dfs(vector<int>&nums, int start, int depth, int sum) {
	if (depth == 3) {
		if (arr[sum]) {
			answer++;
		}
		return;
	}

	for (int i = start; i < nums.size(); i++) {
		dfs(nums, i + 1, depth + 1, sum + nums[i]);
	}
}

int solution(vector<int> nums) {
	init();
	dfs(nums, 0, 0, 0);

	return answer;
}