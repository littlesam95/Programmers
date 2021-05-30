#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
int answer = 0;

int solution(vector<int> d, int budget) {
	sort(d.begin(), d.end());
	for (int i = 0; i < d.size(); i++) {
		if (budget - d[i] >= 0) {
			answer++;
			budget -= d[i];
		}
		else {
			break;
		}
	}

	return answer;
}