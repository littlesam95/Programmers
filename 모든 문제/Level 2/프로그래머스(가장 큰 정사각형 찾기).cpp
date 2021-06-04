#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int answer = 0;

int solution(vector<vector<int>> board) {
	int row = board.size();
	int col = board[0].size();
	int arr[1001][1001];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i + 1][j + 1] = board[i][j];
		}
	}
	int big = 0;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (arr[i][j] != 0) {
				int small = INT_MAX;
				small = min(small, arr[i - 1][j - 1]);
				small = min(small, arr[i][j - 1]);
				small = min(small, arr[i - 1][j]);
				arr[i][j] = small + 1;
				big = max(big, arr[i][j]);
			}
		}
	}
	answer = big * big;
	return answer;
}