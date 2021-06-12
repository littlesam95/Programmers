#include <string>
#include <vector>
#include <deque>
#include <climits>
#include <algorithm>

using namespace std;
vector<int> answer;
int arr[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	int num = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			arr[i][j] = num;
			num++;
		}
	}

	for (int i = 0; i < queries.size(); i++) {
		int startY = queries[i][0] - 1;
		int startX = queries[i][1] - 1;
		int endY = queries[i][2] - 1;
		int endX = queries[i][3] - 1;
		deque<int> q;
		for (int j = startX; j <= endX; j++) {
			q.push_back(arr[startY][j]);
		}
		for (int j = startY + 1; j <= endY; j++) {
			q.push_back(arr[j][endX]);
		}
		for (int j = endX - 1; j >= startX; j--) {
			q.push_back(arr[endY][j]);
		}
		for (int j = endY - 1; j >= startY; j--) {
			q.push_back(arr[j][startX]);
		}
		q.push_front(q.back());
		q.pop_back();
		int small = INT_MAX;
		for (int j = startX; j <= endX; j++) {
			arr[startY][j] = q.front();
			small = min(q.front(), small);
			q.pop_front();
		}
		for (int j = startY + 1; j <= endY; j++) {
			arr[j][endX] = q.front();
			small = min(q.front(), small);
			q.pop_front();
		}
		for (int j = endX - 1; j >= startX; j--) {
			arr[endY][j] = q.front();
			small = min(q.front(), small);
			q.pop_front();
		}
		for (int j = endY - 1; j >= startY; j--) {
			arr[j][startX] = q.front();
			small = min(q.front(), small);
			q.pop_front();
		}
		answer.push_back(small);
	}

	return answer;
}