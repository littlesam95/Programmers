#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
int arr1[10001];
int arr2[10001];
int arr3[10001];
int cor1 = 0;
int cor2 = 0;
int cor3 = 0;
int big = 0;
vector<int> answer;

void init() {
	for (int i = 1; i < 10001; i++) {
		if (i % 5 == 1) {
			arr1[i] = 1;
		}
		else if (i % 5 == 2) {
			arr1[i] = 2;
		}
		else if (i % 5 == 3) {
			arr1[i] = 3;
		}
		else if (i % 5 == 4) {
			arr1[i] = 4;
		}
		else if (i % 5 == 0) {
			arr1[i] = 5;
		}
	}
	for (int i = 0; i < 10000; i += 8) {
		for (int j = 1; j <= 8; j++) {
			if (j % 2 == 1) {
				arr2[i + j] = 2;
			}
			else if (j == 2) {
				arr2[i + j] = 1;
			}
			else if (j == 4) {
				arr2[i + j] = 3;
			}
			else if (j == 6) {
				arr2[i + j] = 4;
			}
			else if (j == 8) {
				arr2[i + j] = 5;
			}
		}
	}
	for (int i = 0; i < 10000; i += 10) {
		for (int j = 1; j <= 10; j += 2) {
			if (j == 1) {
				arr3[i + j] = 3;
				arr3[i + j + 1] = 3;
			}
			if (j == 3) {
				arr3[i + j] = 1;
				arr3[i + j + 1] = 1;
			}
			if (j == 5) {
				arr3[i + j] = 2;
				arr3[i + j + 1] = 2;
			}
			if (j == 7) {
				arr3[i + j] = 4;
				arr3[i + j + 1] = 4;
			}
			if (j == 9) {
				arr3[i + j] = 5;
				arr3[i + j + 1] = 5;
			}
		}
	}
}

vector<int> solution(vector<int> answers) {
	init();
	for (int i = 0; i < answers.size(); i++) {
		if (arr1[i + 1] == answers[i]) {
			cor1++;
		}
		if (arr2[i + 1] == answers[i]) {
			cor2++;
		}
		if (arr3[i + 1] == answers[i]) {
			cor3++;
		}
	}

	big = max(big, cor1);
	big = max(big, cor2);
	big = max(big, cor3);

	if (big == cor1) {
		answer.push_back(1);
	}
	if (big == cor2) {
		answer.push_back(2);
	}
	if (big == cor3) {
		answer.push_back(3);
	}
	return answer;
}