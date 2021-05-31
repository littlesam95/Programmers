#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
int answer = 0;
vector<int> vec;

int solution(int n) {
	for (int i = 1; i <= (n / 2); i++) {
		if (n % i == 0) {
			vec.push_back(i);
		}
	}
	vec.push_back(n);
	for (int i = 0; i < vec.size(); i++) {
		answer += vec[i];
	}

	return answer;
}