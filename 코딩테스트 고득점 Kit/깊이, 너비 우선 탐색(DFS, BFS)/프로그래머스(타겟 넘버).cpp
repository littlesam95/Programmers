#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
queue<pair<int, int> > q;
int start = -1;
int sum = 0;
int res = 0;

int solution(vector<int> numbers, int target) {
	q.push(make_pair(start, sum));
	while (!q.empty()) {
		int nowN = q.front().first;
		int nowSum = q.front().second;
		q.pop();

		if (nowN == numbers.size() - 1) {
			if (nowSum == target) {
				res++;
			}
		}
		else {
			q.push(make_pair(nowN + 1, nowSum + numbers[nowN + 1]));
			q.push(make_pair(nowN + 1, nowSum - numbers[nowN + 1]));
		}
	};

	return res;
}