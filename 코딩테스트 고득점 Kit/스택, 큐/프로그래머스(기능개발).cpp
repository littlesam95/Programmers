#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<int> answer;
queue<pair<int, int> > q;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	for (int i = 0; i < progresses.size(); i++) {
		q.push(make_pair(progresses[i], speeds[i]));
	}
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			if (q.front().first < 100) {
				if (q.front().first + q.front().second < 100) {
					q.push(make_pair(q.front().first + q.front().second, q.front().second));
					q.pop();
				}
				else {
					q.push(make_pair(100, q.front().second));
					q.pop();
				}
			}
			else {
				q.push(make_pair(q.front().first, q.front().second));
				q.pop();
			}
		}
		int hundred_cnt = 0;
		for (int i = 0; i < size; i++) {
			if (q.front().first == 100) {
				q.pop();
				hundred_cnt++;
			}
		}
		if (hundred_cnt > 0) {
			answer.push_back(hundred_cnt);
		}
	};
	return answer;
}