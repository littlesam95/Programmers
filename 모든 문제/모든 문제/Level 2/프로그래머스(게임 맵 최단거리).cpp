#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int answer = 0;

int solution(vector<vector<int> > maps) {
	int arr[101][101];
	for (int i = 0; i < maps.size(); i++) {
		for (int j = 0; j < maps[i].size(); j++) {
			arr[i][j] = maps[i][j];
		}
	}
	int res = INT_MAX;
	bool visited[101][101] = { false, };
	int moveY[4] = { -1,0,1,0 };
	int moveX[4] = { 0,-1,0,1 };

	queue<pair<pair<int, int>, int> > q;
	visited[0][0] = true;
	q.push(make_pair(make_pair(0, 0), 1));

	while (!q.empty()) {
		int nowY = q.front().first.first;
		int nowX = q.front().first.second;
		int nowSize = q.front().second;
		q.pop();

		if ((nowY == maps.size() - 1) && (nowX == maps[0].size() - 1)) {
			res = min(res, nowSize);
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + moveY[i];
			int nextX = nowX + moveX[i];
			if ((nextY >= 0) && (nextY < maps.size()) && (nextX >= 0) && (nextX < maps[0].size())) {
				if ((!visited[nextY][nextX]) && (arr[nextY][nextX] == 1)) {
					visited[nextY][nextX] = true;
					q.push(make_pair(make_pair(nextY, nextX), nowSize + 1));
				}
			}
		}
	};

	if (res == INT_MAX) {
		answer = -1;
	}
	else {
		answer = res;
	}

	return answer;
}