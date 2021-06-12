#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;
int arr[31];

void init(int student) {
	for (int i = 0; i < 31; i++) {
		arr[i] = -1; // 없는 학생
	}
	for (int i = 1; i <= student; i++) {
		arr[i] = 1;
	}
}

int solution(int n, vector<int> lost, vector<int> reserve) {
	init(n);
	for (int i = 0; i < lost.size(); i++) {
		arr[lost[i]]--;
	}
	for (int i = 0; i < reserve.size(); i++) {
		arr[reserve[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 2) {
			if (arr[i - 1] == 0) {
				arr[i]--;
				arr[i - 1]++;;
			}
			else if (arr[i + 1] == 0) {
				arr[i]--;
				arr[i + 1]++;;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] >= 1) {
			answer++;
		}
	}

	return answer;
}