#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;

int solution(int m, int n, vector<string> board) {
	while (1) {
		bool b = false;
		vector<pair<int, int> > vec;
		for (int i = 0; i < (m - 1); i++) {
			for (int j = 0; j < (n - 1); j++) {
				if ((board[i][j] != '0') && (board[i][j] == board[i][j + 1])
					&& (board[i][j] == board[i + 1][j]) && (board[i][j] == board[i + 1][j + 1])) {
					b = true;
					vec.push_back(make_pair(i, j));
					vec.push_back(make_pair(i + 1, j));
					vec.push_back(make_pair(i, j + 1));
					vec.push_back(make_pair(i + 1, j + 1));
				}
			}
		}
		if (b) {
			for (int i = 0; i < vec.size(); i++) {
				board[vec[i].first][vec[i].second] = '0';
			}
			for (int i = m - 1; i >= 0; i--) {
				for (int j = 0; j < n; j++) {
					if (board[i][j] == '0') {
						for (int k = i; k >= 0; k--) {
							if (board[k][j] != '0') {
								char tmp = board[k][j];
								board[k][j] = '0';
								board[i][j] = tmp;
								break;
							}
						}
					}
				}
			}
		}
		else {
			break;
		}
	};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '0') {
				answer++;
			}
		}
	}

	return answer;
}