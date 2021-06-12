#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> answer;

vector<int> solution(int n) {
	int arr[1001][1001] = { 0, };
	int input_count = n;
	int move = 1; // move�� 1�̸� �Ʒ�, 2�� ������, 3�̸� ���� �̵��ϸ鼭 input
	int number = 1; // input�� ���ڴ� 1���� ����
	int row_idx = 1; // �� ��ȣ
	int col_idx = 1; // �� ��ȣ
	while (input_count > 0) {
		if (move == 1) {
			for (int i = 0; i < input_count; i++) {
				arr[row_idx][col_idx] = number;
				if (i < input_count - 1) {
					row_idx++;
				}
				number++;
			}
			col_idx++;
		}
		else if (move == 2) {
			for (int i = 0; i < input_count; i++) {
				arr[row_idx][col_idx] = number;
				if (i < input_count - 1) {
					col_idx++;
				}
				number++;
			}
			row_idx--;
			col_idx--;
		}
		else if (move == 3) {
			for (int i = 0; i < input_count; i++) {
				arr[row_idx][col_idx] = number;
				if (i < input_count - 1) {
					row_idx--;
					col_idx--;
				}
				number++;
			}
			row_idx++;
		}
		move++;
		input_count--;
		if (move > 3) {
			move = 1;
		}
	};

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] > 0) {
				answer.push_back(arr[i][j]);
			}
		}
	}

	return answer;
}