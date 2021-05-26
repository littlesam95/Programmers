#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
int answer = 0;
bool b = true;

int solution(vector<int> scoville, int K) {
	for (int i = 0; i < scoville.size(); i++) {
		q.push(scoville.at(i));
	}

	do {
		b = true;
		int sc1 = q.top();
		q.pop();
		int sc2 = q.top();
		q.pop();
		int newSc = sc1 + (sc2 * 2);
		q.push(newSc);
		answer++;

		int size = q.size();
		queue<int> tmp;
		if (size > 1) {
			if (q.top() >= K) {
				b = true;
			}
			else {
				b = false;
			}
		}
		else {
			if (q.top() < K) {
				answer = -1;
				b = true;
			}
		}
	} while (!b);

	return answer;
}