#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
#define MAX 1000000

using namespace std;
int answer = 0;
int arr[MAX + 1];

int solution(int n) {
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i <= MAX; i++) {
		arr[i] = i;
	}
	for (int i = 2; i <= sqrt(MAX); i++) {
		if (arr[i] == 0) continue;
		for (int j = (i * i); j <= MAX; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] != 0) {
			answer++;
		}
	}

	return answer;
}