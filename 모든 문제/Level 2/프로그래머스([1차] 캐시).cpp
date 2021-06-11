#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;
int answer = 0;

int solution(int cacheSize, vector<string> cities) {
	for (int i = 0; i < cities.size(); i++) {
		for (int j = 0; j < cities[i].size(); j++) {
			if ((int(cities[i][j] >= 97)) && (int(cities[i][j] <= 122))) {
				cities[i][j] = (char)(int(cities[i][j]) - 32);
			}
		}
	}

	queue<string> q;
	unordered_map<string, int> m;
	int index = 0;
	if (cacheSize > 0) {
		while (index < cities.size()) {
			if (q.size() < cacheSize) {
				if (m.find(cities[index]) == m.end()) {
					q.push(cities[index]);
					m.insert(make_pair(cities[index], 1));
					answer += 5;
				}
				else if (m.find(cities[index]) != m.end()) {
					int size = q.size();
					while (size--) {
						if (q.front() != cities[index]) {
							q.push(q.front());
							q.pop();
						}
						else {
							q.pop();
						}
					};
					q.push(cities[index]);
					answer++;
				}
			}
			else {
				if (m.find(cities[index]) == m.end()) {
					m.erase(q.front());
					q.pop();
					q.push(cities[index]);
					m.insert(make_pair(cities[index], 1));
					answer += 5;
				}
				else if (m.find(cities[index]) != m.end()) {
					int size = q.size();
					while (size--) {
						if (q.front() != cities[index]) {
							q.push(q.front());
							q.pop();
						}
						else {
							q.pop();
						}
					};
					q.push(cities[index]);
					answer++;
				}
			}
			index++;
		};
	}
	else {
		answer = (cities.size()) * 5;
	}

	return answer;
}