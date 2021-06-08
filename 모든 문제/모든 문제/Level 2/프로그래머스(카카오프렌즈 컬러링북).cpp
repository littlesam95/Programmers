#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int arr[101][101];
	bool visited[101][101] = { false, };
	int moveY[4] = { -1,0,1,0 };
	int moveX[4] = { 0,-1,0,1 };
	int big = 0;
	vector<int> answer;
	int res = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = picture[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if ((!visited[i][j]) && (arr[i][j] > 0)) {
				queue<pair<int, int> > q;
				visited[i][j] = true;
				q.push(make_pair(i, j));
				int size = 1;

				while (!q.empty()) {
					int nowY = q.front().first;
					int nowX = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nextY = nowY + moveY[k];
						int nextX = nowX + moveX[k];
						if ((nextY >= 0) && (nextY < m) && (nextX >= 0) && (nextX < n)) {
							if ((!visited[nextY][nextX]) && (arr[nextY][nextX] == arr[i][j])) {
								visited[nextY][nextX] = true;
								size++;
								q.push(make_pair(nextY, nextX));
							}
						}
					}
				};

				big = max(big, size);
				res++;
			}
		}
	}

	answer.push_back(res);
	answer.push_back(big);
	return answer;
}