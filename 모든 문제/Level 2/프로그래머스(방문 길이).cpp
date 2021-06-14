#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;
int move_road[11][11][11][11] = { 0, };

int solution(string dirs) {
	int idx = 0;
	int nowY = 5;
	int nowX = 5;
	while (idx < dirs.size()) {
		if (dirs[idx] == 'U') {
			if ((nowY - 1 >= 0) && (nowY - 1 < 11)) {
				if (move_road[nowY][nowX][nowY - 1][nowX] == 0) {
					move_road[nowY][nowX][nowY - 1][nowX] = 1;
					move_road[nowY - 1][nowX][nowY][nowX] = 1;
					answer++;
				}
				nowY--;
			}
		}
		if (dirs[idx] == 'D') {
			if ((nowY + 1 >= 0) && (nowY + 1 < 11)) {
				if (move_road[nowY][nowX][nowY + 1][nowX] == 0) {
					move_road[nowY][nowX][nowY + 1][nowX] = 1;
					move_road[nowY + 1][nowX][nowY][nowX] = 1;
					answer++;
				}
				nowY++;
			}
		}
		if (dirs[idx] == 'L') {
			if ((nowX - 1 >= 0) && (nowX - 1 < 11)) {
				if (move_road[nowY][nowX][nowY][nowX - 1] == 0) {
					move_road[nowY][nowX - 1][nowY][nowX] = 1;
					move_road[nowY][nowX][nowY][nowX - 1] = 1;
					answer++;
				}
				nowX--;
			}
		}
		if (dirs[idx] == 'R') {
			if ((nowX + 1 >= 0) && (nowX + 1 < 11)) {
				if (move_road[nowY][nowX][nowY][nowX + 1] == 0) {
					move_road[nowY][nowX + 1][nowY][nowX] = 1;
					move_road[nowY][nowX][nowY][nowX + 1] = 1;
					answer++;
				}
				nowX++;
			}
		}
		idx++;
	};

	return answer;
}