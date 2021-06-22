#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
long long answer = 0;

long long solution(int n, vector<int> works) {
	priority_queue<int> pq;
	for (int i = 0; i < works.size(); i++) {
		pq.push(works[i]);
	}

	while (n--) {
		if (pq.empty()) break;
		int top = pq.top();
		pq.pop();
		top--;
		if (top > 0) {
			pq.push(top);
		}
	};
	while (!pq.empty()) {
		answer += (pq.top() * pq.top());
		pq.pop();
	}

	return answer;
}