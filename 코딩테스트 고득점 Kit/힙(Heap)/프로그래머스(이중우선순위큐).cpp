#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<int> answer;
priority_queue<int, vector<int>, greater<int> > pq1; // 오름차순 우선순위 큐, top이 최솟값임.
priority_queue<int, vector<int>, less<int> > pq2; // 내림차순 우선순위 큐, top이 최댓값임.
int count_pq = 0;

vector<string> split(string s) {
	vector<string> res;
	string tmp = "";
	int idx = 0;
	while (idx <= s.size()) {
		if ((s[idx] == ' ') || (idx == s.size())) {
			res.push_back(tmp);
			tmp = "";
		}
		else {
			tmp += s[idx];
		}
		idx++;
	};
	return res;
}

vector<int> solution(vector<string> operations) {
	for (int i = 0; i < operations.size(); i++) {
		vector<string> cmd = split(operations[i]);
		if (cmd[0] == "I") {
			int number = stoi(cmd[1]);
			pq1.push(number);
			pq2.push(number);
			count_pq++;
		}
		else if (cmd[0] == "D") {
			if (count_pq > 0) {
				if (cmd[1] == "1") {
					pq2.pop();
				}
				else if (cmd[1] == "-1") {
					pq1.pop();
				}
				count_pq--;
			}

			if (count_pq == 0) {
				while (!pq1.empty()) {
					pq1.pop();
				}
				while (!pq2.empty()) {
					pq2.pop();
				}
			}
		}
	}
	if (count_pq == 0) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(pq2.top());
		answer.push_back(pq1.top());
	}
	return answer;
}