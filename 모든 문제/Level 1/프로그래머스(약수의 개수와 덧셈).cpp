#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
int arr[1001];
int answer = 0;

void init() {
	for (int i = 1; i < 1001; i++) {
		int cnt = 0;
		for (int j = 1; (j * j) <= i; j++) {
			if (i % j == 0) {
				cnt++;
				if (j * j < i) {
					cnt++;
				}
			}
		}
		arr[i] = cnt;
	}
}

int solution(int left, int right) {
	init();
	for (int i = left; i <= right; i++) {
		if (arr[i] % 2 == 0) {
			answer += i;
		}
		else if (arr[i] % 2 == 1) {
			answer -= i;
		}
	}
	return answer;
}