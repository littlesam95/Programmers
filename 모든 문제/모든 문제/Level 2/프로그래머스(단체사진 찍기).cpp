#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

bool isRight(char c, int diff, int num) {
	if (c == '=') {
		return diff == num;
	}
	else if (c == '<') {
		return diff < num;
	}
	else if (c == '>') {
		return diff > num;
	}
}

int solution(int n, vector<string> data) {
	int answer = 0;
	string friends = "ACFJMNRT";

	do {
		bool b = true;
		for (string w : data) {
			char bf = w[0]; // 첫 번째 프렌즈
			char nf = w[2]; // 두 번째 프렌즈
			char comp = w[3]; // 등호/부등호
			int num = w[4] - '0'; // 간격
			int diff = friends.find(bf) - friends.find(nf); // 현재 순열에서 첫 번째와 두 번째 프렌즈의 위치 차이
			int dis = abs(diff) - 1; // 거리
			if (isRight(comp, dis, num)) continue; // 조건을 만족하는지 확인, 만족하면 다음 프렌즈들 확인
			b = false; // 만족하지 않는다면 break 후 다음 순열로 돌린다.
			break;
		}
		if (b) answer++; // 최종적으로 이 순열이 모든 조건을 만족하면 가짓수를 하나 올린다.
	} while (next_permutation(friends.begin(), friends.end())); // 순열을 계속 돌리면서 조건을 만족하는 지 확인한다.

	return answer;
}