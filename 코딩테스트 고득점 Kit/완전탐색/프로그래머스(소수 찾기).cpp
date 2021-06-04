#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 10000000

using namespace std;
int answer = 0;
int arr[MAX + 1];

void init() {
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i <= MAX; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= MAX; i++) {
		if (arr[i] == 0) continue;
		for (int j = (i * i); j <= MAX; j += i) {
			arr[j] = 0;
		}
	}
}

int solution(string numbers) {
	init();

	vector<char> v;
	vector<int> nums;

	for (int i = 0; i < numbers.size(); i++) {
		v.push_back(numbers[i]);
	}
	sort(v.begin(), v.end());

	do {
		string tmp = "";
		for (int i = 0; i < v.size(); i++) {
			tmp.push_back(v[i]);
			nums.push_back(stoi(tmp));
		}
		nums.push_back(stoi(tmp));
	} while (next_permutation(v.begin(), v.end()));

	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	for (int i = 0; i < nums.size(); i++) {
		if (arr[nums[i]] != 0) {
			answer++;
		}
	}

	return answer;
}