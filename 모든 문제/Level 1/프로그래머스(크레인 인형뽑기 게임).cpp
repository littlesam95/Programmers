#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
stack<int> s;
int answer = 0;

int solution(vector<vector<int>> board, vector<int> moves) {
	int count = moves.size();
	int index = 0;
	int size = board.size();
	while (count--) {
		for (int i = 0; i < size; i++) {
			if (board[i][moves[index] - 1] == 0) {
				continue;
			}
			else {
				if (s.empty()) {
					s.push(board[i][moves[index] - 1]);
				}
				else {
					if (s.top() == board[i][moves[index] - 1]) {
						s.pop();
						answer += 2;
					}
					else {
						s.push(board[i][moves[index] - 1]);
					}
				}
				board[i][moves[index] - 1] = 0;
				break;
			}
		}
		index++;
	};

	return answer;
}