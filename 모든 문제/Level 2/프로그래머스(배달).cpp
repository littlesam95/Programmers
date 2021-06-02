#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2147483647

using namespace std;
int answer = 0;

int solution(int N, vector<vector<int> > road, int K) {
	vector<vector<pair<int, int> > > vec(N + 1);
	for (auto w : road) {
		vec[w[0]].push_back(make_pair(w[1], w[2]));
		vec[w[1]].push_back(make_pair(w[0], w[2]));
	}

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	vector<int> dist(N + 1, INF);
	dist[1] = 0;

	pq.push(make_pair(0, 1));

	while (!pq.empty()) {
		int hour = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (hour > dist[node]) {
			continue;
		}

		for (int i = 0; i < vec[node].size(); i++) {
			int newHour = vec[node][i].second;
			int newNode = vec[node][i].first;

			if (dist[newNode] > dist[node] + newHour) {
				dist[newNode] = dist[node] + newHour;
				pq.push(make_pair(newHour, newNode));
			}

		}
	};

	for (int i = 1; i < dist.size(); i++) {
		if (dist[i] <= K) {
			answer++;
		}
	}

	return answer;
}